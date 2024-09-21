#include<iostream>
#include<cstdio>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node* createlist(struct node* head) {
    struct node *newNode, *temp;
    for (int i = 1; i <= 5; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory is full");
            return head;
        }
        newNode->data = i;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* insertAtBeg(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}
struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
struct node* insertAtPos(struct node* head, int data, int pos) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position is out of range\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
struct node* deleteAtBeg(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* deleteAtEnd(struct node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}
struct node* deleteAtPos(struct node* head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (pos == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Position is out of range\n");
        return head;
    }
    struct node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    free(deleteNode);
    return head;
}

int main() {
    struct node* head = NULL;
    head = createlist(head);
    printf("Initial list: ");
    printList(head);

    head = insertAtBeg(head, 0);
    printf("After inserting 0 at beginning: ");
    printList(head);

    head = insertAtEnd(head, 6);
    printf("After inserting 6 at end: ");
    printList(head);

    head = insertAtPos(head, 99, 3);
    printf("After inserting 99 at position 3: ");
    printList(head);

    head = deleteAtBeg(head);
    printf("After deleting from beginning: ");
    printList(head);

    head = deleteAtEnd(head);
    printf("After deleting from end: ");
    printList(head);

    head = deleteAtPos(head, 3);
    printf("After deleting from position 3: ");
    printList(head);

    return 0;
}
