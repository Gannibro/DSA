#include<iostream>
#include "../header/linkedlist.h"
using namespace std;
int main(){
    LinkedList list1; //Creating an object list1 of the class Node i.e creating a linked list
    if(list1.isEmpty()){
        cout<<"The list is empty"<<endl;
    }else{
        cout<<"The list is not empty"<<endl;
    }
    list1.addToHead(2); //adding 2 to the head
    list1.printlist();
    list1.addToTail(3); //adding 3 to the tail
    list1.addToTail(4); //adding 4 to the tail
    list1.traverse();
    list1.addAfter(3,5);
    cout<<"After adding 5"<<endl;
    list1.printlist();
    list1.search(5); //searcing for the info 5
    list1.search(1); //searching for the info 2
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
    bool found = list1.retrieve(3, &outputPtr); // Call the retrieve function and search for 3
    // Checking if the data was found
    if (found) {
        cout << "Data found: " << outputPtr->info << endl; //printing the required info if found
    } else {
        cout << "Data not found" << endl;
    }
}