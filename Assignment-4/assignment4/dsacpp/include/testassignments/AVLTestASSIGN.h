/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVLTestASSIGN.h
 * Author: ltsach
 *
 * Created on July 1, 2021, 11:37 AM
 */

#ifndef AVLTESTASSIGN_H
#define AVLTESTASSIGN_H

#include "testassignments/commons.h"

void avl_fill(AVL<int, int*>& tree, vector<string>& items){
    for(auto dit=items.begin(); dit != items.end(); dit++){
        string item = trimstring(*dit);
        if(item == "None") break;
        stringstream stream(item);
        int iitem; stream >> iitem;
        tree.add(iitem, new int(iitem));
    }
}
void avl_removeitem(AVL<int, int*>& tree, vector<string>& items){
    for(auto dit=items.begin(); dit != items.end(); dit++){
        string item = trimstring(*dit);
        if(item == "None") break;
        
        stringstream stream(item);
        int iitem; stream >> iitem;
        
        bool success = false;
        int* v = tree.remove(iitem, &success);
        REQUIRE(success == true);
        delete v;
    }
}
void avl_additem(AVL<int, int*>& tree, vector<string>& items){
    for(auto dit=items.begin(); dit != items.end(); dit++){
        string item = trimstring(*dit);
        if(item == "None") break;
        
        stringstream stream(item);
        int iitem; stream >> iitem;
        
        tree.add(iitem, new int(iitem));
    }
}

bool equal(DLinkedList<int*> list, vector<string>& expected){
    REQUIRE(list.size() <= expected.size());
    
    bool same = true;
    DLinkedList<int*>::Iterator lit;
    vector<string>::iterator eit;
    for(lit = list.begin(), eit = expected.begin(); lit != list.end(); lit++, eit++){
        int item = **lit;
        stringstream stream(*eit);
        int exp; stream >> exp;
        if(exp != item){
            same = false;
            break;
        }
    }
    return same;
}
bool equal(DLinkedList<string> list, vector<string>& expected){
    REQUIRE(list.size() <= expected.size());
    
    bool same = true;
    DLinkedList<string>::Iterator lit;
    vector<string>::iterator eit;
    for(lit = list.begin(), eit = expected.begin(); lit != list.end(); lit++, eit++){
        string exp = trimstring(*eit);
        string item = trimstring(*lit);
        if(exp != item){
            same = false;
            break;
        }
    }
    return same;
}

int countValid(vector<string>& items){
    int count = 0;
    for(auto dit=items.begin(); dit != items.end(); dit++){
        string item = trimstring(*dit);
        if(item == "None") break;
        count += 1;
    }
    return count;
}


TEST_CASE( "AVL<int, int*>: contruction => size/empty" ) {
    DataFrame master("dat/test_avl_const.csv");
    vector<string> filenames = master["filename"];
    for(auto it=filenames.begin(); it != filenames.end(); it++){
        string filename = *it;
        
        AVL<int, int*> tree;
        DataFrame df(filename);
        
        avl_fill(tree, df["item"]);
        int nvalid = countValid(df["item"]);
        REQUIRE(tree.size() == nvalid);
        REQUIRE(tree.empty() == (nvalid == 0));
    }
}

TEST_CASE( "AVL<int, int*>: contruction with polymorphism" ) {
    DataFrame master("dat/test_avl_const.csv");
    vector<string> filenames = master["filename"];
    for(auto it=filenames.begin(); it != filenames.end(); it++){
        string filename = *it;
        
        IBST<int, int*>* tree = new AVL<int, int*>();
        DataFrame df(filename);
        
        avl_fill(*dynamic_cast<AVL<int, int*>*>(tree), df["item"]);
        int nvalid = countValid(df["item"]);
        REQUIRE(tree->size() == nvalid);
        REQUIRE(tree->empty() == (nvalid == 0));
        delete tree;
    }
}


TEST_CASE( "AVL<int, int*>: contruction => height" ) {
    DataFrame master("dat/test_avl_const.csv");
    vector<string> filenames = master["filename"];
    for(auto it=filenames.begin(); it != filenames.end(); it++){
        string filename = *it;
        
        AVL<int, int*> tree;
        DataFrame df(filename);
        
        avl_fill(tree, df["item"]);
        int N = countValid(df["item"]);
        if(N > 0) REQUIRE(tree.height() <= int(1.44*log2(N)));
    }
}

