#include <iostream>

using namespace std;

class Queue {
    int front, rear, size;
    int *arr;
    int capacity;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        this->front = this->rear = 0;
        this->size = 0;
        this->arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue is full! Cannot insert " << value << endl;
        } else {
            arr[rear] = value;
            rear = (rear + 1) % capacity;
            size++;
        }
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty! Cannot delete." << endl;
            return -1;
        } else {
            int value = arr[front];
            front = (front + 1) % capacity;
            size--;
            return value;
        }
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    Queue q(3);

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
