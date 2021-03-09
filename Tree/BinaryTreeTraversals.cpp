/** 
 * InOrder: - Left Root Right
 * PreOrder - Root Left Right
 * PostOrder - Left Right Root
*/


#include<iostream>
using namespace std;

typedef struct node {
    int data;
    struct node *left, *right;
}Node;

Node* create () {
    int x;
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    cout<<"Enter data (-1 for no node): ";
    cin>>x;
    if(x == -1)
        return NULL;
    newNode->data = x;
    
    //left child
    cout<<"Enter left child of "<<x<<" :- ";
    newNode->left = create();

    //right child
    cout<<"Enter right child of "<<x<<" :- ";
    newNode->right = create();

    return newNode;
}

/** Binary Tree In Order Traversal
 * InOrder - Left Root Right
 */
void inOrder(Node *root) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

/** Binary Tree Pre Order Traversal
 * PreOrder - Root Left Right
 */
void preOrder(Node *root) {
    if(root == NULL) {
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

/** Binary Tree Post Order Traversal
 * PostOrder - Left Right Root
 */
void postOrder(Node *root) {
    if(root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main() {
    Node *root = NULL;
    root = create();
    cout<<"InOrder:-> ";
    inOrder(root);
    cout<<"\nPreOrder:-> ";
    preOrder(root);
    cout<<"\nPostOrder:->";
    postOrder(root);
    cout<<"\n";
    return 0;
}