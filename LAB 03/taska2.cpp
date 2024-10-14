// Solve the following problem using a Singly Linked List:
// Given a Linked List (input by user) of integers or string (as per your choice), write a function to check if
// the entirety of the linked list is a palindrome or not.
// Examples:

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    string sdata;
    Node *next;
    Node(int data) {
        this->data = data;
        next = NULL;
    };
    Node(string sdata) {
        this->sdata = sdata;
        next = NULL;
    };
};

class singlyLL {
private:
    Node *head;

public:
    singlyLL() {
        head = NULL;
    }

    ~singlyLL() {
        Node *current = head;
        while (current != NULL) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void insert(int data) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insert(string sdata) {
        Node *newNode = new Node(sdata);
        if (head == NULL) {
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void isaPalindrome() {
        Node *current = head;
        int count = 0;
        
        while (current != NULL) {
            count++;
            current = current->next;
        }

        int *arr = new int[count];

        current = head;
        for (int i = 0; i < count; i++) {
            arr[i] = current->data;
            current = current->next;
        }

        for (int i = 0; i < count / 2; i++) {
            if (arr[i] != arr[count - i - 1]) {
                cout << "Not a palindrome" << endl;
                delete[] arr;
                return;
            }
        }

        cout << "Palindrome" << endl;
        delete[] arr;
    }

    void displayString(string sdata) {
        Node *current = head;
        while (current != NULL) {
            cout << current->sdata << " ";
            current = current->next;
        }
        cout << endl;
    }

    void display(int data) {
        Node *current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }


};

    int main() {
    singlyLL list;
    int choice;
    int data;
    string sdata;

    do {
        cout << "Enter your choice:" << endl;
        cout << "1. Insert a string" << endl;
        cout << "2. Insert an integer" << endl;
        cout << "3. Check if the list is a palindrome" << endl;
        cout << "4. Display the list" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a string: ";
                cin >> sdata;
                list.insert(sdata);
                break;
            case 2:
                cout << "Enter an integer: ";
                cin >> data;
                list.insert(data);
                break;
            case 3:
                list.isaPalindrome();
                break;
            case 4:
                bool flag;
                do {
                    cout << "Enter 1 to display the list of strings or 0 to display the list of integers: ";
                cin >> flag;
                if (flag == 1) {
                    list.displayString(sdata);
                    break;
                } else if (flag == 0) {
                    list.display(data);
                    break;
                } else {
                    cout << "incorrect choice: " << endl;
                }

                } while (flag != 1 || flag!= 0);
            case 5:
                cout << "Exiting..." << endl;
            break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    while (choice != 5);
    return 0;
    }
                
