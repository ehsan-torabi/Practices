#include <stack.h>


template <typename T>
bool Stack<T>::push(T item)
{
	if (this->isFull())
	{
		throw out_of_range("Stack overflow");
	}
	else
	{
		stackArr[++top] = item;
		return true;
	}
}

template <typename T>
T Stack<T>::pop()
{
	if (this->isEmpty())
	{
		throw out_of_range("Stack underflow");
	}
	else
	{
		return this->stackArr[top--];
	}
}

template <typename T>
bool Stack<T>::isEmpty()
{
	return (top < 0);
}

template <typename T>
bool Stack<T>::isFull()
{
	return (top >= size);
}

template <typename T>
T Stack<T>::peek()
{
	if (this->isEmpty())
	{
		throw out_of_range("Stack underflow");
	}
	else
	{
		return stackArr[top];
	}
}