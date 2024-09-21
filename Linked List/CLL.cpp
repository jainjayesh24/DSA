#include<iostream>
#include<cstdio>

using namespace std;

typedef struct node {
    int data;
    struct node* next;
} node;

node* head = NULL;
node* tail = NULL;

void insertBeg(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        newnode->next = head;
    } else {
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
}

void insertEnd(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        newnode->next = head;
    } else {
        tail->next = newnode;
        tail = newnode;
        newnode->next = head;
    }
}

void insertmid(int data, int pos) {
    node* newnode = (node*)malloc(sizeof(node));
    node* temp = head;
    newnode->data = data;
    newnode->next = NULL;
    int count = 1;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
        newnode->next = head;
        return;
    }

    while (temp->next != head && count < pos) {
        count++;
        temp = temp->next;
    }

    if (temp->next == head) {
        tail->next = newnode;
        tail = newnode;
        newnode->next = head;
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deletebeg() {
    node* temp = head;
    if (temp == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head == tail) {
        free(head);
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        tail->next = head;
        free(temp);
    }
}

void deletEnd() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head == tail) {
        free(head);
        head = NULL;
        tail = NULL;
    } else {
        node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = head;
        free(tail);
        tail = temp;
    }
}

void display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    insertBeg(3);
    insertBeg(2);
    insertBeg(1);
    display();

    insertEnd(4);
    insertEnd(5);
    display();

    insertmid(99, 3);
    display();

    deletebeg();
    display();

    deletEnd();
    display();

    return 0;
}
