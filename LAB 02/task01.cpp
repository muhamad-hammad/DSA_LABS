// Implement Jagged arrays from the above pseudocode by taking a size of 5 and resizing it to 10 in each index.

#include <iostream>
using namespace std;

void display(int *arrp, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arrp[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size = 5;
    int *arr1 = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr1[i] = i + 1;
    };
    display(arr1, size);
    size = 10;
    int *arr2 = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (i < 5)
        {
            arr2[i] = arr1[i];
        }
        else
        {
            arr2[i] = i + 1;
        }
    }
    display(arr2, size);
}