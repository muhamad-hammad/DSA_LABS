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
        prev = NULL;
        next = NULL;
    }
};

class CircularDoublyll
{
public:
    Node *head;
    Node *tail;

    CircularDoublyll()
    {
        head = NULL;
        tail = NULL;
    }

    ~CircularDoublyll()
    {
        while (head != NULL)
        {
            deleteAtStart();
        }
    }

    void addAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void addAtStart(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else
        {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }

    void addAtPos(int data, int key)
    {
        if (key < 1)
        {
            std::cout << "Invalid position" << endl;
            return;
        }
        if (key == 1)
        {
            addAtStart(data);
            return;
        }
        Node *newNode = new Node(data);
        Node *curr = head;
        int count = 1;

        while (count < key - 1 && curr->next != head)
        {
            curr = curr->next;
            count++;
        }

        if (curr != NULL)
        {
            newNode->next = curr->next;
            newNode->prev = curr;
            curr->next->prev = newNode; // Update the next node's prev pointer
            curr->next = newNode;
            if (newNode->next == head)
            { // Update tail if inserting at the end
                tail = newNode;
            }
        }
        else
        {
            std::cout << "Invalid Position" << endl;
            delete newNode; // Prevent memory leak
        }
    }

    void deleteAtStart()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            tail->next = head;
            head->prev = tail;
        }
        delete temp;
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            return;
        }
        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }

    void deleteAtPos(int key)
    {
        if (head == NULL)
        {
            return;
        }
        if (key == 1)
        {
            deleteAtStart();
            return;
        }
        Node *temp = head;
        int count = 1;

        while (count != key && temp->next != head)
        {
            temp = temp->next;
            count++;
        }

        if (temp == NULL || count != key)
        {
            std::cout << "Invalid position" << endl;
            return;
        }

        if (temp == tail)
        {
            deleteAtEnd();
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    void swapNodes(Node *A, Node *B)
    {
        if (A == B || A == NULL || B == NULL)
            return;

        Node *prevA = A->prev;
        Node *prevB = B->prev;

        // Adjust the previous nodes' next pointers
        if (prevA != NULL)
            prevA->next = B;
        if (prevB != NULL)
            prevB->next = A;

        // Adjust the next nodes' prev pointers
        A->next->prev = B;
        B->next->prev = A;

        // Swap next pointers of A and B
        Node *temp = A->next;
        A->next = B->next;
        B->next = temp;

        // Update the previous pointers of A and B
        A->prev = prevB;
        B->prev = prevA;

        // If A or B is the head, update head
        if (head == A)
            head = B;
        else if (head == B)
            head = A;
    }

    int findMax()
    {
        if (head == NULL)
        {
            std::cout << "The list is empty!" << endl;
            return 0; // Return 0 for max
        }
        Node *curr = head;
        int max = curr->data;
        do
        {
            if (curr->data > max)
            {
                max = curr->data;
            }
            curr = curr->next;
        } while (curr != head);
        return max;
    }

    int findMin()
    {
        if (head == NULL)
        {
            std::cout << "The list is empty!" << endl;
            return 0;
        }
        Node *curr = head;
        int min = curr->data;
        do
        {
            if (curr->data < min)
            {
                min = curr->data;
            }
            curr = curr->next;
        } while (curr != head);
        return min;
    }

    void display()
    {
        Node *curr = head;
        if (curr == NULL)
        {
            std::cout << "The list is empty!" << std::endl;
            return;
        }
        do
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        std::cout << endl;
    }
};

Node *concatLinkedL(CircularDoublyll *A, CircularDoublyll *B)
{
    if (A->head == NULL)
        return B->head;
    if (B->head == NULL)
        return A->head;

    Node *curr = A->head;
    do
    {
        curr = curr->next;
    } while (curr != A->head);

    curr->next = B->head;
    B->head->prev = curr;
    B->tail->next = A->head;
    A->head->prev = B->tail;
    return A->head;
}

int main()
{
    CircularDoublyll list1, list2;

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
    if (list1.head->next->next->next != NULL)
    {
        list1.swapNodes(list1.head->next, list1.head->next->next->next);
        cout << "List after swapping nodes: ";
        list1.display();
    }
    else
    {
        cout << "Cannot swap nodes: not enough nodes." << endl;
    }

    return 0;
}
