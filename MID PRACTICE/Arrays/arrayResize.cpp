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

    //Resize
    int *newArray = new int[10];
    for (int i = 0; i < 10; i++)
    {
        newArray[i] = DArray[i];
    }
    delete []DArray;

    for(int i=0; i<10; i++){
        if(i>=5){
            newArray[i] = i;
        }
        cout<<newArray[i]<<" ";
        cout<<endl;
    }
    
}