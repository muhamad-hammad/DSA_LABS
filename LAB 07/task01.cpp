// 1. Given the array through user input implement quick sort 
// that simply chooses the middle element as the pivot and sort
// accordingly.

#include <iostream>
using namespace std;

void swap(int  &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[] , int s, int e){
    int mid = (s+e)/2;
    int pivot = arr[mid];
    int c=0;

    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivot){
            c++;
        }
    }

    int pivotIndex = s+c;
    swap(arr[pivotIndex] , arr[mid]);
    

    int i=s, j=e;
    while (i<pivotIndex && j>pivotIndex)
    {
        while(arr[i] < arr[pivotIndex]){
            i++;
        }
        while (arr[j] > arr[pivotIndex])
        {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i] , arr[j]);
            i++;
            j--;
        }

    }
    return pivotIndex;
    
}

void quickSort(int arr[] ,int s, int e){

    if(s>=e){
        return;
    }

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    cout << "Enter the number of elements you wana keep in the array to be sorted:" << endl;
    int n;
    cin >> n;
    cout << "Enter the Array you wana sort: " << endl;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cout << "Enter element number " << i+1 << " : " ;
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    cout << "The sorted array is: " << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";

    }
    cout << endl;
    delete[] arr;

    return 0;
}