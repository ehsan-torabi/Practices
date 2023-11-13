#ifndef CQUEUE_H

#define CQUEUE_H
// This was written using an array for now.
#include <stdexcept>
template <typename T>
class Cqueue
{
private:
    int size, front, rear;
    T *queue;

public:
    Cqueue(int size);
    ~Cqueue();
    bool isFull();
    bool isEmpty();
    void Enqueue(T element);
    T Dequeue();
};
template <typename T>
Cqueue<T>::Cqueue(int size) : size(size)
{
    queue = new T[size];
    front = rear = 0;
}
template <typename T>
Cqueue<T>::~Cqueue()
{
    delete[] queue;
    front = rear = 0;
}

template <typename T>
bool Cqueue<T>::isFull()
{
    return (front == (rear + 1) % size);
}

template <typename T>
bool Cqueue<T>::isEmpty()
{
    return (front == rear);
}

template <typename T>
void Cqueue<T>::Enqueue(T element)
{
    if (this->isFull())
    {
        throw std::out_of_range("Cqueue is full");
    }
    else
    {
        this->queue[rear] = element;
        rear = (rear + 1) % size;
    }
}

template <typename T>
T Cqueue<T>::Dequeue()
{
    if (this->isEmpty())
    {
        throw std::out_of_range("Cqueue is empty");
    }
    else
    {

        T elemnt = this->queue[front];
        front = (front + 1) % size;
        return elemnt;
    }
}

#endif