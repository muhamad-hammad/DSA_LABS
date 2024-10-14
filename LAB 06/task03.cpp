#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
    Node(string value) : data(value), next(NULL) {}
};

class Stack
{
    Node *top;

public:
    Stack() : top(NULL) {}

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(string c)
    {
        Node *temp = new Node(c);
        temp->next = top;
        top = temp;
    }

    string pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return "";
        }
        else
        {
            Node *temp = top;
            top = top->next;
            string popped = temp->data;
            delete temp;
            return popped;
        }
    }

    string peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return "";
        }
        else
        {
            return top->data;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
        }
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int length()
    {
        int count = 0;
        Node *temp = top;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int precedence(string op)
{
    if (op == "+" || op == "-")
        return 1;
    if (op == "*" || op == "/")
        return 2;
    if (op == "^")
        return 3;
    return 0;
}

bool isoperator(string op)
{
    return (op == "+" || op == "-" || op == "*" || op == "/" || op == "^");
}

string infixToPostfix(const string &infix)
{
    Stack st;
    string postfix;
    string number = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isdigit(c) || c == '.')
        {
            number += c;
        }
        else
        {
            if (!number.empty())
            {
                postfix += number + " ";
                number.clear();
            }

            if (c == '(')
            {
                st.push(string(1, c));
            }
            else if (c == ')')
            {
                while (!st.isEmpty() && st.peek() != "(")
                {
                    postfix += st.pop() + " ";
                }
                if (!st.isEmpty())
                {
                    st.pop();
                }
            }
            else if (isoperator(string(1, c)))
            {
                while (!st.isEmpty() && precedence(st.peek()) >= precedence(string(1, c)))
                {
                    postfix += st.pop() + " ";
                }
                st.push(string(1, c));
            }
        }
    }

    if (!number.empty())
    {
        postfix += number + " ";
    }

    while (!st.isEmpty())
    {
        postfix += st.pop() + " ";
    }

    return postfix;
}

int SolutionOfStack(string postfix)
{
    Stack st;
    string token = "";

    for (int i = 0; i < postfix.length(); i++)
    {
        char c = postfix[i];

        if (isdigit(c) || c == '.')
        {
            token += c;
        }
        else if (c == ' ' && !token.empty())
        {
            st.push(token);
            token.clear();
        }
        else if (isoperator(string(1, c)))
        {
            double operand1 = stod(st.pop());
            double operand2 = stod(st.pop());
            double result;

            if (c == '+') result = operand2 + operand1;
            else if (c == '-') result = operand2 - operand1;
            else if (c == '*') result = operand2 * operand1;
            else if (c == '/') result = operand2 / operand1;
            else if (c == '^') result = pow(operand2, operand1);

            st.push(to_string(result));
        }
    }

    return stoi(st.peek());
}

int main()
{
    string infix = "12+13-5*(0.5+0.5)+1";
    Stack st;

    st.push("x");
    st.push("=");
    st.push("12");
    st.push("+");
    st.push("13");
    st.push("-");
    st.push("5");
    st.push("(");
    st.push("0.5");
    st.push("+");
    st.push("0.5");
    st.push(")");
    st.push("+");
    st.push("1");

    cout << "Expression: ";
    st.display();

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    int result = SolutionOfStack(postfix);
    cout << "Result: " << result << endl;

    st.push(to_string(result));

    cout << "Final Stack: ";
    st.display();

    return 0;
}
