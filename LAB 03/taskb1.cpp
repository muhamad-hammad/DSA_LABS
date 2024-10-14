
// 1. Create a Double link list and perform the mentioned tasks:
// i. Insert a new node at the end of the list.
// ii. Insert a new node at the beginning of list.
// iii. Insert a new node at given position.
// iv. Delete any node.
// v. Print the complete circular double link list.

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
        next = prev = NULL;
    }
};

class circularDoublyLL
{
private:
    Node *head;

public:
    circularDoublyLL()
    {
        head = NULL;
    }

    ~circularDoublyLL()
    {
        if (head == NULL)
            return;

        Node *current = head;
        do
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }

    void insertAtBegining(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void insertAtpos(int data, int pos)
    {
        if (pos < 0)
            return;

        Node *newNode = new Node(data);
        if (pos == 0)
        {
            insertAtBegining(data);
            return;
        }

        Node *current = head;
        int currentPos = 0;
        do
        {
            if (currentPos == pos - 1)
                break;
            current = current->next;
            currentPos++;
        } while (current != head);

        if (current == head->prev)
        { // Insertion at the end
            insertAtEnd(data);
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    void deleteNode(int data)
    {
        if (head == NULL)
            return;

        Node *current = head;
        do
        {
            if (current->data == data)
            {
                if (current == head)
                {
                    if (head->next == head)
                    { // Only one node in the list
                        delete head;
                        head = NULL;
                        return;
                    }
                    else
                    {
                        Node *tail = head->prev;
                        head = head->next;
                        tail->next = head;
                        head->prev = tail;
                        delete current;
                        return;
                    }
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    return;
                }
            }
            current = current->next;
        } while (current != head);
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;
        cout << "Circular Doubly Linked List: ";
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main()
{
    circularDoublyLL list;
    cout << "Enter the number of elements you want to insert: ";
    int n;
    cin >> n;
    int data;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data for node " << i + 1 << ": ";
        cin >> data;
        list.insertAtEnd(data);
    }

    list.display();

    // i. Insert a new node at the end of the list.
    list.insertAtEnd(9);
    cout << "After inserting at the end:" << endl;
    list.display();

    // ii. Insert a new node at the beginning of list.
    list.insertAtBegining(0);
    cout << "After inserting at the beginning:" << endl;
    list.display();

    // iii. Insert a new node at a given position.
    list.insertAtpos(6, 6);
    cout << "After inserting at a position:" << endl;
    list.display();

    // iv. Delete any node.
    list.deleteNode(0);
    cout << "After deleting a node:" << endl;
    list.display();

    // v. Print the complete circular double linked list.
    cout << "Final list:" << endl;
    list.display();

    return 0;
}
