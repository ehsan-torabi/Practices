#ifndef QUEUE_H

#define QUEUE_H

#include <stdexcept>

template <typename T>
class Queue
{
private:
    int size, front, rear;
    T *queue;
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void Enqueue(T element);
    T Dequeue();
};
template <typename T>
Queue<T>::Queue(int size) : size(size)
{
    queue = new T[size];
    front = rear = 0;
}
template <typename T>
Queue<T>::~Queue()
{
    delete[] queue;
    front = rear = 0;
}

template <typename T>
bool Queue<T>::isFull()
{
    return (rear == size);
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return (front == rear);
}

template <typename T>
void Queue<T>::Enqueue(T element)
{
    if (this->isFull())
    {
        throw std::out_of_range("Queue is full");
    }
    else
    {
        this->queue[rear] = element;
        rear++;
    }
}

template <typename T>
T Queue<T>::Dequeue()
{
    if (this->isEmpty())
    {
        throw std::out_of_range("Queue is empty");
    }
    else
    {
        return this->queue[front++];
    }
}

#endif