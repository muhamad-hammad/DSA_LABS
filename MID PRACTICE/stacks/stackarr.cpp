#include<iostream>
using namespace std;

class Stack {
public:
    int *arr;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int e) {
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

    int peek() {
        if (top >= 0)
            return arr[top];
        else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isempty() {
        return top == -1;
    }

    int getMin() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int minVal = arr[0];  // Initialize min with the first element
        for (int i = 1; i <= top; i++) {
            if (arr[i] < minVal)
                minVal = arr[i];
        }
        return minVal;
    }

    int getMax() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int maxVal = arr[0];  // Initialize max with the first element
        for (int i = 1; i <= top; i++) {
            if (arr[i] > maxVal)
                maxVal = arr[i];
        }
        return maxVal;
    }

    int sum() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return 0;
        }
        int total = 0;
        for (int i = 0; i <= top; i++) {
            total += arr[i];
        }
        return total;
    }
};

int main() {
    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);

    if (st.isempty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    cout << "Top Element: " << st.peek() << endl;
    st.pop();
    cout << "Top Element: " << st.peek() << endl;
    st.pop();
    cout << "Top Element: " << st.peek() << endl;
    st.pop();

    if (st.isempty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    // Push some elements to test min, max, and sum functions
    st.push(5);
    st.push(10);
    st.push(20);
    st.push(0);
    st.push(-5);

    cout << "Minimum Element: " << st.getMin() << endl;
    cout << "Maximum Element: " << st.getMax() << endl;
    cout << "Sum of Elements: " << st.sum() << endl;

    return 0;
}
