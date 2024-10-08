#include<iostream>
#include<cstdlib>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


class BinaryTree{
public:
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


};



int main(){
    BinaryTree bt;
    node *root = NULL;
    root = new node(5);
    root->left = new node(7);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->right->left = new node(1);
    root->right->right = new node(9);

    cout<<"PreOrder Traversal = "<<"\n";
    bt.preorderTraversal(root);

    cout<<endl;
    cout<<"InOrder Traversal = "<<"\n";
    bt.inorderTraversal(root);

    cout<<endl;

    cout<<"PostOrder Traversal = "<<"\n";
    bt.postorderTraversal(root);
    return 0;
}
