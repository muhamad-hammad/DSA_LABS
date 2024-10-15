#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;
    
    Node(int data) {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class Doublyll {
public:
    Node *head;

    Doublyll() {
        head = NULL;
    }

    ~Doublyll() {
        while (head != NULL) {
            deleteAtStart();
        }
    }

    void addAtEnd(int data) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node *curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
    }

    void addAtStart(int data) {
        Node *newNode = new Node(data);
        newNode->next = head; 
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void addAtPos(int data, int key) {
        if (key < 1) {
            std::cout << "Invalid position" << endl;
            return;
        }
        if (key == 1) {
            addAtStart(data);
            return;
        }
        Node *newNode = new Node(data);
        int count = 1;
        Node *curr = head;
        while (count != key - 1 && curr != NULL) {
            curr = curr->next;
            count++;
        } 
        if (curr != NULL) {
            newNode->next = curr->next;
            newNode->prev = curr;
            if (curr->next != NULL) {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
        } else {
            std::cout << "Invalid Position" << endl;
            delete newNode; // Prevent memory leak
        }
    }

    void deleteAtStart() {
        if (head == NULL) {
            return;
        } else {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
        }
    }

    void deleteAtEnd() {
        if (head == NULL) {
            return;
        } else if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            Node *curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->prev->next = NULL;
            delete curr;
        }
    }

    void deleteAtPos(int key) {
        if (head == NULL) {
            return;
        }
        if (key == 1) {
            deleteAtStart();
            return;
        }
        Node* temp = head;
        int count = 1;
        while (count != key && temp != NULL) {
            temp = temp->next;
            count++;
        } 
        if (temp == NULL) {
            std::cout << "Invalid position" << endl;
            return;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    void swapNodes(Node* A, Node* B) {
        if (A == B || A == NULL || B == NULL) return;

        Node* prevA = A->prev;
        Node* prevB = B->prev;
        Node* nextA = A->next;
        Node* nextB = B->next;

        // Adjust the previous nodes' next pointers
        if (prevA != NULL) prevA->next = B;
        if (prevB != NULL) prevB->next = A;

        // Adjust the next nodes' prev pointers
        if (nextA != NULL) nextA->prev = B;
        if (nextB != NULL) nextB->prev = A;

        // Swap next pointers of A and B
        A->next = nextB;
        B->next = nextA;

        // Update the previous pointers of A and B
        A->prev = prevB;
        B->prev = prevA;

        // If A or B is the head, update head
        if (head == A) head = B;
        else if (head == B) head = A;
    }

    int findMax() {
        if (head == NULL) {
            std::cout << "The list is empty!" << endl;
            return 0; // Return INT_MIN instead of INT_MAX for max
        }
        Node* curr = head;
        int max = curr->data;
        while (curr != NULL) {
            if (curr->data > max) {
                max = curr->data;
            }
            curr = curr->next;
        }
        return max;
    }

    int findMin() {
        if (head == NULL) {
            std::cout << "The list is empty!" << endl;
            return 0;
        }
        Node* curr = head;
        int min = curr->data;
        while (curr != NULL) {
            if (curr->data < min) {
                min = curr->data;
            }
            curr = curr->next;
        }
        return min;
    }

    void display() {
        Node* curr = head;
        if (curr == NULL) {
            std::cout << "The list is empty!" << std::endl;
            return;
        }
        while (curr != NULL) {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
        std::cout << endl;
    }
};

Node* concatLinkedL(Doublyll *A, Doublyll *B) {
    if (A->head == NULL) return B->head;
    if (B->head == NULL) return A->head;

    Node* curr = A->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = B->head;
    B->head->prev = curr;
    return A->head;
}

int main() {
    Doublyll list1, list2;

    list1.addAtEnd(1);
    list1.addAtEnd(3);
    list1.addAtEnd(5);
    list1.addAtEnd(7);
    cout << "List 1: ";
    list1.display();

    list2.addAtEnd(2);
    list2.addAtEnd(4);
    list2.addAtEnd(6);
    cout << "List 2: ";
    list2.display();

    concatLinkedL(&list1, &list2);
    cout << "Concatenated List: ";
    list1.display();

    cout << "Max in List 1: " << list1.findMax() << endl;
    cout << "Min in List 1: " << list1.findMin() << endl;

    // Swapping second and fourth nodes in the concatenated list
    if (list1.head->next->next->next != NULL) {
        list1.swapNodes(list1.head->next, list1.head->next->next->next);
        cout << "List after swapping nodes: ";
        list1.display();
    } else {
        cout << "Cannot swap nodes: not enough nodes." << endl;
    }

    return 0;
}
