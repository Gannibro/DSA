#include "linkedlist.h"
class Queue //Interface class of Queue
{
public:
    virtual bool isEmpty() = 0;
    virtual void enqueue(int info) = 0;
    virtual int dequeue() = 0;
    virtual int front() = 0;
    virtual int rear() = 0;
    virtual ~Queue() = default;
};
class LinkedListQueue : public Queue //class LinkedListQueue inherits interface class Queue
{
public:
    LinkedListQueue() = default;
    ~LinkedListQueue() override = default;
    bool isEmpty() override;
    void enqueue(int info) override;
    int dequeue() override;
    int front() override;
    int rear();

private:
    LinkedList list;
};

class ArrayQueue : public Queue//class ArrayQueue inherits interface class Queue
{
private:
    int *data;
    int frontIndex; //keeps track of front index
    int backIndex;//Keeps track of rear index
    int capacity;
    int size;

public:
    ArrayQueue(int size);
    ~ArrayQueue();
    bool isEmpty() override;
    bool isFull() const;
    void enqueue(int info) override;
    int dequeue() override;
    int front() override;
    int rear() override;
};