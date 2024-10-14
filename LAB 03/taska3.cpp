// 3. Create a circular link list and perform the mentioned tasks:
// i. Insert a new node at the end of the list.
// ii. Insert a new node at the beginning of list.
// iii. Insert a new node at given position.
// iv. Delete any node.
// v. Print the complete circular link list.

#include<iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int data){
        this->data = data;
        next = NULL;
    };
    friend class CircularList;
};

class CircularList{
    private:
    Node *head;
    Node *tail;
    int size;
    public:
    CircularList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void initialize(int data){
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail->next = head;
        size++;
    }

    void addAtEnd(int data){
        Node *newNode = new Node(data);
        if(head == NULL){
            initialize(data);
        }
        else{
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
            size++;
        }
    }

    void addAtBeginning(int data){
        Node *newNode = new Node(data);
        if(head == NULL){
            initialize(data);
        }
        else{
            newNode->next = head;
            head = newNode;
            tail->next = head;
            size++;
        }
    }

    void addAtPosition(int data, int position){
        Node *newNode = new Node(data);
        if(head == NULL){
            initialize(data);
        }
        else{
            Node *temp = head;
            int count = 0;
            while(count < position-1){
                temp = temp->next;
                count++;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }

    void deleteNode(int data){
        Node *temp = head;
        Node *prev = NULL;
        if(head == NULL){
            cout << "List is empty" << endl;
        }
        else{
            while(temp->data != data){
                prev = temp;
                temp = temp->next;
            }
            if(temp == head){
                head = head->next;
                tail->next = head;
                delete temp;
            }
            else{
                prev->next = temp->next;
                delete temp;
            }
            size--;
        }
    }

    void deleteNodeAtPosition(int position){
        Node *temp = head;
        Node *prev = NULL;
        if(head == NULL){
            cout << "List is empty" << endl;
        }
        else{
            int count = 0;
            while(count < position-1){
                prev = temp;
                temp = temp->next;
                count++;
            }
            if(temp == head){
                head = head->next;
                tail->next = head;
                delete temp;
            }
            else{
                prev->next = temp->next;
                delete temp;
            }
            size--;
        }
    }

    void printList(){
        Node *temp = head;
        if(head == NULL){
            cout << "List is empty" << endl;
        }
        else{
            do{
                cout << temp->data << " ";
                temp = temp->next;
            }while(temp != head);
            cout << endl;
        }
    }

};

void flagChecker(int choice){
    cout << "Do you want to end the task" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cin >> choice;
    if(choice == 1){
        exit(0);}
}

int main(){
    CircularList list;
    int nu;
    cout << "Enter the number of elements you want to initialize : " << endl;
    cin >> nu;
    int data;
    for (int i = 0; i < nu; i++)
    {   
        cout << "Enter the element : " << "for node: " << i << endl;
        cin >> data;
        if (i == 0){
            list.initialize(data);
        }
        else{
            list.addAtEnd(data);
        }
    }
    list.printList();
    int choice;
    list.addAtEnd(data);
    list.printList();
    list.addAtBeginning(data);
    list.printList();
    list.addAtPosition(data, 2);
    list.printList();
    list.deleteNode(data);
    list.printList();
    list.deleteNodeAtPosition(2);
    list.printList();

/*
    I dont know why i mad this functionality while it was unneccessary

    bool flag = 1;
    while(flag){
        
        cout << "Enter the operation you want to perform : " << endl;
        cout << "1. Add at end" << endl;
        cout << "2. Add at beginning" << endl;
        cout << "3. Add at position" << endl;
        cout << "4. Delete node" << endl;
        cout << "5. Delete node at position" << endl;
        cout << "6. Print list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice : " << endl;
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the element you want to add at end: " << endl;
                cin >> data;
                list.addAtEnd(data);
                cout << "End the program? , 0. for yes, 1. for no" << endl;
                cin >> flag;
                break;
            case 2:
                cout << "Enter the element you want to add at beginning: " << endl;
                cin >> data;
                list.addAtBeginning(data);
                cout << "End the program? , 0. for yes, 1. for no" << endl;
                cin >> flag;
                break;
            case 3:
                cout << "Enter the element you want to add: at some position" << endl;
                cin >> data;
                int position;
                cout << "Enter the position: " << endl;
                cin >> position;
                list.addAtPosition(data, position);
                cout << "End the program? , 0. for yes, 1. for no" << endl;
                cin >> flag;
                break;
            case 4:
                cout << "Enter the element you want to delete: " << endl;
                cin >> data;
                list.deleteNode(data);
                cout << "End the program? , 0. for yes, 1. for no" << endl;
                cin >> flag;
                break;
            case 5:
                cout << "Enter the position you want to delete: " << endl;
                cin >> position;
                list.deleteNodeAtPosition(position);
                cout << "End the program? , 0. for yes, 1. for no" << endl;
                cin >> flag;
                break;
            case 6:
            list.printList();
                cout << "End the program? , 0. for yes, 1. for no" << endl;
                cin >> flag;
            break;
            case 7:
            exit(0);
                cout << "End the program? , 0. for yes, 1. for no" << endl;
                cin >> flag;
            break;
        }
}
*/
}