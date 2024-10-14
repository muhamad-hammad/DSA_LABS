// Create a header file called matrix_multuply.h that takes two arrays as input and multiplies them
// and outputs a multiplied array.

#include "matrix_multiply.cpp"

int main()
{
    const int size = 2;
    task02::MatrixMultiply mm;
    int arr2[size][size] = {{5, 6}, {7, 8}};
    int arr1[size][size] = {{1, 2}, {3, 4}};
    int *arr3 = mm.multiplyMatrix((int *)arr1, (int *)arr2, size);
    int displaySize = size * size;
    mm.display((int *)arr3, displaySize);

    delete[] arr3;
    return 0;
}