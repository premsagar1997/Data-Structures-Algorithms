//Mirror of a Tree: Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged.

#include<iostream>
#include<queue>
using namespace std;

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
}Node;

Node *createNode(int data) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(newNode == NULL)
    cout<<"Memory Error!!!\n";
  
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void invertBinaryTree(Node *root) {
  if (root == NULL)
    return;

  Node *temp = NULL;
  invertBinaryTree(root->left);
  invertBinaryTree(root->right);

  temp = root->left;
  root->left = root->right;
  root->right = temp;
}

Node* invert(Node *root) {
  if (root == NULL)
    return NULL;

  Node* leftTree = invert(root->left);
  Node* rightTree = invert(root->right);

  root->left = rightTree;
  root->right = leftTree;

  return root;
}

void mirror(Node *root) {
  if(root == NULL)
    return;

  queue<Node*> mQueue;
  mQueue.push(root);
  Node *current = NULL;
  
  while(!mQueue.empty()) {
    current = mQueue.front();
    mQueue.pop();

    Node *temp = current->right;
    current->right = current->left;
    current->left = temp;

    if(current->left)
      mQueue.push(current->left);
    if(current->right)
      mQueue.push(current->right);
  }
}

void inOrder(Node *root) {
  if(root == NULL) 
    return;
  
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

int main() {
  Node *root = NULL;
  root = createNode(1);
  root->left = createNode(3);
  root->right = createNode(2);
  root->right->left = createNode(5);
  root->right->right = createNode(4);
  inOrder(root);
  cout<<"\n";
  mirror(root);
  inOrder(root);
  cout<<"\n";
  return 0;
}
