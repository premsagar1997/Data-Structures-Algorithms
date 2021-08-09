#include<iostream>
using namespace std;

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
  int height;
}Node;

int max(int x, int y);
int height(Node* N);

//function to get the height of the tree
int height(Node* N) {
  if (N == NULL)
    return 0;
  return N->height;
}

//function to get max between two integers
int max(int x, int y) {
  return x > y ? x : y;
}

//function to create a node with given key
Node* createNode(int key) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->height = 1; //new node is initially added at leaf
  return newNode;
}

Node* leftRotate(Node* x) {
  Node* y = x->right;
  Node* T2 = y->left;

  //perform left rotation
  y->left = x;
  x->right = T2;

  return y;
}

Node* rightRotate(Node* z) {
  Node* y = z->left;
  Node* T2 = y->right;

  //perform right rotation
  y->right = z;
  z->left = T2;

  return y;
}

Node* insert() {
  
}

int main() {
  Node* root = NULL;
  return 0;
}
