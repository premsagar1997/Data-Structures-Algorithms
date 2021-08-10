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

int getBalanceFactor(Node* root) {
  if (root == NULL)
    return 0;
  return (height(root->left) - height(root->right));
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

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

Node* rightRotate(Node* z) {
  Node* y = z->left;
  Node* T2 = y->right;

  //perform right rotation
  y->right = z;
  z->left = T2;

  z->height = max(height(z->left), height(z->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

/** Insert node in AVL tree 
 * Time complexity - O(log n)
 */
Node* insert(Node* root, int key) {
  if (root == NULL)
    return createNode(key);

  if (key < root->key) {
    root->left = insert(root->left, key);
  } else if (key > root->key) {
    root->right = insert(root->right, key);
  } else {
    cout<<"Duplicate not allowed!!!"<<endl;
    return root;
  }

  root->height = 1 + max(height(root->left), height(root->right));

  int bf = getBalanceFactor(root);
  if (bf > 1 && key < root->left->key) { //left left case
    return rightRotate(root);
  } else if (bf < -1 && key > root->right->key) { //right right case
    return leftRotate(root);
  } else if (bf > 1 && key > root->left->key) { //left right case
    root->left = leftRotate(root->left);
    return rightRotate(root);
  } else if (bf < -1 && key < root->right->key) { //right left case
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

Node* getMinValueNode(Node* root) {
  Node* current = root;
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

/** Delete node from AVL tree 
 * Time complexity - O(log n)
 */
Node* deleteNode(Node* root, int key) {
  if (root == NULL) {
    return root;
  }
  
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    if (root->left == NULL || root->right == NULL) { //node has one child or no child
      Node* temp = root->left ? root->left : root->right;
      if (temp == NULL) { //root has no child
        temp = root;
        root = NULL;
      } else {
        *root = *temp; //copy content
      }
      delete(temp);
    } else { //node has 2 children
      Node* minValueNode = getMinValueNode(root->right);
      root->key = minValueNode->key;
      root->right = deleteNode(root->right, minValueNode->key);
    }
  }

  if (root == NULL)
    return root;

  root->height = 1 + max(height(root->left), height(root->right));

  int bf = getBalanceFactor(root);
  if (bf > 1 && getBalanceFactor(root->left) >= 0) {
    return rightRotate(root);
  } else if (bf > 1 && getBalanceFactor(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  } else if (bf < -1 && getBalanceFactor(root->right) <= 0) {
    return leftRotate(root);
  } else if (bf < -1 && getBalanceFactor(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void preorder(Node* root) {
  if (root == NULL)
    return;

  cout<<root->key<<" ";
  preorder(root->left);
  preorder(root->right);
}

int main() {
  Node* root = NULL;

  root = insert(root, 2);
  root = insert(root, 1);
  root = insert(root, 7);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 3);
  root = insert(root, 8);

  preorder(root);
  cout<<endl;

  root = deleteNode(root, 3);
  preorder(root);
  cout<<endl;

  return 0;
}
