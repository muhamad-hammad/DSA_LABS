#include <iostream>
using namespace std;


void merge(int *arr, int s, int e){
    int mid = (s+e)/2;

    int len1 = mid - s +1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid+1;
    for (int i = 0; i < len1; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }
    

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        } else if(first[index1] > second[index2]){
            arr[mainArrayIndex++] = second[index2++];
        } 
    }

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }
    
    delete []first;
    delete []second;
}


void asssendingmergeSort(int *arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    asssendingmergeSort(arr, s, mid);
    asssendingmergeSort(arr, mid+1, e);
    merge(arr, s, e);
}

void reverse(int *arr, int len){
    int temp;
    for (int i = 0; i < len / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}

void dessendingmergeSort(int *arr, int s, int e){
    reverse(arr, e);
    asssendingmergeSort(arr, s, e);
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

    asssendingmergeSort(arr, 0, n-1);

    cout << "The sorted array in Assending order is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    dessendingmergeSort(arr, 0, n-1);
    cout << "The sorted array in Dessending order is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}