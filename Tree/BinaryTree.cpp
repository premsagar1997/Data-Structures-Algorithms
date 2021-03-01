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

int main() {
    Node *root = NULL;
    root = create();
}