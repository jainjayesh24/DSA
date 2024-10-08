#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* root = NULL;
node* createNode(int data)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}


void preorderTraversal(node *node){
    if(node!=NULL){
        cout<<node->data<<" ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void inorderTraversal(node *node){
    if(node!=NULL){
        inorderTraversal(node->left);
        cout<<node->data<<" ";
        inorderTraversal(node->right);
    }
}

void postorderTraversal(node *node){
    if(node!=NULL){
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout<<node->data<<" ";
    }
}


int main(){
    root = createNode(5);
    root->left = createNode(7);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(6);
    root->right->left = createNode(1);
    root->right->right = createNode(9);

    cout<<"PreOrder Traversal = "<<endl;
    preorderTraversal(root);

    cout<<endl;



    cout<<"InOrder Traversal = "<<"\n";
    inorderTraversal(root);
    cout<<endl;

    cout<<"PostOrder Traversal = "<<"\n";
    postorderTraversal(root);


    return 0;
}