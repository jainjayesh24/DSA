#include<iostream>
#include<cstdio>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* head = NULL;

void insertAtbeg(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    if(head == NULL){
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    newnode->prev = NULL;
    newnode->next = head;
    head->prev = newnode; 
    head = newnode;
}


void insertAtEnd(int data){
    node* temp;
    temp = head;
    node* newnode = (node*)malloc(sizeof(node));
    if(temp==NULL){
        temp->data=data;
        newnode->next = NULL;
        newnode->prev = NULL;
        head = newnode;
    }
    newnode->data = data;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
}

void insertmid(int data,int pos){
    node* temp;
    temp = head;
    node* newnode = (node*)malloc(sizeof(node));
    int count = 1;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL){
        head = newnode;
        return;
    }
    if(temp->next == NULL){
        temp->next = newnode;
        newnode->prev = temp;
    }
    while(count<pos-1){
        count++;
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    newnode->next->prev = newnode;
    temp->next = newnode;
}

void deleteBeg(){
    node* temp = head;
    if (temp == NULL){
        head = NULL;
        cout<<"list is Empty";
    }
    if(temp->next = NULL){
        head = NULL;
        free(temp);
        return;
    }
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    free(temp);
}

void deleteEnd(){
    node* temp = head;
    if(temp = nullptr){
        cout<<"Linked list is empty"<<endl;
        return;
    }if(temp->next == NULL){
        head = NULL;
        free(temp);
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    node* temp1 = temp->next;
    temp1->prev = NULL;
    temp->next = NULL;
    free(temp1);
}
void deletemid(int pos){
    node* temp = head;
    int count =1;
    while(count<pos-1){
        count++;
        temp = temp->next;
    }
    node* temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp;
    temp1->next = NULL;
    temp1->prev = NULL;
    free(temp1);
}
void display(){
    node* temp;
    temp = head;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp =  temp->next;
    }
}
int main() {
    insertAtbeg(10);
    insertAtbeg(20);
    insertAtbeg(30);
    cout << "List after inserting at the beginning: ";
    display();
    cout << endl;

    insertAtEnd(40);
    insertAtEnd(50);
    cout << "List after inserting at the end: ";
    display();
    cout << endl;

    insertmid(25, 3); 
    cout << "List after inserting 25 at position 3: ";
    display();
    cout << endl;

    deleteBeg();
    cout << "List after deleting from the beginning: ";
    display();
    cout << endl;

    deleteEnd();
    cout << "List after deleting from the end: ";
    display();
    cout << endl;

    deletemid(2); 
    cout << "List after deleting from position 2: ";
    display();
    cout << endl;

    return 0;
}

