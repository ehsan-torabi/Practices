#ifndef STACK_H
#define STACK_H

#include <stdexcept>

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
        top = -1;
    }
    bool push(T item);
    T pop();
    bool isEmpty();
    bool isFull();
    T peek();
};

// Template function definitions
template <typename T>
bool Stack<T>::push(T item) {
    if (isFull()) {
        return false;
    }
    stackArr[++top] = item;
    return true;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack underflow");
    }
    return stackArr[top--];
}

template <typename T>
bool Stack<T>::isEmpty() {
    return (top == -1);
}

template <typename T>
bool Stack<T>::isFull() {
    return (top == size - 1);
}

template <typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Stack underflow");
    }
    return stackArr[top];
}

#endif
