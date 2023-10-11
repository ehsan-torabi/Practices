#include <iostream>

#define n = 5;
using namespace std;

int main(int argc, char const *argv[])
{

    int arr1[n] = {5, 4, 3, 2, 1};
    int arr2[n] = {10, 9, 8, 7, 6};
    int sortedArr[n * 2];
for(int i : arr1){
    for(int j : arr2){
        if(i>j){
            sortedArr+i;

        }else{
            sortedArr+j;
        }
    }
}
    

    for(int e : sortedArr){
        cout << e << endl;
    }

    return 0;
}
