#include <iostream>
#include <string>
using namespace std;

// Define the binary node template class
template <typename T>
class BinNode
{
private:
    T value; // Value of the node
    BinNode<T> *leftChild; // Pointer to the left child node
    BinNode<T> *rightChild; // Pointer to the right child node

public:
    // Constructor
    BinNode(T value) : value(value), leftChild(nullptr), rightChild(nullptr) {}

    // Getter for the left child
    BinNode<T> *getLeftChild() const { return leftChild; }

    // Getter for the right child
    BinNode<T> *getRightChild() const { return rightChild; }

    // Getter for the value
    T getValue() { return value; }

    // Check if the node is a leaf node
    bool isLeaf() { return (leftChild == nullptr && rightChild == nullptr); }

    // Setter for the left child
    void setLeftChild(BinNode<T> *lc) { leftChild = lc; }

    // Setter for the right child
    void setRightChild(BinNode<T> *rc) { rightChild = rc; }
};

// Define the binary tree traversal template class
template <typename T>
class BinTreeTraversal
{
private:
    BinNode<T> *root; // Root of the binary tree

    // Helper function for postfix traversal
    void PostfixHelper(BinNode<T> *node, string &s)
    {
        if (node->getLeftChild() != nullptr)
        {
            PostfixHelper(node->getLeftChild(), s);
        }

        if (node->getRightChild() != nullptr)
        {
            PostfixHelper(node->getRightChild(), s);
        }

        s += to_string(node->getValue());
    }

    // Helper function for prefix traversal
    void PrefixHelper(BinNode<T> *node, string &s)
    {
        s += to_string(node->getValue());

        if (node->getLeftChild() != nullptr)
        {
            PrefixHelper(node->getLeftChild(), s);
        }

        if (node->getRightChild() != nullptr)
        {
            PrefixHelper(node->getRightChild(), s);
        }
    }

    // Helper function for infix traversal
    void InfixHelper(BinNode<T> *node, string &s)
    {
        if (node->getLeftChild() != nullptr)
        {
            InfixHelper(node->getLeftChild(), s);
        }

        s += to_string(node->getValue());

        if (node->getRightChild() != nullptr)
        {
            InfixHelper(node->getRightChild(), s);
        }
    }

public:
    // Constructor
    BinTreeTraversal(BinNode<T> *treeRoot) : root(treeRoot) {}

    // Getter for the root
    BinNode<T> *getRoot() const { return root; }

    // Function for infix traversal
    string Infix()
    {
        string s = "";
        InfixHelper(root, s);
        return s;
    }

    // Function for postfix traversal
    string Postfix()
    {
        string s = "";
        PostfixHelper(root, s);
        return s;
    }

    // Function for prefix traversal
    string Prefix()
    {
        string s = "";
        PrefixHelper(root, s);
        return s;
    }
};

int main(int argc, char const *argv[])
{
    // Create a binary tree
    BinNode<int> root(0);
    root.setLeftChild(new BinNode<int>(1));
    root.setRightChild(new BinNode<int>(2));
    root.getLeftChild()->setLeftChild(new BinNode<int>(3));
    root.getLeftChild()->setRightChild(new BinNode<int>(4));

    // Perform tree traversals
    BinTreeTraversal<int> b(&root);
    cout << "Infix: " << b.Infix() << endl;
    cout << "Postfix: " << b.Postfix() << endl;
    cout << "Prefix: " << b.Prefix() << endl;

    return 0;
}
