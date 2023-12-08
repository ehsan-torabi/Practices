#include <iostream>

using namespace std;

										//--------------------- Node class definition ---------------------
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

										//--------------------- Node class implementation ---------------------
template <typename T>
Node<T>::Node(T val, Node<T> *n) : next_Node(n), value(val)
{
	// Empty constructor
}

template <typename T>
T Node<T>::getValue() const
{
	return value; // Return value of this node
}

template <typename T>
Node<T> *Node<T>::getNext() const
{
	return next_Node; // Return next node address of this node
}

template <typename T>
void Node<T>::setNext(Node<T> *next)
{
	next_Node = next; // Set the address of the next node for this node to the received next parameter
}

										//--------------------- List class definition ---------------------
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
	void append(T data);

	// Get first element
	Node<T> *getFirst();

	// Get last element
	Node<T> *getLast();

	// Get element at specific index
	T getValue(int index);

	// Get element with specific value
	Node<T> *getElement(T data);

	// Remove element at specific index
	void rmIndex(int index);

	// Remove element with specific value
	void rmElement(T data);

	// Erase the list
	void erase();

	// Get size of the list
	int size();

	// Count occurrences of a value
	int count(T n);
};

										//--------------------- List class implementation ---------------------
template <typename T>
List<T>::List() : list_head(nullptr), list_tail(nullptr)
{
	// Empty constructor
}

template <typename T>
bool List<T>::isEmpty()
{
	return (list_head == nullptr); // Return true if list_head address equal to one node else return false
}

template <typename T>
void List<T>::insert(T data, int index)
{
	// Check negative index and if true throw a exception
	if (index < 0)
	{
		throw invalid_argument("An element cannot be inserted at a negative index.");
	}

	// If the index is out of range or the list is empty, append the data to the end of the list
	if (isEmpty() || index >= size())
	{
		append(data);
		return;
	}

	// If the index is 0, insert the data at the head of the list
	if (index == 0)
	{
		list_head = new Node<T>(data, list_head);
		return;
	}

	// Find the node at the given index and its previous node
	Node<T> *prev = nullptr;
	Node<T> *current = list_head;
	for (int i = 0; i < index; i++)
	{
		prev = current;
		current = current->getNext();
	}

	// Insert the new node between the previous node and the current node
	Node<T> *newNode = new Node<T>(data, current);
	prev->setNext(newNode);

	// If the new node is inserted at the end of the list, update the tail of the list
	if (current == nullptr)
	{
		list_tail = newNode;
	}
}

// Function to insert a new node into the last of list
template <typename T>
void List<T>::append(T data)
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
void List<T>::rmIndex(int index)
{
	// If negative index or list is empty or index greater than list size then throw a exception
	if (index < 0 || isEmpty() || index >= size())
	{
		throw invalid_argument("An element cannot be removed at this index or list is empty.");
	}

	// If the index is 0, remove the node at the head of the list
	if (index == 0)
	{
		Node<T> *temp = list_head;
		list_head = list_head->getNext();
		delete temp;
		return;
	}

	// Find the node at the given index and its previous node
	Node<T> *prev = nullptr;
	Node<T> *current = list_head;
	for (int i = 0; i < index; i++)
	{
		prev = current;
		current = current->getNext();
	}

	// If the old node is removed at the end of the list, update the tail of the list
	if (current->getNext() == nullptr)
	{
		list_tail = prev;
		prev->setNext(nullptr);
		delete current;
		return;
	}

	// Remove the node if the node was in beetween list head and list tail
	prev->setNext(current->getNext());
	delete current;
}

template <typename T>
void List<T>::rmElement(T data)
{
	Node<T> *prev = nullptr;
	Node<T> *current = list_head;
	for (Node<T> *n = list_head; n != nullptr; n = n->getNext())
	{
		// If the value of the node is equal to the given data, increment a counter
		if (n->getValue() == data)
		{
			current = n;
			break;
		}
		prev = n;
	}

	if (current->getValue() == list_head->getValue())
	{
		Node<T> *temp = list_head;
		list_head = list_head->getNext();
		delete temp;
		return;
	}

	// If the old node is removed at the end of the list, update the tail of the list
	if (current->getNext() == nullptr)
	{
		list_tail = prev;
		prev->setNext(nullptr);
		delete current;
		return;
	}

	// Remove the node if the node was in beetween list head and list tail
	prev->setNext(current->getNext());
	delete current;
}

// Function to erase all nodes in the list
template <typename T>
void List<T>::erase()
{
	// If the list is empty, throw a logic error
	if (isEmpty())
	{
		throw logic_error("List is empty");
	}
	else
	{
		// Iterate over each node in the list
		Node<T> *temp = list_head;
		for (Node<T> *n = list_head; temp != nullptr; n = temp)
		{
			// Get the next node and delete the current node
			temp = n->getNext();
			delete n;
		}
		// Set the head of the list to null
		list_head = nullptr;
	}
}

// Function to get the size of the list
template <typename T>
int List<T>::size()
{
	// If the list is empty, return 0
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		// Iterate over each node in the list and increment a counter
		int i = 0;
		for (Node<T> *n = list_head; n != nullptr; n = n->getNext())
		{
			i++;
		}
		// Return the counter
		return i;
	}
}

// Function to count the occurrences of a value in the list
template <typename T>
int List<T>::count(T data)
{
	// If the list is empty, return 0
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		// Iterate over each node in the list
		int i = 0;
		for (Node<T> *n = list_head; n != nullptr; n = n->getNext())
		{
			// If the value of the node is equal to the given data, increment a counter
			if (n->getValue() == data)
			{
				i++;
			}
		}
		// Return the counter
		return i;
	}
}

										//--------------------- Main Function ---------------------
int main()
{
	List<float> list;
	list.append(1);
	list.append(3);
	list.append(5);
	list.rmElement(5);
	for (Node<float> *n = list.getFirst(); n != nullptr; n = n->getNext())
	{
		cout << n->getValue() << endl;
	}
	cout << "List size : "<<  list.size(); 
}
