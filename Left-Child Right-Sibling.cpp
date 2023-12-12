template <typename T>
class Node
{
private:
    T value;
    Node<T> *leftChild;
    Node<T> *rightSibling;

public:
    Node(T val);
    Node<T>* getChild();
    Node<T>* getSibling();
    T getValue(); 
    bool isRoot();
    void setValue(T val);
    void setChild(Node<T> *ch);
    void setRightsibling(Node<T> *rs);
    ~Node();
};
template <typename T>
Node<T>::Node(T val)
{
}
template <typename T>
Node<T>::~Node()
{
}
