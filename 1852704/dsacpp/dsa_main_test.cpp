// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "doctest.h"

// #include "test/XArrayListTest.h"
// #include "test/XArrayListSETest.h"


// //UNCOMMENT the following WHENEVER completing the related data structures

// #include "test/SLinkedListTest.h"
// #include "test/SLinkedListSETest.h"
// #include "test/DLinkedListTest.h"
// #include "test/DLinkedListSETest.h"
// #include "test/BSTTest.h"
// #include "test/StackTest.h"
// #include "test/QueueTest.h"
// #include "test/HeapTest.h"
// #include "test/PriorityQueueTest.h"
// #include "test/XHashMapTest.h"
// #include "test/SortTest.h"
// #include "test/GraphTest.h"
// #include "test/AVLTest.h"

/*
#include <iostream>
#include <sstream>
#include <iomanip>
#include "graph/DGraphModel.h"
#include "graph/UGraphModel.h"
#include "graph/AbstractGraph.h"
#include "graph/TopoSorter.h"
#include "util/ArrayLib.h"
#include "util/FuncLib.h"
#include "util/FileIOLib.h"
#include "geom/Point3D.h"
#include "geom/Vector3D.h"
using namespace std;

bool vertexEQ(char& lhs, char& rhs){
    return lhs == rhs;
}

string vertex2str(char& item){
   stringstream os;
    os << item;
    return os.str();
}
int hashcode(char& key, int size){
    return int(key)%size;
}
DGraphModel<char>* reverse_graph(DGraphModel<char>& graph);
void quiz(){
    DGraphModel<char> graph(&vertexEQ, &vertex2str);
    char vertices[] = {'B', 'E', 'A', 'M', 'J'};
    //for(char v : vertices) graph.add(v);
    for(int i=0; i < 5; i++){
        graph.add(vertices[i]);
    }
    graph.connect('B', 'A');
    graph.connect('E', 'A');
    graph.connect('A', 'M');
    graph.connect('A', 'J');
    graph.println();
    //graph.println();
    TopoSorter<char> sorter(&graph, &hashcode);
    DLinkedList<char> dfs = sorter.sort(TopoSorter<char>::DFS);
    DLinkedList<char>::Iterator it;
    for(it = dfs.begin(); it != dfs.end(); it++){
        cout << *it << setw(8) << graph.inDegree(*it) << setw(8) << graph.outDegree(*it) << endl;
    }
    DGraphModel<char>* new_graph = reverse_graph(graph);
    new_graph->println();
    
}
DGraphModel<char>* reverse_graph(DGraphModel<char>& graph){
    DGraphModel<char>* new_graph = new DGraphModel<char>(&vertexEQ, &vertex2str);
    DLinkedList<char> vertices = graph.vertices(); // use vertices() to return list of vertice
    DLinkedList<char>::Iterator it;
    for(it = vertices.begin(); it != vertices.end(); it++){
        new_graph->add(*it);
    }

    for(it = vertices.begin(); it != vertices.end(); it++){
        DLinkedList<char> list = graph.getOutwardEdges(*it);
        DLinkedList<char>::Iterator it2;
        for(it2 = list.begin(); it2 != list.end(); it2++){
            new_graph->connect(*it2, *it);
        }
    }
    return new_graph;
}
float func1(float x){
    return 1;
}
float func2(float x){
    return 2;
}
float func3(float x){
    return 3;
}

float get_value(string funct, float x){
    XHashMap<string, float(*)(float)> map(&hash_murmur);
    map.put("func1", &func1);
    map.put("func2", &func2);
    map.put("func3", &func3);
    float (*func) (float);
    func = map.get(funct);
    return func(x);
}
int main(int argc, char** argv){
    //quiz();
    string arr[] = {"func1", "func2", "func3"};
    for(int i=0; i < 3; i++){
        float y = get_value(arr[i], 0.5);
        cout<< y << " ";
    }
    
    return 0;
}

//Schain without dummy node
template<class T>
struct SNode{
    T data;
    SNode<T>* next;
    SNode(T data, SNode<T>* next = NULL){
        this->data = data;
        this->data = next;
    }
};


template<class T>
SNode<T>* create_schain(T* ptr, int size){
    SNode<T>* head = NULL;
    //YOUR CODE HERE
    for(int idx=size -1; idx >= 0; idx--){
        head = new SNode<T>(ptr[idx], head);
    }
    return head;
}
 
 template<class T>
 void delete_schain(SNode<T>*& head){
    //YOUR CODE HERE  
    SNode<T>* cursor;
    SNode<T>* backup;
    for(cursor=head; cursor != NULL; cursor=backup){
        backup = cursor->next;
        delete cursor;
    }
    head = NULL;
 }

 template<class T>
 string to_string(SNode<T>* const head){
    //YOUR CODE HERE  
    stringstream itemos;
    SNode<T>* ptr = head;
    while(ptr != NULL){
        itemos << ptr->data << ", ";
        ptr = ptr->next;
    }
    string itemstr = itemos.str();
    itemstr = itemstr.substr(0, itemstr.rfind(','));
    return "[" + itemstr + "]"; 
 }



void gen_student_data(){
    //YOUR CODE HERE
    int len_sname = sname.length();
    int len_scode = scode.length();
    int index = 0;
    for(int i = len_sname-5; i < len_sname;i++){
      student_data[index] = (int)sname[i];
      index++;
    }
    for(int i = len_scode-5; i < len_scode;i++){
      student_data[index] = (int)scode[i];
      index++;
    }
}
*/