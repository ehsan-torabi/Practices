#include <iostream>

using namespace std;

// Non-recursive Fibonacci 
int fib(int n)
{
    int t1 = 0, t2 = 1;
    int next = t1 + t2;
    for (int i = 3; i <= n; i++)
    {
        t1 = t2;
        t2 = next;
        next = t1 + t2;
    }
    return next;
}

// Recursive Fibonacci 
int rfib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }

    return rfib(n - 1) + rfib(n - 2);
}

int main(int argc, const char **argv)
{
    cout << rfib(10) << endl;
    cout << fib(10) << endl;
    return 0;
}
