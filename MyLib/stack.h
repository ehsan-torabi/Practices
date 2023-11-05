#ifndef STACK_H

#define STACK_H

#include <iostream>

template <typename T>
class Stack
{
private:
    int size;
    int top;
    T *stackArr;

public:
    Stack(int stackSize) : size(stackSize)
    {
        stackArr = new T[size];
        top = -1;
    }
    ~Stack()
    {
        delete[] stackArr;
    }
    bool push(T item);
    T pop();
    bool isEmpty();
    bool isFull();
    T peek();
};

#endif