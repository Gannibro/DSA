#include "../header/stack.h"
#include <iostream>
ArrayStack::ArrayStack(int size) : size(size), topIndex(-1)
{
    data = new int[size];
}

bool ArrayStack::isEmpty()
{
    return topIndex == -1;
}
bool ArrayStack::isFull() const
{
    return topIndex == size - 1;
}
void ArrayStack::push(int info)
{
    if (topIndex + 1 >= size)
    {
        std::cout << "Stack is empty" << std::endl;
    }
    data[++topIndex] = info;
}

int ArrayStack::pop()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    return data[topIndex--];
}

int ArrayStack::top()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    return data[topIndex];
}
int main()
{
    ArrayStack stack(5);

    std::cout << "Pushing elements onto the stack:\n";
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl;

    std::cout << "Popping elements from the stack:\n";
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;

    if (stack.isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << "Stack is not empty" << std::endl;
    }

    stack.push(40);
    std::cout << "Top element: " << stack.top() << std::endl;

    std::cout << "Popping elements from the stack:\n";
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;

    if (stack.isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << "Stack is not empty" << std::endl;
    }

    // Trying to pop from an empty stack
    stack.pop(); // This will throw an exception
    return 0;
}