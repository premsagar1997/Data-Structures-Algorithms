#include<iostream>
#include<vector>
using namespace std;

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
}Node;

bool findPath(Node* root, vector<Node*> &path, int v) {
  if (root == NULL)
    return false;

  path.push_back(root);

  if (root->data == v)
    return true;

  if ((root->left && findPath(root->left, path, v)) || (root->right && findPath(root->right, path, v)))
    return true;

  path.pop_back();
  return false;
}

Node* findLCA(Node* root, int v1, int v2) {
  vector<Node*> path1, path2;

  if (!findPath(root, path1, v1) || !findPath(root, path2, v2))
    return NULL;

  int i;
  for (i = 0; i < path1.size() && i < path2.size(); i++) {
    if (path1[i]->data != path2[i]->data)
      break;
  }

  return path1[i-1];
}

Node* newNode(int data) {
  Node* n = (Node*)malloc(sizeof(Node));
  n->data = data;
  n->left = n->right = NULL;
  return n;
}

int main() {
  Node * root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  cout<<"\nLCA(4, 5) = "<<findLCA(root, 4, 5)->data;
  cout<<"\nLCA(4, 6) = "<<findLCA(root, 4, 6)->data;
  cout<<"\nLCA(3, 4) = "<<findLCA(root, 3, 4)->data;
  cout<<"\nLCA(2, 4) = "<<findLCA(root, 2, 4)->data;
  cout<<"\n";
   
  return 0;
}
