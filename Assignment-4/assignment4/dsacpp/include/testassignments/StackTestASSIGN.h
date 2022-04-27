/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StackTest.h
 * Author: LTSACH
 *
 * Created on 27 August 2020, 10:00
 */

#ifndef STACKTESTASSIGN_H
#define STACKTESTASSIGN_H

#include "testassignments/commons.h"

TEST_CASE("Stack<int>: size+empty+clear") {
    Stack<int> stack;
    
    SUBCASE("With empty stack"){
        REQUIRE(stack.size() == 0);
        REQUIRE(stack.empty() == true);
        try{
            stack.clear();
            REQUIRE(stack.size() == 0);
            REQUIRE(stack.empty() == true);
        }
        catch(exception& e){ 
            REQUIRE(1==1);
        } 
    }
    
    SUBCASE("With non-empty stack"){
        int* sizes = genIntArray(nsizes, 0, max_length, true, 2021);
        for(int idx=0; idx < nsizes; idx++){
            //making stack empty
            stack.clear();
            REQUIRE( stack.size() == 0 );
            REQUIRE( stack.empty() == true );

            //pushing items
            int size = sizes[idx];
            int* items = genIntArray(size, -500, 500, true, 2021);
            for(int i=0; i < size; i++) stack.push(items[i]);

            //enforcing stack size
            REQUIRE( stack.size() == size );
            REQUIRE( stack.empty() == ((size == 0) ? true: false));
            
            //freeing mem
            delete []items;
        }
        delete []sizes;
    }
}

TEST_CASE("Stack<int>: peek + pop: WHEN stack empty"){
    Stack<int> stack;
    try{
        stack.peek();
    }
    catch(exception& e){
        REQUIRE(1==1);
    }
    try{
        stack.pop();
    }
    catch(exception& e){
        REQUIRE(1==1);
    }
}

TEST_CASE("Stack<int>: push+pop+peek") {
    Stack<int> stack;
    
    SUBCASE("push->peek+pop"){
        int* sizes = genIntArray(nsizes, 0, max_length, true, 2021);
        for(int idx=0; idx < nsizes; idx++){
            //making stack empty
            stack.clear();

            //pushing items
            int size = sizes[idx];
            int* items = genIntArray(size, -500, 500, true, 2021);
            for(int i=0; i < size; i++) stack.push(items[i]);
            
            for(int i=0; i < size; i++){
                REQUIRE(stack.size() == (size-i));
                int item = stack.peek();
                REQUIRE(item == items[size-1-i]);
                
                item = stack.pop();
                REQUIRE(item == items[size-1-i]);
                REQUIRE(stack.size() == (size-i-1));
            }
            delete []items;
        }
        delete []sizes;
    }
    
    SUBCASE("push->pop->push->peek+pop"){
        stack.clear();
        int half_length = max_length/2;
        for(int v=0; v < max_length; v++) stack.push(v);
        
        //push
        REQUIRE(stack.size() == max_length);
        
        //pop a half
        for(int v=max_length-1; v >= half_length; v--){
            int item = stack.pop();
            REQUIRE(item == v);
        }
        REQUIRE(stack.size() == half_length);
        
        //push again
        for(int v=half_length; v < max_length; v++) stack.push(v);
        
        int item;
        for(int v=max_length-1; !stack.empty(); v--, stack.pop()){
            item = stack.peek();
            REQUIRE(v == item);
        }
    }
}

