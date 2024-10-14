#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool solveNQueens(int board[], int n, int row = 0) {
    if (row == n) {
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;

            if (solveNQueens(board, n, row + 1)) {
                return true;
            }

            board[row] = -1;
        }
    }
    return false;
}

void printSolution(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
int CountQueens(int board[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n = 4;
    int* board = new int[n];
    
    for (int i = 0; i < n; i++) {
        board[i] = -1;
    }

    if (solveNQueens(board, n)) {
        cout << "Solution for a " << n << "x" << n << " grid:" << endl;
        printSolution(board, n);
        cout << "Maximum Number of Queens: " << CountQueens(board, n) << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    delete[] board;
    
    return 0;
}
