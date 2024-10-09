#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef struct node {
    int data;
    node* left;
    node* right;
} node;

node* createNode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

node* insert(node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void levelOrderTraversal(node* root) {
    if (root == NULL) return;

    queue<node*> q;  
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        cout << current->data << " "; 
        q.pop();

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

int main() {
    node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 9);
    root = insert(root, 100);
    root = insert(root, 7);
    root = insert(root, 20);
    root = insert(root, 12);

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root); 

    return 0;
}
