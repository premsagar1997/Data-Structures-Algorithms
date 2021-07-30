// An iterative inorder traversal of a binary tree
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

void inorder(Node* root) {
  stack<Node*> st; //create empty stack
  Node* current = root; //start from the root node

  while (!st.empty() || current != NULL) {
    //push the current node to the stack and set current = current->left
    if (current != NULL) {
      st.push(current);
      current = current->left;
    } else {
      current = st.top();
      st.pop();
      cout<<current->key<<" ";
      current = current->right;
    }
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
  inorder(root);
  cout<<endl;
  return 0;
}
