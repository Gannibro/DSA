#include "../header/queue.h"
#include <iostream>
ArrayQueue::ArrayQueue(int size) : capacity(size), frontIndex(0), backIndex(-1), size(0){
    data = new int[capacity];
}

ArrayQueue::~ArrayQueue(){
    delete[] data; //deleting the constructor
}

bool ArrayQueue::isEmpty(){
    return size == 0; //returns true if size is 0
}

bool ArrayQueue::isFull() const{
    return size == capacity; //returns true if size is full
}

void ArrayQueue::enqueue(int info){
    if (isFull()){ //Checks if queue is full or not
        std::cout << "Queue is full" << std::endl;
    }
    if (backIndex == capacity - 1){
        backIndex = 0;
    }
    else{
        backIndex++;
    }
    data[backIndex] = info;
    size++;
}

int ArrayQueue::dequeue()
{
    if (isEmpty()){
        std::cout << "Queue is empty" << std::endl;
    }
    int frontInfo = data[frontIndex];
    if (frontIndex == capacity - 1){
        frontIndex = 0;
    }
    else{
        frontIndex++;
    }
    size--;
    return frontInfo;
}

int ArrayQueue::front(){
    if (isEmpty()){
        std::cout << "Queue is empty" << std::endl;
    }
    return data[frontIndex];
}

int ArrayQueue::rear(){
    if (isEmpty()){
        std::cout << "Queue is empty" << std::endl;
    }
    return data[backIndex];
}

int main(){
    ArrayQueue arrQueue(5); //creating an object
    std::cout << "Testing ArrayQueue:" << std::endl;

    if (arrQueue.isEmpty()){
        std::cout << "The queue is empty" << std::endl;
    }

    arrQueue.enqueue(1); //adds element into the queue
    arrQueue.enqueue(2);
    arrQueue.enqueue(3);
    std::cout << "Front element: " << arrQueue.front() << std::endl;
    std::cout << "Rear element: " << arrQueue.rear() << std::endl;

    std::cout << "Dequeued element: " << arrQueue.dequeue() << std::endl;
    std::cout << "Front element after dequeue: " << arrQueue.front() << std::endl;
    std::cout << "Rear element after dequeue: " << arrQueue.rear() << std::endl;

    arrQueue.enqueue(40);
    arrQueue.enqueue(50);
    arrQueue.enqueue(60);
}