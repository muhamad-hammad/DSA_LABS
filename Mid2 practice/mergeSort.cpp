#include<iostream>
using namespace std;

void merge(int *arr, int left, int mid, int right){
    int s1 = mid - left + 1;
    int s2 = right - mid;

    int *arr1 = new int[s1];
    int *arr2 = new int[s1];

    for(int i=0; i<=s1; i++){
        arr1[i] = arr[left + i];
    }
    for(int i=0; i<s2; i++){
        arr2[i] = arr[mid+1+i];
    }
    int i=0, j=0, k=left;
    while(i<s1 && j<s2){
        if(arr1[i] < arr2[j]){
            arr[k++] = arr1[i++] ;
        } else if(arr1[i] > arr2[j]){
            arr[k++] = arr2[j++] ;
        }
    }

    while(i<s1){
            arr[k++] = arr1[i++] ;
    }
    while(j<s2){
            arr[k++] = arr2[j++] ;
    }
}

void mergeSort(int* arr, int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid ,right);
    }
}

void printarr(int *arr, int a){
    for(int i=0; i<a; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[7] = {1,7,3,9,2,6,4};
    printarr(arr,7);
    mergeSort(arr, 0, 6);
    printarr(arr,7);
    
    
}