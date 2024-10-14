// 4. Given a linked list (input by user), you have to perform the following task:

// i. Extract the alternative nodes starting from second node.
// ii. Reverse the extracted list.
// iii. Append the extracted list at the end of the original list.
// Note: Try to solve the problem without using any extra memory.
// Example:
// Input:
// LinkedList = 10->4->9->1->3->5->9->4
// Output:
// 10 9 3 9 4 5 1 4
// Explanation:
// Alternative nodes in the given linked list are 4,1,5,4. Reversing the alternative nodes from the given list,
// and then appending them to the end of the list results in a list 10->9->3->9->4->5->1->4.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLL
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLL()
    {
        head = NULL;
        tail = NULL;
    }
    ~DoublyLL()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    void insertAtBegining(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else if (head != NULL)
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtpos(int data, int pos)
    {
        if (pos < 0)
        {
            return;
        }

        Node *newNode = new Node(data);
        if (pos == 0)
        {
            insertAtBegining(data);
            return;
        }
        Node *current = head;
        int currentPos = 0;
        while (currentPos < pos - 1 && current != NULL)
        {
            current = current->next;
            currentPos++;
        }
        if (current == NULL)
            return;
        newNode->next = current->next;

        if (current->next != NULL)
        {
            current->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void initialize()
    {
        cout << "Enter the number of elements you want to initialize the linked list with: " << endl;
        int n, d;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "For Node : " << i << "Enter the element: " << endl;
            cin >> d;
            insertAtEnd(d);
        }
    }

    void deleteNode(int data)
    {
        if (head == NULL)
        {
            return;
        }
        if (head->data == data)
        {
            Node *temp = head;
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            else
            {
                tail = NULL;
            }
            delete temp;
            return;
        }
        Node *current = head;
        while (current != NULL && current->data != data)
        {
            current = current->next;
        }
        if (current == NULL)
        {
            cout << "Bode not found" << endl;
            return;
        }
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
        else
        {
            tail = current->prev;
        }
        current->prev->next = current->next;
        delete current;
    }
    
void function() {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node* curr = head->next;
    Node* prev = head;
    Node* last = tail;
    Node* end = NULL;

    while (curr != NULL) {
        prev->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = prev;
        } else {
            tail = prev;
        }

        Node* next = curr->next;
        curr->next = end;
        if (end != NULL) {
            end->prev = curr;
        }
        curr->prev = NULL;
        end = curr;
        
        curr = next ? next->next : NULL;
    }

    if (end != NULL) {
        last->next = end;
        end->prev = last;
    }
}

    void display()
    {
        Node *current = head;
        cout << "Doubly linked list" << endl;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLL *one = new DoublyLL();
    cout << "Initiaize  List" << endl;
    one->initialize();
    one->display();
    one->function();
    cout << "After functions" << endl;
    one->display();

    delete one;
    return 0;
}