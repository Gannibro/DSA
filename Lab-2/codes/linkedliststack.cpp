#include <iostream>
#include "../header/stack.h"
using namespace std;

LinkedListStack::LinkedListStack() {}

bool LinkedListStack::isEmpty(){
    if (list1.isEmpty()){  //Checks if the linkedlist is empty or not using Linked List's function
        return true;
    }
    else{
        return false;
    }
}

void LinkedListStack::push(int info){
    list1.addToHead(info); //Uses addToHead function from LinkedList to push into stack
}

int LinkedListStack::pop(){
    if (!list1.isEmpty()){
        int topInfo = list1.returnHead();
        list1.removeFromHead(); //Uses removeFromHead() function from Linked List to pop from stack
        return topInfo;
    }
    else{
        cout << "Stack is empty. Cannot pop." << endl;
        return -1; // Return an error value or handle appropriately
    }
}

int LinkedListStack::top(){
    if (!list1.isEmpty()){
        return list1.returnHead(); //Uses return head from linkedlist to show the top element of stack
    }
    else{
        cout << "Stack is empty. Cannot get top element." << endl;
        return -1; // Return an error value
    }
}

int main(){
    LinkedListStack stack;
    if (stack.isEmpty()){
        cout << "The stack is empty" << endl;
    }
    else{
        cout << "The stack is not empty" << endl;
    }
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "Top element: " << stack.top() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    cout << "Top element after pop: " << stack.top() << endl;
    if (stack.isEmpty()){
        cout << "The stack is empty" << endl;
    }
    else{
        cout << "The stack is not empty" << endl;
    }
}