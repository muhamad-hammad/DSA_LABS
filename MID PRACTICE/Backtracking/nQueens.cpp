#include <iostream>

using namespace std;

// Function to check if it's safe to place a queen at position (x, y)
bool isSafe(int **arr, int x, int y, int n)
{
    // Check if there's a queen in the same column
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false; // Queen found, not safe
        }
    }

    // Check the upper-left diagonal
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false; // Queen found, not safe
        }
        row--;
        col--;
    }

    // Check the upper-right diagonal
    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false; // Queen found, not safe
        }
        row--;
        col++;
    }

    // If no queens are found in the column or diagonals, it's safe
    return true;
}

// Recursive function to solve the N-Queens problem
bool nQueen(int **arr, int x, int n)
{
    // Base case: if all queens are placed, return true
    if (x >= n)
    {
        return true;
    }

    // Try placing the queen in each column of the current row
    for (int col = 0; col < n; col++)
    {
        // Check if placing a queen at (x, col) is safe
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1; // Place the queen

            // Recursively try to place the next queen
            if (nQueen(arr, x + 1, n))
            {
                return true; // Solution found
            }

            // Backtracking: remove the queen and try the next column
            arr[x][col] = 0;
        }
    }

    // If the queen can't be placed in any column, return false
    return false;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    // Dynamically allocate a 2D array for the chessboard
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0; // Initialize all positions to 0
        }
    }

    // Try to solve the N-Queens problem
    if (nQueen(arr, 0, n))
    {
        // If a solution is found, print the board
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        // If no solution is found, print a message
        cout << "No solution exists for " << n << " queens." << endl;
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}