#include <iostream>

using namespace std;

class CircularQueue {
    int *arr;
    int rear, front, size;

public:
    CircularQueue(int size) {
        this->size = size;
        this->rear = this->front = 0;
        this->arr = new int[size];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot insert " << value << endl;
            return;
        }

        arr[rear] = value;
        rear = (rear + 1) % size;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot delete." << endl;
            return -1;
        }

        int value = arr[front];
        front = (front + 1) % size;
        return value;
    }
};

int main() {
    CircularQueue q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.enqueue(40);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.dequeue() << endl;

    return 0;
}
