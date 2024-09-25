#include <iostream>
using namespace std;

class Stack {
    int top;
    int arr[5];

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 4) {
            cout << "Stack is full" << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << endl;
    cout << s.peek() << endl;

    return 0;
}
