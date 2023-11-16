#include <iostream>
#include "link-list.h"

using namespace std;

// Node class definition
template <typename T>
class Node
{
private:
	T value;			// Value of the node
	Node<T> *next_Node; // Pointer to the next node

public:
	// Constructor
	Node(T val = NULL, Node<T> *n = nullptr);

	// Getter for value
	T getValue() const;

	// Getter for next node
	Node<T> *getNext() const;

	void setNext(Node<T> *next);
};

// Node class implementation
template <typename T>
Node<T>::Node(T val, Node<T> *n) : next_Node(n), value(val)
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
	return next_Node;
}

template <typename T>
void Node<T>::setNext(Node<T> *next)
{
	next_Node = next;
}

// List class definition
template <typename T>
class List
{
private:
	Node<T> *list_head; // Head of the list
	Node<T> *list_tail; // Tail of the list

public:
	// Constructor
	List();

	// Check if list is empty
	bool isEmpty();

	// Insert data at specific index
	void insert(T data, int index);

	// Insert data at the end
	void insert(T data);

	// Get first element
	Node<T> *getFirst();

	// Get last element
	Node<T> *getLast();

	// Get element at specific index
	T getValue(int index);

	// Get element with specific value
	Node<T> *getElement(T data);

	// Remove element at specific index
	void rmElement(int index);

	// Remove element with specific value
	void rmElement(T data);

	// Erase the list
	void erase();

	// Get size of the list
	int size();

	// Count occurrences of a value
	int count(T n);
};

// List class implementation
template <typename T>
List<T>::List() : list_head(nullptr), list_tail(nullptr)
{
}

template <typename T>
bool List<T>::isEmpty()
{
	return (list_head == nullptr);
}

template <typename T>
void List<T>::insert(T data, int index)
{
	// Implementation goes here
}

// Function to insert a new node into the list
template <typename T>
void List<T>::insert(T data)
{
	// Create a new node with the given data
	Node<T> *newNode = new Node<T>(data);

	// If the list is empty, set both the head and tail to the new node
	if (isEmpty())
	{
		list_head = newNode;
		list_tail = newNode;
	}
	else
	{
		// If the list is not empty, append the new node to the end of the list
		list_tail->setNext(newNode);
		list_tail = newNode;
	}
}

template <typename T>
Node<T> *List<T>::getFirst()
{
	return list_head;
}

template <typename T>
Node<T> *List<T>::getLast()
{
	return list_tail;
}

template <typename T>
T List<T>::getValue(int index)
{
	if (!isEmpty() || index < 0)
	{
		int i = -1;
		for (Node<T> *n = list_head; n != nullptr; n = n->getNext())
		{
			i++;
			if (i == index)
			{
				return n->getValue();
			}
		}

		throw invalid_argument("Not found element by this index");
	}
	else
	{
		throw out_of_range("List is empty !");
	}
}

template <typename T>
Node<T> *List<T>::getElement(T data)
{
	if (!isEmpty())
	{
		for (Node<T> *n = list_head; n != nullptr; n = n->getNext())
		{
			if (n->getValue() == data)
			{
				return n->getValue();
			}
		}

		throw invalid_argument("Not found element by this value");
	}
	else
	{
		throw out_of_range("List is empty !");
	}
}

template <typename T>
void List<T>::rmElement(int index)
{
	// Implementation goes here
}

template <typename T>
void List<T>::rmElement(T data)
{
	// Implementation goes here
}

template <typename T>
void List<T>::erase()
{
	if (isEmpty())
	{
		throw logic_error("List is empty");
	}
	else
	{

	}
}

template <typename T>
int List<T>::size()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		int i = 0;
		for (Node<T> *n = list_head; n != nullptr; n = n->getNext())
		{
			i++;
		}
		return i;
	}
}

template <typename T>
int List<T>::count(T data)
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		int i = 0;
		for (Node<T> *n = list_head; n != nullptr; n = n->getNext())
		{
			if (n->getValue() == data)
			{
				i++;
			}
		}
		return i;
	}
}

// Main function
int main()
{
	List<float> list;	 // Create a list of floats
	list.insert(12);	 // Insert 12 into the list
	list.insert(13);	 // Insert 13 into the list
	list.insert(13);	 // Insert another 13 into the list
	list.erase();
	cout << list.size(); // Print the size of the list
}
