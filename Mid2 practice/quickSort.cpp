#include<iostream>
using namespace std;

void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int* arr, int left, int right){
     int pivot = arr[right]; // taking last element as pivot
     int i = left -1;

     for(int j=left; j<right; j++){
        if(arr[j] < pivot){
            swap(arr, ++i, j);
        }
     }
        swap(arr, i+1, right);
        return i+1;
}

void quickSort(int* arr, int left, int right){
    if (left < right){
    int p = partition(arr, left, right);
    quickSort(arr, left, p-1);
    quickSort(arr, p+1, right);
}
}

void printarr(int *arr, int a){
    for(int i=0; i<a; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int arr[5] = { 7,3,5,2,9};
    printarr(arr,5);
    quickSort(arr, 0, 4);
    printarr(arr,5);
    return 0;
}