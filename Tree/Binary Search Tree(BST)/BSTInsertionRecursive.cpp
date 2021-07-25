#include<iostream>
using namespace std;

struct node {
  int key;
  struct node *left;
  struct node *right;
};

struct node *createNode(int key) {
  struct node *newNode = (struct node*)malloc(sizeof(struct node));
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

/** A recursive approach to insert a node in BST
 * Time Complexity
 * Average case - O(logN)
 * Worst case - O(N)
 * Where N is number of nodes
 */
struct node* insert(struct node *root, struct node *newNode) {
  if (root == NULL) //if tree is empty
    return newNode;
  
  if (newNode->key < root->key)
    root->left = insert(root->left, newNode);
  else if(newNode->key > root->key)
    root->right = insert(root->right, newNode);
  return root;
}

void inOrder(struct node* root) {
  if (root == NULL)
    return;
  
  inOrder(root->left);
  cout<<root->key<<" ";
  inOrder(root->right);
}

int main() {
  struct node *root = NULL;

  root = insert(root, createNode(22));
  insert(root, createNode(31));
  insert(root, createNode(42));
  insert(root, createNode(28));
  insert(root, createNode(7));
  insert(root, createNode(6));
  insert(root, createNode(14));

  inOrder(root);
  cout<<endl;
  return 0;
}
