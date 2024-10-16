#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Enqueue an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear == NULL) {
            // If queue is empty, both front and rear point to the new node
            front = rear = newNode;
            return;
        }

        // Add the new node at the end of the queue and update the rear pointer
        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        // Remove the front node and move the front pointer to the next node
        Node* temp = front;
        front = front->next;

        // If the queue becomes empty after dequeuing
        if (front == NULL) {
            rear = NULL;
        }

        // Free the dequeued node's memory
        delete temp;
    }

    // Display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Peek at the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek." << endl;
            return -1;
        }
        return front->data;
    }

    // Destructor to free up the memory when queue is destroyed
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    // Display elements
    q.display();

    // Dequeue elements
    q.dequeue();
    q.dequeue();

    // Display elements again after dequeue
    q.display();

    // Peek at the front element
    cout << "Front element: " << q.peek() << endl;

    return 0;
}
