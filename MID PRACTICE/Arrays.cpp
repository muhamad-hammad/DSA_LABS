#include<iostream>
using namespace std;

int main(){
    // Dynamic Allocation
    int *DArray = new int[5];
    for(int i=0; i<5; i++){
        cin>>DArray[i];
    }
    for(int i=0; i<5; i++){
        cout<<DArray[i]<<" ";
        cout<<endl;
    }
    delete []DArray;

    // 2D Array
    
}