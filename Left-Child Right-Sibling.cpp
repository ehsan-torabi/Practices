template <typename T>
class Node
{
private:
    T value;
    Node<T> *leftChild;
    Node<T> *rightSibling;
    Node<T> *parrent;

public:
    Node(T val);
    Node<T> *getChild();
    Node<T> *getSibling();
    Node<T> *getParrent();
    T getValue();
    bool isRoot();
    bool isLeaf();
    void setValue(T val);
    void setChild(Node<T> *ch);
    void setRightsibling(Node<T> *rs);
    void setParrent(Node<T> *p);
};
template <typename T>
Node<T>::Node(T val)
{
}
template <typename T>
Node<T> *Node<T>::getChild()
{
    return leftChild;
}

template <typename T>
Node<T> *Node<T>::getSibling()
{
    return rightSibling;
}

template <typename T>
Node<T> *Node<T>::getParrent()
{
    return parrent;
}

template <typename T>
T Node<T>::getValue()
{
    return value;
}

template <typename T>
bool Node<T>::isRoot()
{
    return (parrent == nullptr);
}

template <typename T>
bool Node<T>::isLeaf()
{
    return (leftChild == nullptr && rightSibling == nullptr);
}

template <typename T>
void Node<T>::setValue(T value)
{
    this->value = value;
}

template <typename T>
void Node<T>::setChild(Node<T> *ch)
{
    leftChild = ch;
}

template <typename T>
void Node<T>::setRightsibling(Node<T> *rs)
{
    rightSibling = rs;
}

template <typename T>
void Node<T>::setParrent(Node<T> *p)
{
    parrent = p;
}