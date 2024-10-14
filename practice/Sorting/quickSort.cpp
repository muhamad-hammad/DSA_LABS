#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count = 0;
    
    // Count how many elements are less than or equal to the pivot
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = s + count;

    // Swap pivot element with the element at pivotIndex
    swap(arr[pivotIndex], arr[s]);

    // Now move all elements smaller than pivot to the left and larger to the right
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < arr[pivotIndex]) {
            i++;
        }
        while (arr[j] > arr[pivotIndex]) {
            j--;
        }

        // Swap elements to ensure partitioning
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    // Base case
    if (s >= e)
        return;

    // Partition the array
    int p = partition(arr, s, e);

    // Recursively sort the left and right parts
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[5] = {2, 4, 1, 6, 9};
    int n = 5;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
