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



void shellSort(int A[], int len) {
    for (int gap = len/3; gap >0; gap-=3)
    {
        for(int j=gap; j<len; j++){
            int temp = A[j];
            int i = j;
            while (i >= gap && A[i-gap]>temp)
            {
                A[i] = A[i-gap];
                i -= gap;
            }
            A[i] = temp;
            
        }
    }
    
}


int main(){
    // Assuming eployees weights
    int B[] = {23, 11 , 44, 33,43, 54, 23, 22,44};
    int length2 = sizeof(B) / sizeof(B[0]);
    cout << "Employees weight before sorting: " << endl;
    printArray(B, length2);
    shellSort(B, length2);
    cout << "Employees weight after sorting: " << endl;
    printArray(B, length2);

}
