#include "linkedlist.h"

class Stack //Interface class of stack
{
public:
    virtual bool isEmpty() = 0;
    virtual void push(int info) = 0;
    virtual int pop() = 0;
    virtual int top() = 0;
};

class LinkedListStack : public Stack //inheriting class Stack
{
public:
    LinkedListStack();
    ~LinkedListStack() {}
    virtual bool isEmpty();
    virtual void push(int info);
    virtual int pop();
    virtual int top();

private:
    LinkedList list1; 
};

class ArrayStack : public Stack //inheriting class Stack
{
private:
    int *data;
    int topIndex;
    int size;

public:
    ArrayStack(int size);
    bool isEmpty();
    bool isFull() const;
    void push(int info);
    int pop();
    int top();
};