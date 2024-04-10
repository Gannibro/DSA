#include <iostream>
#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList(){
    this -> HEAD = NULL;
    this -> TAIL = NULL;
}

bool LinkedList::isEmpty(){
    return HEAD == NULL;
}

void LinkedList::addToHead(int data){
    Node * newNode = new Node(data, HEAD);
    if (this -> isEmpty()){
        TAIL = newNode;
    }
    HEAD = newNode;
}

void LinkedList::print(char separator){
    cout << "Contents: " << endl;
    for (Node* t = HEAD; t != NULL; t = t->next){
        cout << t->info << separator;
    }
}