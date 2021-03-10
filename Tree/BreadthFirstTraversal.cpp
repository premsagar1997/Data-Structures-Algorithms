/** Level order traversal of a tree is breadth first traversal for the tree
  * Time Complexity - O(N) where N is number of nodes in the binary tree
  * Space Complexity - O(N) where N is number of nodes in the binary tree
*/

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

void bfs(Node *root) {
  if(root == NULL)
    return;

  queue<Node*> mQueue;
  mQueue.push(root);
  Node *temp = NULL;

  while(!mQueue.empty()) {
    temp = mQueue.front();
    mQueue.pop();
    cout<<temp->data<<" ";

    if(temp->left)
      mQueue.push(temp->left);

    if(temp->right)
      mQueue.push(temp->right);
  }
  cout<<"\n";
}

int main() {
  Node *root = NULL;
  root = createNode(1);
  root->left = createNode(2);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right = createNode(3);
  bfs(root);
  return 0;
}