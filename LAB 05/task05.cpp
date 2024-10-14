#include<iostream>
using namespace std;

bool isSafe(int maze[5][5], int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

bool ratinmaze(int maze[5][5], int x, int y, int n, int sol[5][5]) {
    if (x == n - 1 && y == n - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, n)) {
        sol[x][y] = 1;

        if (ratinmaze(maze, x + 1, y, n, sol)) {
            return true;
        }

        if (ratinmaze(maze, x, y + 1, n, sol)) {
            return true;
        }

        sol[x][y] = 0;
        return false;
    }

    return false;
}

void displaySolution(int sol[5][5], int n) {
    cout << "\nSolution to the Maze:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int maze[5][5] = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };
    
    int sol[5][5] = {0};
    
    if (ratinmaze(maze, 0, 0, 5, sol)) {
        displaySolution(sol, 5);
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
