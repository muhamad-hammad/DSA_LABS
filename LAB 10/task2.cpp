//Consider another tree 35,33,42,10,14,19,27,44,26,31 Make the tree into a min heap and
// delete its root node and rebalance the tree to max heap and print the tree in a sorted
// output.

#include <iostream>
using namespace std;
#define MAX 100

void minheapify(int arr[], int N, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < N && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minheapify(arr, N, smallest);
    }
}

void buildMinHeap(int arr[], int N) {
    int startIndex = (N / 2) - 1;
    for (int i = startIndex; i >= 0; i--) {
        minheapify(arr, N, i);
    }
}

void maxheapify(int arr[], int N, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < N && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxheapify(arr, N, largest);
    }
}

void buildMaxHeap(int arr[], int N) {
    int startIndex = (N / 2) - 1;
    for (int i = startIndex; i >= 0; i--) {
        maxheapify(arr, N, i);
    }
}

void deleteRoot(int arr[], int& N) {
    arr[0] = arr[N - 1];
    N = N - 1;
    maxheapify(arr, N, 0);
}

void heapSort(int arr[], int N) {
    buildMaxHeap(arr, N);
    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxheapify(arr, i, 0);
    }
}

void printHeap(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    int arr[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial Min-Heap:\n";
    buildMinHeap(arr, N);
    printHeap(arr, N);

    deleteRoot(arr, N);
    cout << "\nAfter deleting the root node (min-heap):\n";
    printHeap(arr, N);

    cout << "\nRebalanced as Max-Heap:\n";
    buildMaxHeap(arr, N);
    printHeap(arr, N);

    cout << "\nSorted output (Max-Heap):\n";
    heapSort(arr, N);
    printHeap(arr, N);

    return 0;
}
