#include <iostream>
#define linkedlist_h

class Node{
    public:
        int info;
        Node * next;

        Node(){}
        Node(int d) : info (d), next(nullptr) {}
        Node(int d, Node * next) : info(d), next(next) {}
};

class LinkedList{
    private:
        Node* HEAD;
        Node* TAIL;
    public:
        LinkedList();
        ~LinkedList();

        void add(Node *pred, int data);
        void addToHead(int data);
        void addToTail(int data);

        bool remove(int data);
        bool removeFromHead(int &data);
        bool removeFromTail(int &data);

        bool isEmpty();
        void head(int &data);
        void print(char separator);
};