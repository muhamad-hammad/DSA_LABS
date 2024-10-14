#include<iostream>
using namespace std;


int recursiveArraySum(int* arr[], int sizes[], int dim){
    if(dim == 0){
        return 0;
    }
    int sum = 0;
    for(int i = 0; i < sizes[dim-1]; i++){
        sum += arr[dim-1][i];
    }
    return sum + recursiveArraySum(arr, sizes, dim-1);
}

int main() {
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;
    
    int **matrix = new int *[numRows];
    int *numElements = new int[numRows];
    

    for (int i = 0; i < numRows; i++) {
        cout << "Enter the number of elements in row " << i + 1 << ": ";
        cin >> numElements[i];
        matrix[i] = new int[numElements[i]];
    }

    for (int i = 0; i < numRows; i++) {
        cout << "Enter elements for row " << i + 1 << ": " << endl;
        for (int j = 0; j < numElements[i]; j++) {
            cout << "Element number " << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nElements Matrix:" << endl;
    for (int i = 0; i < numRows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < numElements[i]; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int sum = recursiveArraySum(matrix, numElements, numRows);
    cout << "Sum of all elements: " << sum << endl;
    
    for (int i = 0; i < numRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] numElements;

    return 0;
}