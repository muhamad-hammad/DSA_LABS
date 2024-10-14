#include<iostream>
using namespace std;

int main(){
    int rows = 3;
    int **jagged = new int*[rows];

    for(int i=0; i<3; i++){
        jagged[i]   = new int[i+2];
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<i+2; j++ ){
            jagged[i][j] = i+j;
            cout << jagged[i][j] << " ";
        }
        cout << endl;
    }
    //free memory
    for(int i=0; i<rows; i++){
        delete[] jagged[i];
    }

    return 0;
}