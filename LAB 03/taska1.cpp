#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
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

    
    void initializeLL(int data) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void modifyLL() {
        if (head == NULL || head->next == NULL)
            return;

        Node *current = head;
        Node *prev = NULL;

        while (current != NULL) {
            if (current->data % 2 == 0) {
                if (current == head) {
                    prev = current;
                    current = current->next;
                    continue; 
                }

                if (prev != NULL)
                    prev->next = current->next;

                Node *evenNode = current;
                current = current->next;

                evenNode->next = head;
                head = evenNode;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }

    void display() {
        Node *current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    singlyLL LL1;
    cout << "Enter the number of elements you want to enter: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cout << "For Node no : " << i << " Enter the data: ";
        cin >> data;
        LL1.initializeLL(data);
    }
    cout << "Original List: ";
    LL1.display();
    LL1.modifyLL();
    cout << "Modified List: ";
    LL1.display();
    return 0;
}
