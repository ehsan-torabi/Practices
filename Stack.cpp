#include <iostream>

using namespace std;

#define MAX 1000

template <typename T>
class Stack
{
    int top;

public:
    T a[MAX];
    Stack() { top = -1; }
    bool push(T x);
    T pop();
    T peek();
    bool isEmpty();
};
template <typename T>
bool Stack<T>::push(T x)
{
    if (top >= MAX - 1)
    {
        cout << "Stack overflow" << endl;
        return false;
    }
    else
    {
        a[++top] = x;
        cout << "Push is successful" << endl;
        return true;
    }
}
template <typename T>
T Stack<T>::pop()
{
    if (0 > top)
    {
        cout << "Stack underflow" << endl;
        return 0;
    }
    else
    {
        T x = a[top--];
        return x;
    }
}
template <typename T>
T Stack<T>::peek()
{
    if (top < 0)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }

    else
    {
        return a[top];
    }
}
template <typename T>
bool Stack<T>::isEmpty()
{

    return (top < 0);
}

int main(int argc, char const *argv[])
{
    class Stack<int> s;
    s.push(1);
    s.push(4);
    s.push(5);
    cout << s.pop() << " Popped from stack\n";
    cout << "Top element is : " << s.peek() << endl;

    while (s.isEmpty() == 0)
    {
        cout << s.peek() << endl;
        s.pop();
    }

    return 0;
}
