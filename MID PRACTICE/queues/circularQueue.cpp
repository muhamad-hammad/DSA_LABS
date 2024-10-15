#include<iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Circular Linked List
class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    // Add a node at the end
    void addAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Pointing to itself to make it circular
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Add a node at the start
    void addAtStart(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode; // Last node's next now points to the new head
            newNode->next = head;
            head = newNode; // Update head to the new node
        }
    }

    // Delete a node at the start
    void deleteAtStart() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) { // Traverse to the last node
                temp = temp->next;
            }
            Node* toDelete = head;
            temp->next = head->next; // Last node points to the second node
            head = head->next; // Update head to the second node
            delete toDelete;
        }
    }

    // Delete a node at the end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == head) { // Only one node
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head; // Second last node points to the head
            delete temp;
        }
    }

    // Display the circular linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.addAtEnd(10);
    cll.addAtEnd(20);
    cll.addAtEnd(30);
    cll.addAtEnd(40);
    cll.display();

    cll.addAtStart(5);
    cll.display();

    cll.deleteAtStart();
    cll.display();

    cll.deleteAtEnd();
    cll.display();

    return 0;
}
