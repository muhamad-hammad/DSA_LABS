#include<iostream>
using namespace std;

// Function to print the array
void printArray(int A[], int len) {
    for(int i = 0; i < len; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Function to get the maximum element in the array
int getMax(int A[], int len) {
    int max = A[0];
    for(int i = 0; i < len; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Counting Sort algorithm
void countSort(int *arr, int len) {
    // Create the output array of the same size
    int *output = new int[len];
    
    // Get the maximum element from the array
    int max = getMax(arr, len);
    
    // Create a count array with all values initialized to 0
    int *count = new int[max + 1];
    for(int i = 0; i <= max; i++) {
        count[i] = 0;
    }
    
    // Store the count of each element
    for(int i = 0; i < len; i++) {
        count[arr[i]]++;
    }
    
    // Calculate the cumulative count
    for(int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    // Build the output array
    for(int i = len - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    // Copy the sorted elements into the original array
    for(int i = 0; i < len; i++) {
        arr[i] = output[i];
    }

    // Free dynamically allocated memory
    delete[] output;
    delete[] count;
}

void radixsort(int *arr, int len) {
    // Get the maximum element from the array
    int max = getMax(arr, len);

    // Perform counting sort for every digit
    for(int exp = 1; max/exp > 0; exp *= 10) {
        countSort(arr, len);
    }
}

// Driver program to test counting sort
int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, len);
    
    countSort(arr, len);
    
    cout << "Sorted array: ";
    printArray(arr, len);
    
    return 0;
}
