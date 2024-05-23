#include<iostream>
#include"../header/linkedlist.h"
using namespace std;

int LinkedList::returnHead(){
    if(HEAD!=NULL){
        return HEAD->info;
    }
    return -1;
}

int LinkedList::returnTail(){
    if(TAIL!=NULL){
        return TAIL->info;
    }
    return -1;
}

void LinkedList::printlist()//display node data 
        {
            Node * newNode = HEAD;
            while(newNode!=NULL){ //traversal 
                 cout<<newNode->info<<endl; //printing the required info of the node.
                 newNode = newNode->next;
            }
        }
bool LinkedList::isEmpty(){ //checks if the Node is empty
    if (HEAD==NULL){
        return true; //returns true if it is empty
    }
    else{
        return false;//returns false if it is not empty
    }
}

void LinkedList::addToHead(int info){ //adding node from Head
    Node* newNode = new Node(info);
    newNode->info=info; 
    newNode->next = HEAD;
    HEAD = newNode;
    if(TAIL==NULL){
        TAIL = newNode;
    }
}

void LinkedList::addToTail(int info){ //adding node from Tail
    Node *newNode = new Node(info);
    if(TAIL==NULL){
        HEAD = newNode;
        newNode->info = info;
        newNode->next = NULL;
        TAIL = newNode;
    }
    else{
        newNode->info = info;
        newNode->next = NULL;
        TAIL->next = newNode;
        TAIL = newNode;
    }
}
void LinkedList::traverse(){ //traversing the given linked list
            Node* newNode = HEAD;
            while (newNode!=NULL)
            {
                cout<<newNode->info<<endl;
                newNode=newNode->next;
            }
}
void LinkedList::addAfter(int predecessorInfo, int newData) {
    //check if the list is empty
    if (isEmpty()) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* predecessor = nullptr;
    //search for the predecessor node
    if (!retrieve(predecessorInfo, &predecessor)) {
        std::cout << "Predecessor node not found." << std::endl;
        return;
    }

    //create a new node
    Node* newNode = new Node(newData);

    //update the pointers to add the new node after the predecessor
    newNode->next = predecessor->next;
    predecessor->next = newNode;

    //if the predecessor is the tail, update the tail pointer
    if (predecessor == TAIL)
        TAIL = newNode;
}


void LinkedList::removeFromHead(){ //removing node from head
    Node* newNode = HEAD;
    HEAD = HEAD->next;
    delete newNode;
}

void LinkedList::removeFromTail(){ //remove from TAIL
    if(!isEmpty()){
        Node* newNode = TAIL; //creating a node pointer pointing to the TAIL of the linked list
        if(HEAD==TAIL){
             HEAD=TAIL=NULL;
        }
        else{
            Node *pred = HEAD; //creating a predecessor node pointer pointing to the HEAD of the linked list

            while(pred->next!=TAIL){  
            pred = pred->next;
            }
        TAIL = pred;
        TAIL->next = NULL;
        }
         delete newNode; 
    }
    else cout<<"Empty"<<endl; 
}

void LinkedList::remove(int info){ //function to remove the desired data from the linked list
    if(!isEmpty()){ 
        if(HEAD->info == info){
            removeFromHead(); //calling the removeFromHead function to remove the info if found in head of the linked list
        }
        else if(TAIL->info == info){ //calling the removeFromTail function to remove the info if found in tail of the linked list
            removeFromTail();
        }
        else{
            Node* newNode = HEAD->next; //creating a newNode pointer which points to the second node of the list
            Node* pred = HEAD; //creating a predecessor pointer pointing to the head of the list
            while(pred->next!=NULL){ 
                if(newNode->info == info)break;
                else{
                    pred = pred->next;
                    newNode= newNode->next;
                }
            }
            if (newNode!=NULL){
                pred->next = newNode->next;
                delete newNode;
            }
            else{
                TAIL = pred;
                delete newNode;
            }
            
        }
    }
}

void LinkedList::search(int info){ //searching for the required data and returns true if it is found 
    Node* newNode = HEAD;
    bool found = false; //indicate whether the info is found
    if(!isEmpty()){
        while(newNode!=NULL){
            if(newNode->info == info){
                cout<<"Info found"<<endl;
                found = true; //updating, if the info is found
                break; //breaking the loop
            }
            newNode = newNode->next;
        } 
        if(!found){ //if the required info is not found
            cout<<"Info not found"<<endl;
        }
    }
}

bool LinkedList::retrieve(int data, Node** outputPtr) {
    Node* p = HEAD; //initialize pointer p to traverse the list starting from HEAD

    while (p != nullptr && p->info != data) { //traversing until the required info is found
        p = p->next;
    }

    if (p == nullptr) { //if p is nullptr, it means the data was not found in the list
        *outputPtr = nullptr; //setting outputPtr to nullptr
        return false; //returns false if not found
    } else {
        *outputPtr = p; // Set outputPtr to point to the node containing the data
        return true; //returns true if found
    }
}

/*int main(){
    LinkedList list1; //creating an object list1 of the class Node i.e creating a linked list
    if(list1.isEmpty()){
        cout<<"The list is empty"<<endl;
    }else{
        cout<<"The list is not empty"<<endl;
    }
    list1.addToHead(1); //adding 1 to the head
    list1.printlist();
    list1.addToTail(2); //adding 2 to the tail
    list1.addToTail(4); //adding 4 to the tail
    list1.traverse();
    list1.addAfter(3,5);
    cout<<"After adding 5"<<endl;
    list1.printlist();
    list1.search(5); //searcing for the info 5
    list1.search(1); //searching for the info 1
    list1.remove(3);
    cout<<"After removing 3"<<endl;
    list1.printlist();
    list1.removeFromHead();
    cout<<"After removing from head"<<endl;
    list1.printlist();
    list1.removeFromTail();
    cout<<"After removing from tail"<<endl;
    list1.printlist();
    list1.search(5); //searcing for the info 5
    list1.search(2); //searching for the info 2
    Node* outputPtr; // Pointer to store the address of the node containing the data
    bool found = list1.retrieve(3, &outputPtr);//call the retrieve function and search for 3
    // Checking if the data was found
    if (found) {
        cout << "Data found: " << outputPtr->info << endl; //printing the required info if found
    } else {
        cout << "Data not found" << endl;
    }
}
*/