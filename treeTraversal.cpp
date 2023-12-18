#include <iostream>
#include <string>
#include "MyLib/stack.h"
#include "MyLib/cqueue.h"
#include "MyLib/link-list.h"
using namespace std;

template <typename T>
class TreeNode
{
private:
    T value;                           // Value of the node
    LinkList<TreeNode<T> *> *children; // List of child
public:
    // Constructor
    TreeNode(T value) : value(value)
    {
        children = new LinkList<TreeNode<T> *>();
    }

    // Getter for the children
    LinkList<TreeNode<T> *> *getChildren() const { return children; }

    // Getter for the child in a special index 
    TreeNode<T> *getChild(int index)
    {
        try
        {
            return children->getValue(index);
        }
        catch (const std::exception &e)
        {
            return nullptr;
        }
    }

    // Getter for the value
    T getValue() { return value; }

    // Check if the node is a leaf node
    bool isLeaf() { return (children.isEmpty()); }

    // Function for get degree of this node
    int Degree()
    {
        return children->size();
    }

    // Adder for the children
    void AddChild(TreeNode<T> *c) { children->append(c); }
};

// Define the binary tree traversal template class
template <typename T>
class TreeTraversal
{
private:
    TreeNode<T> *root; // Root of the binary tree

    // Helper function for postfix traversal
    void PostfixHelper(TreeNode<T> *node, string &s)
    {
        if (node->Degree() > 2)
        {
            cout << "this just work in binary trees";
        }
        else
        {
            if (node->getChild(0) != nullptr)
            {
                PostfixHelper(node->getChild(0), s);
            }

            if (node->getChild(1) != nullptr)
            {
                PostfixHelper(node->getChild(1), s);
            }

            s += to_string(node->getValue());
        }
    }

    // Helper function for prefix traversal
    void PrefixHelper(TreeNode<T> *node, string &s)
    {
        if (node->Degree() > 2)
        {
            cout << "this just work in binary trees";
        }
        else
        {
            s += to_string(node->getValue());

            if (node->getChild(0) != nullptr)
            {
                PrefixHelper(node->getChild(0), s);
            }

            if (node->getChild(1) != nullptr)
            {
                PrefixHelper(node->getChild(1), s);
            }
        }
    }

    // Helper function for infix traversal
    void InfixHelper(TreeNode<T> *node, string &s)
    {
        if (node->Degree() > 2)
        {
            cout << "this just work in binary trees";
        }
        else
        {
            if (node->getChild(0) != nullptr)
            {
                InfixHelper(node->getChild(0), s);
            }

            s += to_string(node->getValue());

            if (node->getChild(1) != nullptr)
            {
                InfixHelper(node->getChild(1), s);
            }
        }
    }

public:
    // Constructor
    TreeTraversal(TreeNode<T> *treeRoot) : root(treeRoot) {}

    // Getter for the root
    TreeNode<T> *getRoot() const { return root; }

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
    // Function for BFS (Breadth-first) traversal
    string BFS()
    {
        Cqueue<TreeNode<T> *> tempQueue(10);
        string tempStr = "";
        tempQueue.Enqueue(root);
        while (!tempQueue.isEmpty())
        {
            TreeNode<T> *tempNode = tempQueue.Dequeue();
            tempStr += to_string(tempNode->getValue());
            for (int i = 0; i < tempNode->Degree(); i++)
            {
                tempQueue.Enqueue(tempNode->getChild(i));
            }
        }
        return tempStr;
    }

    // Function for DFS (Depth-first) traversal
    string DFS()
    {
        Stack<TreeNode<T> *> tempStack(10);
        string tempStr = "";
        tempStack.push(root);
        while (!tempStack.isEmpty())
        {
            TreeNode<T> *tempNode = tempStack.pop();
            tempStr += to_string(tempNode->getValue());
            for (int i = tempNode->Degree() - 1; 0 <= i; i--)
            {
                tempStack.push(tempNode->getChild(i));
            }
        }
        return tempStr;
    }
};

int main(int argc, char const *argv[])
{

    TreeNode<int> binary(1);
    binary.AddChild(new TreeNode<int>(2));
    binary.AddChild(new TreeNode<int>(3));
    binary.getChild(0)->AddChild(new TreeNode<int>(4));
    binary.getChild(0)->AddChild(new TreeNode<int>(5));
    binary.getChild(1)->AddChild(new TreeNode<int>(6));
    binary.getChild(1)->AddChild(new TreeNode<int>(7));
    TreeTraversal<int> binaryTree(&binary);
    cout << "----Binary Tree---- "<<endl;
    cout << "Infix: " << binaryTree.Infix() << endl;
    cout << "Postfix: " << binaryTree.Postfix() << endl;
    cout << "Prefix: " << binaryTree.Prefix() << endl;
    cout << "DFS: " << binaryTree.DFS() << endl;
    cout << "BFS: " << binaryTree.BFS() << endl;
    cout << "----Binary Tree---- "<<endl;
    TreeNode<int> troot(0);
    troot.AddChild(new TreeNode<int>(1));
    troot.AddChild(new TreeNode<int>(2));
    troot.AddChild(new TreeNode<int>(3));
    troot.AddChild(new TreeNode<int>(4));
    troot.getChildren()->getValue(0)->AddChild(new TreeNode<int>(5));
    TreeTraversal<int> a(&troot);
    cout << "DFS: " << a.DFS() << endl;
    cout << "BFS: " << a.BFS() << endl;

    return 0;
}
