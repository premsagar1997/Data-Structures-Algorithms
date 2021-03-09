// Given a binary tree, delete a node from it by making sure that tree shrinks from the bottom
// (i.e. the deleted node is replaced by bottom most and rightmost node)

#include<iostream>
#include<queue>
using namespace std;

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
}Node;

Node* createNode(int data) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  if(!newNode) {
    cout<<"Memory error!!!"<<endl;
    return NULL;
  }

  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void inOrder(Node *root) {
  if(root == NULL)
    return;
  
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

void deleteDeepest(Node *root, Node *lastNode) {
  queue<Node*> mQueue;
  mQueue.push(root);

  Node *temp;
  while(!mQueue.empty()) {
    temp = mQueue.front();
    mQueue.pop();

    if(temp == lastNode) {
      temp = NULL;
      free(lastNode);
      return;
    }

    if(temp->left) {
      if(temp->left == lastNode) {
        temp->left = NULL;
        free(lastNode);
        return;
      } else {
        mQueue.push(temp->left);
      }
    }

    if(temp->right) {
      if(temp->right == lastNode) {
        temp->right = NULL;
        free(lastNode);
        return;
      } else {
        mQueue.push(temp->right);
      }
    }
  }
}

Node *deleteNode(Node *root, int data) {
  if(root == NULL) return NULL;

  if(root->left == NULL && root->right == NULL) {
    if(root->data == data) {
      free(root);
      return NULL;
    } else {
      return root;
    }
  }

  queue<Node*> mQueue;
  mQueue.push(root);

  Node *temp, *keyNode = NULL;
  while(!mQueue.empty()) {
    temp = mQueue.front();
    mQueue.pop();

    if(temp->data == data) {
      keyNode = temp;
    }

    if(temp->left)
      mQueue.push(temp->left);

    if(temp->right)
      mQueue.push(temp->right);
  }

  if(keyNode != NULL) {
    int keyValue = temp->data; //copy data of deepest node
    deleteDeepest(root, temp);
    keyNode->data = keyValue;
  }
  return root;
}

int main() {
  Node *root = NULL;
  root = createNode(10);
  root->left = createNode(11);
  root->left->left = createNode(7);
  root->left->right = createNode(12);
  root->right = createNode(9);
  root->right->left = createNode(15);
  root->right->right = createNode(8);

  cout<<"Inorder before deletion\n";
  inOrder(root);
  cout<<"\n";

  root = deleteNode(root, 11);
  cout<<"Inorder after deletion\n";
  inOrder(root);
  cout<<"\n";

  return 0;
}