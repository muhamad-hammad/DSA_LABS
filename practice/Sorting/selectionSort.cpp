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
void selectionSort(int A[], int len) {
    int min;
    for(int i=0; i< len-1; i++){
        min = i;
        for(int j=1+i; j<len; j++){
            if (A[j] < A[min]){
                min = j;
            }
        }
        if(min != i){
            swapVal(A[i] , A[min]);
        }
    }
}


int main(){
    int B[] = {23, 11 , 44, 33,43, 54, 23, 22,44};
    int length2 = sizeof(B) / sizeof(B[0]);
    printArray(B, length2);
    selectionSort(B, length2);
    printArray(B, length2);

}
