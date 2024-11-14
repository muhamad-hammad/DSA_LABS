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

void printHeap(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main() {
    int arr[] = {7, 1, 6, 2, 5, 9, 10, 2};
    int N = sizeof(arr) / sizeof(arr[0]);

    cout << "Min-Heap:\n";
    buildMinHeap(arr, N);
    printHeap(arr, N);

    cout << "\nMax-Heap:\n";
    buildMaxHeap(arr, N);
    printHeap(arr, N);

    return 0;
}
