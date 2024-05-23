#include "../header/queue.h"
#include<iostream>
bool LinkedListQueue::isEmpty() { //CChecks if the Queue is empty or not using LinkedList function
    return list.isEmpty();
}

void LinkedListQueue::enqueue(int info) { //Uses addToTail function from linked list
    list.addToTail(info); 
}

int LinkedListQueue::dequeue() {
    if (isEmpty()) {
         std::cout << "Queue is empty" << std::endl;
    }
    int frontInfo = list.returnHead();
    list.removeFromHead();//Uses removeFromHead() function from Linked List to dequeue
    return frontInfo;
}

int LinkedListQueue::front() {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
    }
    return list.returnHead(); //Uses returnHead from linked list
}
int LinkedListQueue::rear() {
    if (isEmpty()) {
        std::cout << "Queue is empty" << std::endl;
    }
    return list.returnTail(); //uses returnTail function from Linked List
}
int main(){
       LinkedListQueue llQueue;
        std::cout << "Testing LinkedListQueue:" << std::endl;

        if (llQueue.isEmpty()) {
            std::cout << "The queue is empty" << std::endl;
        }

        llQueue.enqueue(1);
        llQueue.enqueue(2);
        llQueue.enqueue(3);
        std::cout << "Front element: " << llQueue.front() << std::endl; 
        std::cout << "Rear element: " << llQueue.rear() << std::endl;   

        std::cout << "Dequeued element: " << llQueue.dequeue() << std::endl; 
        std::cout << "Front element after dequeue: " << llQueue.front() << std::endl; 
        std::cout << "Rear element after dequeue: " << llQueue.rear() << std::endl;   


}