TEST_CASE("Stack<int>: remove"){
    Stack<int> stack;
    
    SUBCASE("remove: top"){
        stack.clear();
        for(int v=0; v < max_length; v++) stack.push(v);
        bool found;
        for(int v=max_length-1; v >=0; v--){
            REQUIRE(stack.peek() == v);
            found = stack.remove(v);
            REQUIRE(found == true);
            REQUIRE(stack.size() == v);
        }
        REQUIRE(stack.empty() == true);
    }
    
    SUBCASE("remove: bottom"){
        stack.clear();
        for(int v=0; v < max_length; v++) stack.push(v);
        bool found;
        for(int v=0; v < max_length; v++){
            found = stack.remove(v);
            REQUIRE(found == true);
            REQUIRE(stack.size() == (max_length-v-1));
        }
        REQUIRE(stack.empty() == true);
    }
    
    SUBCASE("remove: not found"){
        stack.clear();
        for(int v=0; v < max_length; v++) stack.push(v);
        bool found;
        int items[] = {-500, -400, -300, max_length + 100, max_length + 400};
        for(int item: items){
            found = stack.remove(item);
            REQUIRE(found == false);
            REQUIRE(stack.size() == max_length);
        }
        REQUIRE(stack.empty() == false);
    }
    SUBCASE("remove: random item"){
        stack.clear();
        //push max_length item
        for(int v=0; v < max_length; v++) stack.push(v);
        
        //remove random item
        int* items = permutation(max_length, true, 2021);
        bool found;
        for(int idx =0; idx < max_length; idx++){
            int item = items[idx];
            found = stack.remove(item);
            REQUIRE(found == true);
            REQUIRE(stack.size() == max_length-1-idx);
        }
        REQUIRE(stack.empty() == true);
        
        delete []items;
    }
}

TEST_CASE("Stack<int>: contains"){
    Stack<int> stack;
    
    SUBCASE("with found items"){
        int* items = permutation(max_length, true, 2021);
        for(int idx=0; idx < max_length; idx++) stack.push(items[idx]);
        bool found;
        for(int idx=0; idx < max_length; idx++){
            found = stack.contains(items[idx]);
            REQUIRE(found == true);
        }
        delete []items;
    }
    SUBCASE("with not found items"){
        int* items = permutation(max_length, true, 2021);
        for(int idx=0; idx < max_length; idx++) stack.push(items[idx]);
        bool found;
        for(int idx=0; idx < max_length; idx++){
            found = stack.contains(items[idx] + max_length);
            REQUIRE(found == false);
        }
        delete []items;
    }
}

TEST_CASE("Stack<int>: Iteraror"){
    Stack<int> stack;
    
    SUBCASE("iterator -> equality"){
        int* items = permutation(max_length, true, 2021);
        for(int idx=0; idx < max_length; idx++) stack.push(items[idx]);
        Stack<int>::Iterator it;
        int idx;
        for(it=stack.top(), idx=max_length-1; it != stack.bottom(); it++, idx--){
            REQUIRE(*it == items[idx]);
        }
        //
        delete []items;
    }
    SUBCASE("iterator -> remove"){
        int* items = permutation(max_length, true, 2021);
        for(int idx=0; idx < max_length; idx++) stack.push(items[idx]);
        
        Stack<int>::Iterator it;
        for(int idx=0; idx < max_length; idx++){
            int item = items[idx];
            //remove item;
            it = stack.top();
            while(it != stack.bottom()){
                if(*it == item) it.remove();
                it++;
            }
            //ensure size
            REQUIRE(stack.size() == max_length - 1 - idx);
        }
        REQUIRE(stack.empty() == true);
        //
        delete []items;
    }
}

///Test polymorphism: using stack via pointer to IDeck
TEST_CASE("IDeck<int>*: stack via ptr to IDeck") {
    IDeck<int> *pdeck = new Stack<int>();
    
    //require empty
    REQUIRE(pdeck->size() == 0);
    REQUIRE(pdeck->empty() == true);
    
    //push some
    for(int v=0; v < max_length; v++) pdeck->push(v);
    REQUIRE(pdeck->size() == max_length);
    
    //clear + require empty
    pdeck->clear();
    REQUIRE(pdeck->size() == 0);
    REQUIRE(pdeck->empty() == true);
    
    //deallocate
    delete pdeck;
}

#endif /* STACKTESTASSIGN_H */

