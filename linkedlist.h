#include <iostream>
#define linkedlist_h

class Node{
    public:
        int info;
        Node * next;

        Node(){}
        Node(int d) : info (d), next(NULL) {}
        Node(int d, Node * next) : info(d), next(next) {}
}