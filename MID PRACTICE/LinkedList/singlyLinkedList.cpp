#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = NULL;
    }

    ~Node(){
        delete next;
    }
};

class Singlyll {
    public:
    Node *head;

    Singlyll(){
        head = NULL;
    }

    ~Singlyll(){
        delete head;
    }

    void addAtEnd(int data){
        Node *newNode = new Node(data);
        if (head == NULL){
            head = newNode;
        } else {
            Node *curr = head;
            while (curr->next != NULL){
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void addAtStart(int data){
        Node *newNode = new Node(data);
        newNode->next = head; 
        head = newNode;
    }

    void addAtPos(int data, int key){
        if(key == 1){
            addAtStart(data);
            return;
        }
        Node *newNode = new Node(data);
        int count = 1;
        Node *curr = head;
        while (count != key-1 && curr!=NULL){
            curr = curr->next;
            count++;
        } 
        if (curr != NULL){
            newNode->next = curr->next;
            curr->next = newNode;
        } else {
            cout << "Invalid Position" << endl;
        }
    }

    void deleteAtStart(){
        if (head == NULL){
            return;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteAtEnd(){
        if(head == NULL){
            return;
        } else if(head->next == NULL){
            delete head;
            head = NULL;
        } else {
            Node *curr = head;
            Node *prev = NULL;
            while(curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            delete curr;
        }
    }

    void deleteAtpos(int key){
        Node* temp = head;
        Node* prev = NULL;
        
        if(head == NULL){
            return;
        }
        if(key == 1){
            deleteAtStart();
            return;
        }
        int count = 1;
        while(count != key && temp!=NULL){
            prev = temp;
            temp = temp->next;
            count++;
        } 
        if (temp != NULL){
            prev->next = temp->next;
            delete temp;
        } else {
            cout << "Invalid Position" << endl;
        }
    }

    void swapNodes(Node** headRef, Node* A, Node* B){
        if (A == B || A == NULL || B == NULL) return;
        
        Node* prevA = NULL, *prevB = NULL, *curr = *headRef;
        
        // Find previous nodes of A and B
        while (curr != NULL && curr->next != NULL) {
            if (curr->next == A) prevA = curr;
            if (curr->next == B) prevB = curr;
            curr = curr->next;
        }

        // If either A or B is not present
        if (prevA == NULL && *headRef != A) return;
        if (prevB == NULL && *headRef != B) return;

        // If A is the head
        if (*headRef == A) *headRef = B;
        else if (*headRef == B) *headRef = A;

        // Update the previous nodes' next pointers
        if (prevA != NULL) prevA->next = B;
        if (prevB != NULL) prevB->next = A;

        // Swap next pointers of A and B
        Node* temp = A->next;
        A->next = B->next;
        B->next = temp;
    }

    int findMax(){
        if(head == NULL){
            cout << "The list is empty!" << endl;
            return 0;
        }
        Node* curr = head;
        int max = curr->data;
        while(curr != NULL){
            if(curr->data > max){
                max = curr->data;
            }
            curr = curr->next;
        }
        return max;
    }

    int findMin(){
        if(head == NULL){
            cout << "The list is empty!" << endl;
            return 0;
        }
        Node* curr = head;
        int min = curr->data;
        while(curr != NULL){
            if(curr->data < min){
                min = curr->data;
            }
            curr = curr->next;
        }
        return min;
    }

    void display(){
        Node* curr = head;
        while(curr != NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

Node* concatLinkedL(Singlyll *A, Singlyll *B){
   if(A->head == NULL) return B->head;
   Node* curr = A->head;
   while (curr->next != NULL){
       curr = curr->next;
   }
   curr->next = B->head;
   return A->head;
}

int main(){
    Singlyll list1, list2;

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

    list1.swapNodes(&(list1.head), list1.head->next, list1.head->next->next->next);
    cout << "List after swapping nodes: ";
    list1.display();

    return 0;
}
