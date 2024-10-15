#include <iostream>
using namespace std;

int front = -1;
int rear = -1;
int N = 5;
int arr[5];

// Check if the queue is full
bool isFull() {
    return (rear == N - 1);
}

// Check if the queue is empty
bool isEmpty() {
    return (front == -1 || front > rear);
}

// Enqueue an element into the queue
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is Full!" << endl;
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    arr[rear] = value;
}

// Dequeue an element from the queue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    } else if (front == rear) { // Only one element left
        front = rear = -1;
    } else {
        front++;
    }
}

// Display the elements of the queue
void display() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "\nElements of the Queue: \n" << endl;
    for (int i = front; i <= rear; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    
    dequeue(); // Remove first element (10)
    dequeue(); // Remove next element (20)
    display();
    
    enqueue(60); // Try adding an element (this will fail because the queue is full in a linear queue)
    display();
}
