/** Depth first traversal of a binary tree
  * Time Complexity - O(N) where N is number of nodes in the binary tree
  * Space Complexity - O(N) where N is number of nodes in the binary tree
  * Inorder Traversal (Left-Root-Right)
  * Preorder Traversal (Root-Left-Right)
  * Postorder Traversal (Left-Right-Root)
*/

#include <iostream>
using namespace std;

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    cout << "Memory error!!!" << endl;
    return NULL;
  }

  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void inOrder(Node *root) {
  if (root == NULL)
    return;

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void preOrder(Node *root) {
  if (root == NULL)
    return;

  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node *root) {
  if (root == NULL)
    return;

  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

int main() {
  Node *root = NULL;
  root = createNode(1);
  root->left = createNode(2);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right = createNode(3);
  inOrder(root);
  cout<<"\n";
  preOrder(root);
  cout<<"\n";
  postOrder(root);
  cout<<"\n";
  return 0;
}