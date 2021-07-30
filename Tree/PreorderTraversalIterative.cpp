// An iterative preorder traversal of a binary tree
// Time Complexity - O(n)

#include<iostream>
#include<stack>
using namespace std;

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
}Node;

Node* createNode(int key) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void preorder(Node* root) {
  if (root == NULL)
    return;

  stack<Node*> st;
  st.push(root);
  Node* current = NULL;
  while (!st.empty()) {
    current = st.top();
    st.pop();
    cout<<current->key<<" ";
    if (current->right != NULL)
      st.push(current->right);
    if (current->left != NULL)
      st.push(current->left);
  }
}

int main() {
  Node* root = createNode(30);
  root->left = createNode(20);
  root->left->left = createNode(10);
  root->left->right = createNode(25);
  root->left->left->left = createNode(5);
  root->right = createNode(50);
  root->right->left = createNode(45);
  preorder(root);
  cout<<endl;
  return 0;
}
