// Given a Double Circular Linked List 1-7-4-2-6-4-5-3-9-8 (You can take your own list as input as well).
// Your task is to swap the nodes (not values) given their indexes along with its previous and next pointers.
// Input: Enter two nodes keys = 3 7
// Output:
// Initial Linked List = 1-7-4-2-6-4-5-3-9-8
// After Swapping = 1-7-4-3-6-4-5-2-9-8

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
        Node *current = head;
        while (current != NULL)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            head->prev = newNode;
        }
        else
        {
            Node *current = head->prev;
            current->next = newNode;
            newNode->next = head;
            newNode->prev = current;
            head->prev = newNode;
        }
    }
    void swapNodes(int key1, int key2)
    {
        if (head == NULL || key1 == key2)
            return;

        Node *node1 = NULL;
        Node *node2 = NULL;
        Node *current = head;
        do
        {
            if (current->data == key1)
                node1 = current;
            if (current->data == key2)
                node2 = current;
            current = current->next;
        } while (current != head);
        if (node1 && node2)
        {
            Node *tempPrev = node1->prev;
            node1->prev = node2->prev;
            node2->prev = tempPrev;

            Node *tempNext = node1->next;
            node1->next = node2->next;
            node2->next = tempNext;

            if (node1->next != NULL)
                node1->next->prev = node1;
            if (node1->prev != NULL)
                node1->prev->next = node1;
            if (node2->next != NULL)
                node2->next->prev = node2;
            if (node2->prev != NULL)
                node2->prev->next = node2;

            if (head == node1)
                head = node2;
            else if (head == node2)
                head = node1;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node *current = head;
        cout << "Circular Doubly linked list: ";
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

    cout << "Before Swapping: ";
    list.display();

    cout << "Enter the data for node to be swapped: ";
    int key1, key2;
    cout << "Enter the first key: ";
    cin >> key1;
    cout << "Enter the second key: ";
    cin >> key2;
    list.swapNodes(key1, key2);
    cout << "After swapping" << endl;
    list.display();
}