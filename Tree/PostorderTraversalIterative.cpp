// An iterative postorder traversal of a binary tree
// Time Complexity - O(n)

/** Alorithm
 * 1 Push root to first stack
 * 2 Loop while first stack is not empty
 *    2.a Pop a node from first stack and push it to second stack
 *    2.b Push left & right children of the popped node to first stack
 * 3 Print contents of second stack
*/

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

void postorder(Node* root) {
  if (root == NULL)
    return;

  stack<Node*> st1;
  stack<Node*> st2;
  st1.push(root);
  Node* current = NULL;
  while (!st1.empty()) {
    current = st1.top();
    st1.pop();
    st2.push(current);
    if (current->left != NULL)
      st1.push(current->left);
    if (current->right != NULL)
      st1.push(current->right);
  }

  while (!st2.empty()) {
    cout<<st2.top()->key<<" ";
    st2.pop();
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
  postorder(root);
  cout<<endl;
  return 0;
}
