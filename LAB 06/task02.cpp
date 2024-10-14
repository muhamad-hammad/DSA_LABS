#include <iostream>
using namespace std;

class queue{
    int *arr;
    int size;
    int front;
    int rear;

    public:
    queue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int data){
        if(rear == size-1){
            cout << "Queue is full" << endl;
        }
        else{
            rear++;
            arr[rear] = data;
        }
        if (front == -1) {
            front++;
        }
    }

    void dequeue(){
        if(front == -1 || front > rear){
            cout << "Queue is empty" << endl;
        }
        else{
            front++;
        }
    }

    void display(){
        if(front == -1 || front > rear){
            cout << "Queue is empty" << endl;
        }
        else{
            for(int i=front; i<=rear; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    ~queue(){
        delete[] arr;
    }
};

int main(){
    queue q(7);
    q.enqueue(13);
    q.enqueue(7);
    q.enqueue(4);
    q.enqueue(1);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(10);

    q.display();

    for (int i = 1; i < 7; i++)
    {
        q.dequeue();
        cout << "Customer " << i << " is being served" << endl;
        cout << "Remaining customers: ";
        q.display();
    }
    return 0;
}