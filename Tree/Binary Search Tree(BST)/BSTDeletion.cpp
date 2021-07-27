#include<iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

//function to create new node with given key
struct node* createNode(int key) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->key = key;
  newNode->left = newNode->right = NULL;
  return newNode;
}

//inorder traversal of BST
void inorder(struct node* root) {
  if (root == NULL)
    return;

  inorder(root->left);
  cout<<root->key<<" ";
  inorder(root->right);
}

//function to insert new node in BST
struct node* insert(struct node* root, struct node* newNode) {
  if (root == NULL)
    return newNode;

  if (newNode->key < root->key)
    root->left = insert(root->left, newNode);
  else if (newNode->key > root->key)
    root->right = insert(root->right, newNode);
  
  return root;
}

struct node* minValueNode(struct node* root) {
  struct node *current = root;
  //find the leftmost leaf node
  while (current && current->left != NULL) {
    current = current->left;
  }
  return current;
}

struct node* deleteNode(struct node* root, int key) {
  //base case
  if (root == NULL)
    return root;
  
  //the key to be deleted is smaller than the root's key
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) { //the key to be deleted is greater than the root's key
    root->right = deleteNode(root->right, key);
  } else { //key matches
    //if node has right child or no child
    if (root->left == NULL) {
      struct node* temp = root->right;
      delete(root);
      return temp;
    } else if (root->right == NULL) { //if node has right child
      struct node* temp = root->left;
      delete(root);
      return temp;
    } else { //if node has 2 child
      struct node* temp = minValueNode(root->right); //get inorder successor
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }
  return root;
}

int main() {
  struct node* root = NULL;

  root = insert(root, createNode(5));
  root = insert(root, createNode(3));
  root = insert(root, createNode(2));
  root = insert(root, createNode(4));
  root = insert(root, createNode(7));
  root = insert(root, createNode(6));
  root = insert(root, createNode(8));

  cout<<"Inorder traversal of BST"<<endl;
  inorder(root);

  cout<<endl<<"Deleting 2"<<endl;
  root = deleteNode(root, 2);
  cout<<"Inorder traversal of BST"<<endl;
  inorder(root);

  cout<<endl<<"Deleting 3"<<endl;
  root = deleteNode(root, 3);
  cout<<"Inorder traversal of BST"<<endl;
  inorder(root);

  cout<<endl<<"Deleting 5"<<endl;
  root = deleteNode(root, 5);
  cout<<"Inorder traversal of BST"<<endl;
  inorder(root);
  cout<<endl;

  return 0;
}