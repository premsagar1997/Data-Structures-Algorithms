#include<iostream>
#include<queue>
#include<map>
using namespace std;

typedef struct node {
  int data;
  int hd;
  struct node *left;
  struct node *right;
}Node;

Node* createNode(int data) {
  Node* n = (Node*)malloc(sizeof(Node));
  n->data = data;
  n->left = n->right = NULL;
  return n;
}

void topView(Node* root) {
  if (root == NULL)
    return;

  queue<Node*> myQ;
  map<int, int> mp;
  int hd = 0;
  root->hd = hd;

  myQ.push(root);
  while (!myQ.empty()) {
    root = myQ.front();
    myQ.pop();
    hd = root->hd;

    //count function returns 1 if the container contains an element whose key is equivalent to hd, or returns 0 otherwise
    if (mp.count(hd) == 0) {
      mp[hd] = root->data;
    }
    if (root->left) {
      root->left->hd = hd - 1;
      myQ.push(root->left);
    }
    if (root->right) {
      root->right->hd = hd + 1;
      myQ.push(root->right);
    }
  }

  map<int, int>::iterator i;
  for (i = mp.begin(); i != mp.end(); i++)
    cout<<i->second<<" ";
  cout<<endl;
}

int main() {
  Node* root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);
  topView(root);
  return 0;
}
