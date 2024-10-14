#include<iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;
    Node(int d = 0) {
        data = d;
        next = NULL;
    }
};

class SLL {
public:
    Node* head;
    SLL() {
        head = NULL;
    }

    void initLL(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void searchData(Node* n, int d) {
        if (n == NULL) {
            cout << "Data: " << d << " Not found" << endl;
            return;
        } else if (n->data == d) {
            cout << "Data: " << d << " Found" << endl;
            return;
        } else {
            searchData(n->next, d);
        }
    }

    void searchData(int d) {
        searchData(head, d);
    }
};

int main() {
    SLL linkedlist;
    int n;
    cout << "Enter the number of elements you want to keep in the linked list: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter the data for the node: ";
        cin >> data;
        linkedlist.initLL(data);
    }

    int data;
    cout << "Enter the data you want to search: ";
    cin >> data;
    linkedlist.searchData(data);

    Node* curr = linkedlist.head;
    while (curr != NULL) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}
