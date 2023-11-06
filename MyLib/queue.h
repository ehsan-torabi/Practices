#ifndef QUEUE_H

#define QUEUE_H
template <typename T>
class Queue
{
private:
    int size, front, rear;
    queue = new T[size];

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
    return (rear == size-1)

    
}

template <typename T>
bool Queue<T>::isEmpty()
{
    return (front == 0)

    
}

#endif