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

/** A iterative approach to insert a node in BST
 * Time Complexity
 * Average case - O(logN)
 * Worst case - O(N)
 * Where N is number of nodes
 */
struct node* insert(struct node *root, struct node *newNode) {
  if (root == NULL) {
    root = newNode;
  } else {
    struct node *temp = root;
    while (temp != NULL) {
      if (temp->key == newNode->key) { //no duplicate allowed in BST
        break;
      } else if (newNode->key < temp->key && temp->left == NULL) {
        temp->left = newNode;
        break;
      } else if (newNode->key < temp->key) {
        temp = temp->left;
      } else if (newNode->key > temp->key && temp->right == NULL) {
        temp->right = newNode;
        break;
      } else if (newNode->key > temp->key) {
        temp = temp->right;
      }
    }
  }
  return root;
}

void inOrder(struct node* root) {
  if (root == NULL)
    return;
  
  inOrder(root->left);
  cout<<root->key<<" ";
  inOrder(root->right);
}

struct node* search(struct node* root, int key) {
  if (root == NULL)
    return root;

  struct node* current = root;
  while (current != NULL) {
    if (key == current->key)
      return current;
    else if (key < current->key)
      current = current->left;
    else
      current = current->right;
  }
  return NULL;
}

int main() {
  struct node *root = NULL;

  root = insert(root, createNode(5));
  insert(root, createNode(3));
  insert(root, createNode(2));
  insert(root, createNode(4));
  insert(root, createNode(7));
  insert(root, createNode(6));
  insert(root, createNode(8));

  inOrder(root);
  cout<<endl;
  return 0;
}
