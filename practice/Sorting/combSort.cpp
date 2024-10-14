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
void combSort(int A[], int len) {
    float shrink = 1.3;
    int gap = len;
    bool swapped = true;
    while (gap > 1 || swapped == true){
        gap = (int) (gap/shrink);
        if (gap < 1)
            gap = 1;
    swapped = false;
    for(int i=0; i<len-gap; i++){
            if (A[i] > A[i+gap]){
                swapVal(A[i], A[i+gap]);
                swapped = true;
    }
    }
    }
}


int main(){
    int B[] = {23, 11 , 44, 33,43, 54, 23, 22,44};
    int length2 = sizeof(B) / sizeof(B[0]);
    printArray(B, length2);
    combSort(B, length2);
    printArray(B, length2);

}
