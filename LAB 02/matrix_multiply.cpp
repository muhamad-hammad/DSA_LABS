#include "matrix_multiply.h"
#include <iostream>

using namespace std;

namespace task02
{

    int *MatrixMultiply::multiplyMatrix(int *arr1, int *arr2, int size)
    {
        int *arr3 = new int[size * size];
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                arr3[i * size + j] = 0;
                for (int k = 0; k < size; k++)
                {
                    arr3[i * size + j] += arr1[i * size + k] * arr2[k * size + j];
                }
            }
        }
        return arr3;
    }

    void MatrixMultiply::display(int *arrp, int n)
    {
        cout << "Array: {";
        for (int i = 0; i < n; i++)
        {
            cout << arrp[i] << " ";
            if (i < n - 1)
            {
                cout << ",";
            }
        }
        cout << "} ";
        cout << endl;
    }

}