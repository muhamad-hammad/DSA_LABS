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
            if (A[j] > A[j+1]) {
                swapVal(A[j], A[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}


int binarySearch(int A[], int len, int key) {
    int low = 0;
    int high = len - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (A[mid] == key) {
            cout << "Found at " << mid << endl;
            return mid;
        } 
        else if (A[mid] > key) {
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }

    return low;
}

void updateArraay(int A[], int &len, int key, int pos) {
    for (int i = len; i > pos; i--) {
        A[i] = A[i - 1];
    }
    A[pos] = key;
    len++;
}

int main(){
    int A[] = {23, 11 , 44, 33,43, 54, 23, 22,44};
    int length = sizeof(A) / sizeof(A[0]);
    int l2rollno = 44;// roll no: 23I-0544
    cout << "Original array:" << endl;
    printArray(A, length);
    bubbleSort(A, length);
    cout << "Sorted array:" << endl;
    printArray(A, length);
    int position = binarySearch(A, length, l2rollno);
    if (position < length && A[position] == l2rollno) {
        cout << "Employee ID " << l2rollno << " found at position: " << position << endl;
    } else {
        cout << "Employee ID " << l2rollno << " not found, inserting at position: " << position << endl;
        updateArraay(A, length, l2rollno, position);
        cout << "Array after insertion:" << endl;
        printArray(A, length);
    }
}