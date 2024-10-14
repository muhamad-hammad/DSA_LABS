#include<iostream>
using namespace std;

class Stack {
public:
    char *arr;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        arr = new char[size];
        top = -1;
    }

    void push(char e) {
        if (size - top > 1) {
            top++;
            arr[top] = e;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "Stack Underflow" << endl;
        }
    }

    char peek() {
        if (top >= 0)
            return arr[top];
        else {
            cout << "Stack is Empty" << endl;
            return '\0';
        }
    }

    bool isempty() {
        return top == '\0';
    }

    bool isAPalindrome() {
        Stack temp(size);
        for(int i = 0; i < size; i++) {
            temp.push(arr[i]);
        }
        for (int i = 0; i < size; i++) {
            if (arr[i] != temp.peek()) {
                return false;
            }
            temp.pop();
        }
    }
};

int main() {
    // cout << "Enter a string: " << endl;
    // string s;
    // cin >> s;
    string s = "BORROWROB";
    Stack st(s.length());
    for (int i = 0; i < s.length(); i++) {
        st.push(s[i]);
    }
    if (st.isAPalindrome()) {
        cout << "The string " << s << "is a palindrome" << endl;
    } else {
        cout << "The string " << s << "is not a palindrome" << endl;
    }
    
    return 0;
}
