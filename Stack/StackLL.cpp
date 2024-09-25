#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
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
