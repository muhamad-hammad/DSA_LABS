#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

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

void insertionSort(int *arr, int n) {
    for (int j = 1; j < n; j++) {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }
}

void shellSort(int *arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int res = j;
            while (res >= gap && arr[res - gap] > temp) {
                arr[res] = arr[res - gap];
                res -= gap;
            }
            arr[res] = temp;
        }
    }
}

int partition(int arr[], int s, int e) {
    int mid = (s + e) / 2;
    int pivot = arr[mid];
    int c = 0;

    for (int i = s; i <= e; i++) {
        if (arr[i] < pivot) {
            c++;
        }
    }

    int pivotIndex = s + c;
    swap(arr[pivotIndex], arr[mid]);

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < arr[pivotIndex]) {
            i++;
        }
        while (arr[j] > arr[pivotIndex]) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    if (s >= e)
        return;
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

void merge(int *arr, int left, int right, int mid) {
    int s1 = mid - left + 1;
    int s2 = right - mid;

    int *leftarr = new int[s1];
    int *rightarr = new int[s2];

    for (int i = 0; i < s1; i++) {
        leftarr[i] = arr[left + i];
    }
    for (int j = 0; j < s2; j++) {
        rightarr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < s1 && j < s2) {
        if (leftarr[i] <= rightarr[j]) {
            arr[k++] = leftarr[i++];
        } else {
            arr[k++] = rightarr[j++];
        }
    }

    while (i < s1) {
        arr[k++] = leftarr[i++];
    }

    while (j < s2) {
        arr[k++] = rightarr[j++];
    }

    delete[] leftarr;
    delete[] rightarr;
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right, mid);
    }
}

void displayArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 7;
    int arr[7] = {3, 9, 6, 3, 6, 1, 8};

    int choice;

    cout << "Choose sorting algorithm:\n";
    cout << "1. Selection Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Shell Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. Merge Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            SelectionSort(arr, n);
            cout << "Sorted array using Selection Sort: ";
            break;
        case 2:
            insertionSort(arr, n);
            cout << "Sorted array using Insertion Sort: ";
            break;
        case 3:
            shellSort(arr, n);
            cout << "Sorted array using Shell Sort: ";
            break;
        case 4:
            quickSort(arr, 0, n - 1);
            cout << "Sorted array using Quick Sort: ";
            break;
        case 5:
            mergeSort(arr, 0, n - 1);
            cout << "Sorted array using Merge Sort: ";
            break;
        default:
            cout << "Invalid choice" << endl;
            return 1;
    }

    displayArray(arr, n);

    return 0;
}
