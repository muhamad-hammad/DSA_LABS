#include<iostream>
using namespace std;

class Node {
public:
    Node* next;
    int data;
    Node(int d=0) {
        next = NULL;
        data = d;
    }
};

class SLL{
    public:
    Node* head;
    SLL(){
        head = NULL;
    };
    ~SLL(){
        Node* temp = head;
        while(temp != NULL){
            Node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }
    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void initLinkedlist( int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }else {
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    int findLength(Node* node, int count = 0) const {
        if(node == NULL){
            return count;
        }else {
            return findLength(node->next, count+1);
        }
    }

    int getlength() const{
        return findLength(head);
    }
};

int main(){
    cout << "Enter the number of elements you wana keep: " << endl;
    int n;
    cin >> n;
    SLL linkedList;
    int data;
    for(int i = 0; i < n; i++){
        cout << "Enter data for " << i+1 << "Node : " << endl;
        cin >> data;
        linkedList.initLinkedlist(data);
    }
    cout << "Length of linked list is: " << linkedList.getlength() << endl;
    return 0;
}