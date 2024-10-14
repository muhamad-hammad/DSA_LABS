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

bool isDistributedUniformly(int A[], int len){
    if(len < 2)
        return true;
    int diff = A[1] - A[0];
    for(int i=1; i<len; i++){
        if(A[i] - A[i-1] != diff)
            return false;
    }
    return true;
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


void interpolationSearch(int A[], int len, int key) {
    int low = 0;
    int high = len - 1;
    int POS = low + (key - A[low]) * (high - low) / (A[high] - A[low]);

    while (low <= high && key >= A[low] && key <= A[high]) 
    {
        if (low == high) {
            if(A[low] == key){
                cout << "Element found at index :"  << low <<endl;
            } else {
                cout << "Element not found" << endl;
            }
            return;
        }
        if (A[high] == A[low]){
            cout << "Not uniformly distributed" << endl;
            return;
        }
        int POS = low + (static_cast<double>(key - A[low]) * (high - low)) / (A[high] - A[low]);
        if (A[POS] == key)
        {
            cout << "Element found at index :"  << POS << endl;
            return;
        }
        if (A[POS] < key) {
            low = POS + 1;
        } else {
            high = POS - 1;
        }
    }
    cout << "Element not found" << endl;
}

int main() {
    cout << "Enter the number of elements you want to keep in the array of account balance: " << endl;
    int length;
    cin >> length;
    int* A = new int[length];

    for (int i = 0; i < length; i++) {
        cout << "Enter the account balance " << i + 1 << ": " << endl;
        cin >> A[i];
    }

    printArray(A, length);
    bubbleSort(A, length);
    printArray(A, length);
    if (!isDistributedUniformly(A, length)) {
        cout << "Array is not uniformly distributed. Interpolation Search may not work effectively." << endl;
        delete[] A;
        return 1;
    }
    cout << "Enter the number you want to search: " << endl;
    int key;
    cin >> key;
    interpolationSearch(A, length, key);

    delete[] A;
    return 0;
}