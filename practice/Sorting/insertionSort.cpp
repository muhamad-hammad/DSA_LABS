#include<iostream>
using namespace std;

void printArray(int A[], int len){
    for(int i=0; i<len; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

    void swapVal(int &arr1, int &arr2){
    int temp = arr1;
    arr1 = arr2;
    arr2 = temp;
}

void insertionSort(int A[], int len) {
    
    for(int j=1; j<len; j++ ){
        int key = A[j];
        int i = j-1;
        while (i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
    }
}

int main(){
    int A[] = {23, 11 , 44, 33,43, 54, 23, 22,44};
    int length = sizeof(A) / sizeof(A[0]);
    printArray(A, length);
    insertionSort(A, length);
    printArray(A, length);

}
