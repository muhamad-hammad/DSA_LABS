#include<iostream>
using namespace std;

void printArray(string A[], int len){
    for(int i=0; i<len; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


int priority(string d){
    if(d == "CEO") 
        return 1;
    if(d == "CTO") 
        return 2;
    if(d == "CFO") 
        return 3;
    if(d == "VP") 
        return 4;
    if(d == "MGR") 
        return 5;
    if(d == "EMP") 
        return 6;
    return 7;
}


void insertionSort(string A[], int len) {
    
    for(int j=1; j<len; j++ ){
        string key = A[j];
        int i = j-1;
        while (i >= 0 && priority(A[i]) > priority(key))
        {
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
    }
}

int main(){
    string A[8] =  {"EMP", "CFO", "MGR", "EMP", "VP", "CTO", "MGR", "CEO"};
    cout<<"Initial string : "<<endl;
    printArray(A, 8);
    insertionSort(A, 8);
    cout<<"Sorted string : "<<endl;
    printArray(A, 8);
}