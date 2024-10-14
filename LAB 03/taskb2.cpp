// Give an efficient algorithm for concatenating two doubly linked lists L and M, with head and tail
// preserved nodes, into a single list that contains all the nodes of L followed by all the nodes of M.
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
    friend DoublyLL concat(DoublyLL *one, DoublyLL *two);
};
DoublyLL concat(DoublyLL *one, DoublyLL *two)
{
    DoublyLL result;
    if (one->head == NULL)
    {
        result.head = two->head;
        result.tail = two->tail;
        return result;
    }
    if (two->head == NULL)
    {
        result.head = one->head;
        result.tail = one->tail;
        return result;
    }

    one->tail->next = two->head;
    two->head->prev = one->tail;
    result.head = one->head;
    result.tail = two->tail;

    return result;
}
int main()
{
    DoublyLL *one = new DoublyLL();
    DoublyLL *two = new DoublyLL();
    cout << "Initiaize First List" << endl;
    one->initialize();
    cout << " First List" << endl;
    one->display();
    cout << "Initiaize Second List" << endl;
    two->initialize();
    cout << " Second List" << endl;
    two->display();

    DoublyLL concatenatedList = concat(one, two);
    cout << "Concatenated List: ";
    concatenatedList.display();

    delete one;
    delete two;
    return 0;
}