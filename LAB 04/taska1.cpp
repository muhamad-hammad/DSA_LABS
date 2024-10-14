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
void bubbleSort(int A[], int len) {
    bool swapped;
    for (int i = 0; i < len - 1; i++) {
        swapped = false;
        for (int j = 0; j < len - i - 1; j++) {
            if (A[j] < A[j + 1]) {  
                swapVal(A[j], A[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main(){
    int B[] = {23, 11 , 44, 33,43, 54, 23, 22,44};
    int length2 = sizeof(B) / sizeof(B[0]);
    printArray(B, length2);
    bubbleSort(B, length2);
    printArray(B, length2);

}
