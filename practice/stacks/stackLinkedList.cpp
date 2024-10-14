#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
    Node* top;
public:
    Stack() : top(nullptr) {}

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int a)
    {
        Node* temp = new Node(a);
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "LinkedList is Empty !";
            return;
        }
        else 
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "LinkedList is Empty !";
            return -111; // error value
        }
        else 
            return top->data;
    }

    int findMax(){
        if(isEmpty()){
            cout << "LinkedList is Empty !";
            return -111; // error value
        }
        else{
            int max = top->data;
            Node* temp = top;
            while (temp != nullptr)
            {
                if (temp->data > max)
                    max = temp->data;
                temp = temp->next;
            }
            return max;
        }
    }

    int findMin(){
        if(isEmpty()){
            cout << "LinkedList is Empty !";
            return -111; // error value
        }
        else{
            int min = top->data;
            Node* temp = top;
            while (temp != nullptr)
            {
                if (temp->data < min)
                    min = temp->data;
                temp = temp->next;
            }
            return min;
        }
    }

    void addStack(Stack& s2){
        if (s2.isEmpty())
        {
            cout << "LinkedList is Empty !";
            return;
        }
        else
        {
            Node* temp = top;
            while (temp != nullptr)
            {
                s2.push(temp->data);
                temp = temp->next;
            }
        }
    }

    void display()
    {
        if (isEmpty())
            cout << "LinkedList is empty";
        Node* temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};