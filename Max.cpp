#include <iostream>
using namespace std;

int main()
{
    const int n = 10;
    int arr[n] = {5, 1, 6, 7, 2, 4, 9, 8, 3, 10};
    for (int i = 0; i < n; i++)
    {
        int index;
        int max = arr[i];
        for (int j = i; j < n; j++)
        {

            if (max < arr[j])
            {
                max = arr[j];
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }

    }
    for (int e : arr)
    {
        cout << e << "\n";
    }
    return 0;
}
