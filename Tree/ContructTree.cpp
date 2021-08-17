//Contruct binary tree from preorder and inorder traversal

#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<int, int> mp;
int preorderIndex = 0;

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
}Node;

Node* buildTree(vector<int> &x, vector<int> &y, int s, int e);

Node* createNode(int val) {
  Node* nNode = (Node*)malloc(sizeof(Node));
  nNode->data = val;
  nNode->left = nNode->right = NULL;
  return nNode; 
}

Node* constructBinaryTree(vector<int>& preorder, vector<int>& inorder) {
  for (int i = 0; i < inorder.size(); i++)
    mp.insert(pair<int, int>(inorder[i], i));

  return buildTree(preorder, inorder, 0, inorder.size() - 1);
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end) {
  if (start > end)
    return NULL;

  Node* root = createNode(preorder[preorderIndex++]);
  if (root == NULL)
    return NULL;

  if (start == end)
    return root;

  int index = mp.find(root->data)->second;
  root->left = buildTree(preorder, inorder, start, index - 1);
  root->right = buildTree(preorder, inorder, index + 1, end);

  return root;
}

void inOrder(Node* root) {
  if (root == NULL)
    return;

  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

int main() {
  vector<int> preorder { 3, 9, 20, 15, 7 };
  vector<int> inorder { 9, 3, 15, 20, 7 };

  Node* root = constructBinaryTree(preorder, inorder);
  inOrder(root);
  cout<<endl;

  return 0;
}
