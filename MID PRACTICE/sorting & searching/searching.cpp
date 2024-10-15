#include<iostream>
using namespace std;

// Selection Sort
void SelectionSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

// Linear Search
void linearSearch(int *arr, int len, int key) {
    bool found = false; // Flag to track if key is found
    for (int i = 0; i < len; i++) {
        if (arr[i] == key) {
            cout << "Key found at index: " << i << endl;
            found = true;
            break; // Exit loop after finding the key
        }
    }
    if (!found) {
        cout << "Key not found!" << endl;
    }
}

// Binary Search
int binarySearch(int *arr, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid-point

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid; // Return the index where key is found
        }
        // If key is greater, ignore the left half
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        // If key is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Return -1 if key is not found
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 22;

    // Sorting the array before applying binary search
    SelectionSort(arr, n);
    
    // Linear Search
    cout << "Linear Search:" << endl;
    linearSearch(arr, n, key);
    
    // Binary Search
    cout << "Binary Search:" << endl;
    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found!" << endl;
    }

    return 0;
}
