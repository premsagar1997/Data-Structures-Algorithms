#include<iostream>
using namespace std;

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
}Node;

Node* createNode(int key) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void inorder(Node* root) {
  if (root == NULL)
    return;
  
  inorder(root->left);
  cout<<root->key<<" ";
  inorder(root->right);
}

int height(Node* root) {
  if (root == NULL)
    return -1;

  int lHeight = height(root->left);
  int rHeight = height(root->right);
  if (lHeight > rHeight)
    return (lHeight + 1);
  else
    return (rHeight + 1);
}

int main() {
  Node *root = NULL;
  root = createNode(30);
  root->left = createNode(20);
  root->left->left = createNode(10);
  root->left->right = createNode(25);
  root->left->left->left = createNode(5);
  root->right = createNode(50);
  root->right->left = createNode(45);
  inorder(root);
  cout<<endl;
  cout<<height(root)<<endl;
}