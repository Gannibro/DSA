#include "stack.h"
class ArrayStack : public Stack{
    private:
        int *data;
        int topIndex;
        int maxStackSize;
    public:
        ArrayStack(int maxStackSize);
        ~ArrayStack(){
            delete[] data;
        }
        bool isEmpty() const;
        bool isFull() const;
        void push(const int element);
        bool pop(int &element);
        bool top(int &element) const;
};
