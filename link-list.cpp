#include <iostream>
#include "link-list.h"

using namespace std;

template <typename T>
class Node
{
private:
	T value;
	Node *next_Node;

public:
	Node(T val = NULL, Node *n = nullptr);
	T getValue() const;
	Node *getNext() const;
};

template <typename T>
Node<T>::Node(T val, Node *n) : next_Node(n), value(val)
{
}

template <typename T>
T Node<T>::getValue() const
{
	return value;
}

template <typename T>
Node<T> *Node<T>::getNext() const
{
	return this->next_Node;
}

template <typename T>
class List
{
private:
	Node<T> *list_head;

public:
	List();
	bool isEmpty();
	void insert(T data, int index);
	T getFirst();
	T getLast();
	T getElement(int index);
	T getElement(T data);
	void rmElement(int index);
	void rmElement(T data);
	void erase();
	int size();
	int count(T n);
};

template <typename T>
List<T>::List()
{
	this->list_head = nullptr;
}

template <typename T>
bool List<T>::isEmpty()
{
	return (list_head == nullptr);
}

template <typename T>
void List<T>::insert(T data, int index)
{
}

template <typename T>
T List<T>::getFirst()
{
	return list_head->getValue();
}

template <typename T>
T List<T>::getLast()
{
}

template <typename T>
T List<T>::getElement(int index)
{
}

template <typename T>
T List<T>::getElement(T data)
{
}

template <typename T>
void List<T>::rmElement(int index)
{
}

template <typename T>
void List<T>::rmElement(T data)
{
}

template <typename T>
void List<T>::erase()
{
}

template <typename T>
int List<T>::size()
{
}

template <typename T>
int List<T>::count(T data)
{
}

int main()
{
}
