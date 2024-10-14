// 2. Given an array through user input, sort the array in
// ascending as
// well as descending order and return it using radix sort.
#include <iostream>
using namespace std;

int getMax(int a[], int len)
{
    int max = a[0];
    for (int i = 0; i < len; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

void countSort(int *arr, int len)
{
    int max = getMax(arr, len);
    int *output = new int[len];
    int *count = new int[max + 1];

    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = len - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = output[i];
    }
    delete[] output;
    delete[] count;
}

void assendingRadixSort(int *arr, int len)
{
    int max = getMax(arr, len);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, len);
    }
}

void reverse(int *arr, int len)
{
    int temp;
    for (int i = 0; i < len / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}

void dessendingRadixSort(int *arr, int len)
{
    assendingRadixSort(arr, len);
    reverse(arr, len);
}

int main()
{
    cout << "Enter the number of elements you wana keep in the array to be sorted:" << endl;
    int n;
    cin >> n;
    cout << "Enter the Array you wana sort: " << endl;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element number " << i + 1 << " : ";
        cin >> arr[i];
    }

    assendingRadixSort(arr, n);

    cout << "The sorted array in Assending order is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    dessendingRadixSort(arr, n);
    cout << "The sorted array in Dessending order is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}