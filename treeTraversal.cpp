#include <iostream>
#include <string>
using namespace std;

template <typename T>
class BinNode
{
private:
    T value;
    BinNode<T> *leftChild;
    BinNode<T> *rightChild;

public:
    BinNode(T value);
    BinNode<T> *getLeftChild() const;
    BinNode<T> *getRightChild() const;
    T getValue();
    bool isLeaf();
    void setLeftChild(BinNode<T> *lc);
    void setRightChild(BinNode<T> *rc);
};
template <typename T>
BinNode<T>::BinNode(T value) : leftChild(nullptr), rightChild(nullptr)
{
    this->value = value;
}

template <typename T>
BinNode<T> *BinNode<T>::getLeftChild() const
{
    return leftChild;
}

template <typename T>
BinNode<T> *BinNode<T>::getRightChild() const
{
    return rightChild;
}

template <typename T>
T BinNode<T>::getValue()
{
    return value;
}

template <typename T>
bool BinNode<T>::isLeaf()
{
    return (leftChild == nullptr && rightChild == nullptr);
}

template <typename T>
void BinNode<T>::setLeftChild(BinNode<T> *lc)
{
    leftChild = lc;
}

template <typename T>
void BinNode<T>::setRightChild(BinNode<T> *rc)
{
    rightChild = rc;
}

template <typename T>
class BinTreeTraversal
{
private:
    BinNode<T> *root;
    void PostfixHelper(BinNode<T> *rootB, string &s)
    {
        if (rootB->getLeftChild() != nullptr)
        {
            PostfixHelper(rootB->getLeftChild(), s);
        }

        if (rootB->getRightChild() != nullptr)
        {
            PostfixHelper(rootB->getRightChild(), s);
        }

        s += to_string(rootB->getValue());
    }

    void PrefixHelper(BinNode<T> *rootB, string &s)
    {
        s += to_string(rootB->getValue());
        if (rootB->getLeftChild() != nullptr)
        {
            PostfixHelper(rootB->getLeftChild(), s);
        }

        if (rootB->getRightChild() != nullptr)
        {
            PostfixHelper(rootB->getRightChild(), s);
        }
    }

    void InfixHelper(BinNode<T> *rootB, string &s)
    {

        if (rootB->getLeftChild() != nullptr)
        {
            PostfixHelper(rootB->getLeftChild(), s);
        }
        s += to_string(rootB->getValue());
        if (rootB->getRightChild() != nullptr)
        {
            PostfixHelper(rootB->getRightChild(), s);
        }
    }

public:
    BinTreeTraversal(BinNode<T> *treeRoot);
    BinNode<T> *getRoot() const;
    string Infix();
    string Postfix();
    string Prefix();
};

template <typename T>
BinTreeTraversal<T>::BinTreeTraversal(BinNode<T> *treeRoot)
{
    root = treeRoot;
}

template <typename T>
string BinTreeTraversal<T>::Infix()
{
    string s = "";
    InfixHelper(this->root, s);
    return s;
}

template <typename T>
string BinTreeTraversal<T>::Postfix()
{
    string s = "";
    PostfixHelper(this->root, s);
    return s;
}

template <typename T>
string BinTreeTraversal<T>::Prefix()
{
    string s = "";
    PrefixHelper(this->root, s);
    return s;
}

int main(int argc, char const *argv[])
{
    BinNode<int> root(0);
    root.setLeftChild(new BinNode<int>(1));
    root.setRightChild(new BinNode<int>(2));
    root.getLeftChild()->setLeftChild(new BinNode<int>(3));
    root.getLeftChild()->setRightChild(new BinNode<int>(4));
    BinTreeTraversal<int> b(&root);
    cout << b.Infix()<< endl;
    cout << b.Postfix()<< endl;
    cout << b.Prefix()<< endl;
    return 0;
}
