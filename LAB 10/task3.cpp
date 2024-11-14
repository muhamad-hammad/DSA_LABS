// Assume you are tasked to schedule computer tasks. Given task from t1 to tn you must
// schedule them in the given manner down below.
// Note:
// Each task that is being pooled comes with a priority (generate this priority randomly
// between values 1 to 10). The value with the highest priority gets the first treatment and
// then subsequent nodes will get later priorities. Once the tree is built up delete the nodes
// accordingly to the priority (Max to min) while also printing the order.


#include <iostream>
using namespace std;

// Node structure to represent each element in the priority queue
struct Node {
    int data;
    int priority;
    Node* next;
};

class PriorityQueue {
private:
    Node* head; // Head of the priority queue

public:
    PriorityQueue() {
        head = NULL;
    }

    // Function to push (insert) an element into the priority queue
    void push(int data, int priority) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->priority = priority;

        // If the queue is empty or the new element has higher priority
        if (head == NULL || newNode->priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;

            // Find the position to insert based on priority
            while (temp->next != NULL && temp->next->priority <= newNode->priority) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Function to pop (remove) the element with the highest priority from the queue
    void pop() {
        if (head == NULL) {
            cout << "Priority Queue is empty." << endl;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to peek (get) the element with the highest priority without removing it
    int peek() {
        if (head == NULL) {
            cout << "Priority Queue is empty." << endl;
            return -1; // You can choose a different value to indicate an error.
        }
        return head->data;
    }

    void printQueue(){
        if (head == NULL) {
                    cout << "Priority Queue is empty." << endl;
                    return;
                }
                
                Node* current = head;
                cout << "Priority Queue: ";
                while (current != NULL) {
                    cout << current->data << " ";
                    current = current->next;
                }
                cout << endl;
        
    }
};

int random() {
    return rand() % 10 + 1;
}


int main() {
    PriorityQueue priorityQueue;
    int arr[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++){
        priorityQueue.push(arr[i], random());
    }
    

    // Peek and print the element with the highest priority
    priorityQueue.printQueue();

    return 0;
}