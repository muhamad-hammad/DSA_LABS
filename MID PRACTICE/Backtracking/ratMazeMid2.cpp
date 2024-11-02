#include<iostream>
using namespace std;

bool isSafe(int** arr, int x, int y,int size){
    if(x<= size && y<=size && arr[x][y] == 1){
        return true;
    }
    return false;
}


bool ratInMaze(int** arr, int x, int y,int size, int** solArr){
    if (x == size - 1 && y == size - 1) {
        solArr[x][y] = 1;
        return true;
    }
    if(isSafe(arr, x, y, size)){
        solArr[x][y] = 1;
    if(ratInMaze(arr, x+1, y, size, solArr)){
        return true;
    }
    if(ratInMaze(arr, x, y+1, size, solArr)){
        return true;
    }
        solArr[x][y] = 0;
        return false;
    }
    return false;
}

void printSolution(int** solArr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << solArr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;

    int** arr = new int*[n];
    int** solArr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            solArr[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, n, solArr)) {
        cout << "Solution path:" << endl;
        printSolution(solArr, n);
    } else {
        cout << "No path exists." << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
        delete[] solArr[i];
    }
    delete[] arr;
    delete[] solArr;

    return 0;
}