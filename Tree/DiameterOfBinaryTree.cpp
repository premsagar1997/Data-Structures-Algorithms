#include<iostream>
using namespace std;

typedef struct node {
  int key;
  struct node* left;
  struct node* right;
}Node;

int ans = 0;

int max(int a, int b) {
  return a > b ? a : b;
}

/** Return diameter of given binary tree
 * Time Complexity - O(n)
 */
int getDiameter(Node* root) {
  if (root == NULL) //base case
    return 0;

  int l = getDiameter(root->left);
  int r = getDiameter(root->right);
  ans = max(ans, (l + r + 1));
  return max(l, r) + 1;
}

int diameterOfBinaryTree(Node* root) {
  getDiameter(root);
  return ans == 0 ? ans : ans - 1;
}

Node* createNode(int key) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->left = newNode->right = NULL;
  return newNode;
}

int main() {
  Node* root = NULL;
  root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);

  cout<<diameterOfBinaryTree(root)<<endl;
  return 0;
}

