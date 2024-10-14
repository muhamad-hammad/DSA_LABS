#include<iostream>
using namespace std;


int main(){
    int row =3, col = 3;
    int ** array = new int*[row];
// initializing array
    for(int i=0; i<row; i++){
        array[i] = new int[col];
    }
// puting values
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            array[i][j] = i+j;
            cout << array[i][j] << " " ;
        }
        cout << endl;     
    }
// free memory
for(int i= 0; i<row; i++){
    delete [] array[i];
}
delete[] array;
return 0;
    
}