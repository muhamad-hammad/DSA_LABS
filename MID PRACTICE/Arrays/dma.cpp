#include<iostream>
using namespace std;

int main(){
    // Dynamic Allocation
    int *DArray = new int[5];
    for(int i=0; i<5; i++){
        DArray[i] = i * i;
        cout<<DArray[i]<<" ";
        cout<<endl;
    }
    delete []DArray;
    
}