TEST_CASE( "AVL<int, int*>: contruction => traversals: same" ) {
    DataFrame master("dat/test_avl_const.csv");
    vector<string> filenames = master["filename"];
    for(auto it=filenames.begin(); it != filenames.end(); it++){
        string filename = *it;
        
        AVL<int, int*> tree;
        DataFrame df(filename);
        
        avl_fill(tree, df["item"]);
        REQUIRE(equal(tree.ascendingList(), df["ascending"]) == true);
        REQUIRE(equal(tree.descendingList(), df["descending"]) == true);
        REQUIRE(equal(tree.dfs(), df["dfs"]) == true);
        REQUIRE(equal(tree.bfs(), df["bfs"]) == true);
        REQUIRE(equal(tree.nlr(), df["nlr"]) == true);
        REQUIRE(equal(tree.lrn(), df["lrn"]) == true);
        REQUIRE(equal(tree.lnr(), df["lnr"]) == true);
    }
}
TEST_CASE( "AVL<int, int*>: contruction => bfactor" ) {
    DataFrame master("dat/test_avl_const.csv");
    vector<string> filenames = master["filename"];
    for(auto it=filenames.begin(); it != filenames.end(); it++){
        string filename = *it;
        
        AVL<int, int*> tree;
        DataFrame df(filename);
        
        avl_fill(tree, df["item"]);
        REQUIRE(equal(tree.bfactor(), df["bfactor"]) == true);
    }
}

TEST_CASE( "AVL<int, int*>: add + remove => traversals: same" ) {
    DataFrame master("dat/test_avl_const.csv");
    vector<string> filenames = master["filename"];
    for(auto it=filenames.begin(); it != filenames.end(); it++){
        string filename = *it;
        
        AVL<int, int*> tree;
        DataFrame df(filename);
        
        avl_fill(tree, df["add"]);
        REQUIRE(equal(tree.dfs(), df["dfs0"]) == true);
        REQUIRE(equal(tree.bfs(), df["bfs0"]) == true);
        REQUIRE(equal(tree.bfactor(), df["bfactor0"]) == true);
    }
}

TEST_CASE( "AVL<int, int*>: add + remove => traversals: same" ) {
    DataFrame master("dat/test_avl_const.csv");
    vector<string> filenames = master["filename"];
    for(auto it=filenames.begin(); it != filenames.end(); it++){
        string filename = *it;
        
        AVL<int, int*> tree;
        DataFrame df(filename);
        
        avl_fill(tree, df["add"]);
        avl_removeitem(tree, df["remove-then-add0"]);
        REQUIRE(equal(tree.dfs(), df["dfs1"]) == true);
        REQUIRE(equal(tree.bfs(), df["bfs1"]) == true);
        REQUIRE(equal(tree.bfactor(), df["bfactor1"]) == true);
    }
}

TEST_CASE( "AVL<int, int*>: add + remove => traversals: same" ) {
    DataFrame master("dat/test_avl_const.csv");
    vector<string> filenames = master["filename"];
    for(auto it=filenames.begin(); it != filenames.end(); it++){
        string filename = *it;
        
        AVL<int, int*> tree;
        DataFrame df(filename);
        
        avl_fill(tree, df["add"]);
        avl_removeitem(tree, df["remove-then-add0"]);
        avl_additem(tree, df["remove-then-add0"]);
        REQUIRE(equal(tree.dfs(), df["dfs2"]) == true);
        REQUIRE(equal(tree.bfs(), df["bfs2"]) == true);
        REQUIRE(equal(tree.bfactor(), df["bfactor2"]) == true);
    }
}

TEST_CASE( "AVL<int, int*>: add + remove => traversals: same" ) {
    DataFrame master("dat/test_avl_const.csv");
    vector<string> filenames = master["filename"];
    for(auto it=filenames.begin(); it != filenames.end(); it++){
        string filename = *it;
        
        AVL<int, int*> tree;
        DataFrame df(filename);
        
        avl_fill(tree, df["add"]);
        avl_removeitem(tree, df["remove-then-add0"]);
        avl_additem(tree, df["remove-then-add0"]);
        avl_removeitem(tree, df["remove-then-add1"]);
        REQUIRE(equal(tree.dfs(), df["dfs3"]) == true);
        REQUIRE(equal(tree.bfs(), df["bfs3"]) == true);
        REQUIRE(equal(tree.bfactor(), df["bfactor3"]) == true);
    }
}

TEST_CASE( "AVL<int, int*>: add + remove => traversals: same" ) {
    DataFrame master("dat/test_avl_const.csv");
    vector<string> filenames = master["filename"];
    for(auto it=filenames.begin(); it != filenames.end(); it++){
        string filename = *it;
        
        AVL<int, int*> tree;
        DataFrame df(filename);
        
        avl_fill(tree, df["add"]);
        avl_removeitem(tree, df["remove-then-add0"]);
        avl_additem(tree, df["remove-then-add0"]);
        avl_removeitem(tree, df["remove-then-add1"]);
        avl_additem(tree, df["remove-then-add1"]);
        REQUIRE(equal(tree.dfs(), df["dfs4"]) == true);
        REQUIRE(equal(tree.bfs(), df["bfs4"]) == true);
        REQUIRE(equal(tree.bfactor(), df["bfactor4"]) == true);
    }
}

#endif /* AVLTESTASSIGN_H */

