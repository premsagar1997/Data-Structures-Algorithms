// The idea is to do iterative level order traversal of the given tree using queue.
// If we find a node whose left child is empty, we make new key as left child of the node.
// Else if we find a node whose right child is empty, we make the new key as right child.
// We keep traversing the tree until we find a node whose either left or right is empty

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

Node *insertNode(Node *root, int data) {
  if(root == NULL) { //if tree is empty
    root = createNode(data);
    return root;
  }

  queue<Node*> mQueue;
  mQueue.push(root);

  while(!mQueue.empty()) {
    Node *temp = mQueue.front();
    mQueue.pop();

    if(temp->left != NULL)
      mQueue.push(temp->left);
    else {
      temp->left = createNode(data);
      return root;
    }

    if(temp->right != NULL)
      mQueue.push(temp->right);
    else {
      temp->right = createNode(data);
      return root;
    }
  }
}

int main() {
  Node *root = createNode(10);
  root->left = createNode(11);
  root->left->left = createNode(7);
  root->right = createNode(9);
  root->right->left = createNode(15);
  root->right->right = createNode(8);

  cout<<"Inorder before insertion:\n";
  inOrder(root);
  cout<<"\n";

  root = insertNode(root, 12);
  cout<<"Inorder after insertion:\n";
  inOrder(root);
  cout<<"\n";

  return 0;
}