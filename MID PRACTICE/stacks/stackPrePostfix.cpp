#include <iostream>
#include <string>
#include <cctype> // Include for isalnum
using namespace std;

class Stack {
    int top;
    int capacity;
    char *arr;

public:
    Stack(int size) {
        top = -1;
        capacity = size;
        arr = new char[capacity];
    }
   
    ~Stack() {
        delete[] arr;
    }
   
    void push(char el) {
        if (top == capacity - 1) {
            cout << "Stack overflow" << endl;
            return; // Ensure we return after the overflow message
        }
        arr[++top] = el; // Move this line inside the if statement
    }

    char pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl; // Add a newline for better readability
            return '\0';
        }
        return arr[top--];
    }
   
    char peek() {
        if (top == -1) {
            return '\0';
        }
        return arr[top];
    }
   
    bool isEmpty() {
        return (top < 0);
    }
};

int precedence(char op) { // Corrected function name from "precendence"
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0; // Added return for undefined operators
}

bool isOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^'); // Added '^' to operators
}

string infixToPostfix(const string &infix) {
    Stack st(infix.length());
    string postfix;
   
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
       
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop(); // Pop the '('
        } else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c)) {
                postfix += st.pop();
            }
            st.push(c); // Push the current operator to the stack
        }
    }
   
    while (!st.isEmpty()) { // Pop remaining operators from the stack
        postfix += st.pop();
    }
   
    return postfix; // Return the postfix expression
}

int main() {
    string infix = "A+B*(C^D-E)";
    cout << "Infix expression: " << infix << endl;
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;

    return 0; // Added return statement to main
}

