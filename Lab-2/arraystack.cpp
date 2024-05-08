#include <iostream>
#include "arraystack.h"

using namespace std;

ArrayStack::ArrayStack(int size) : maxStackSize(size), topIndex(-1), data(new int[size]) {}

bool ArrayStack::isEmpty() const{
    return topIndex < 0;
}

bool ArrayStack::isFull() const{
    return topIndex == maxStackSize - 1;
}

void ArrayStack::push(const int element){
    if(isFull()){
        topIndex++;
        data[topIndex] = element;
    }
    else{
        cout << "Stack Overflow" << endl;
    }
}

bool ArrayStack::pop(int &element){
    if(!isEmpty()){
        topIndex--;
        return data[topIndex+1];
    }
    else{
        cout << "Stack is Empty." << endl;
    }
}

bool ArrayStack::top(int &element) const{
    if(!isEmpty()){
        return data[topIndex];
    }
    else{
        cout << "Stack is Empty." << endl;
        return -1;
    }
}


