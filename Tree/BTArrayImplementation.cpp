#include<iostream>
using namespace std;

char tree[10];

int root(char key) {
  if(tree[0] != '\0')
    cout<<"Tree already had root\n";
  else
    tree[0] = key;
  return 0;
}

int setLeftChild(char leftChild, int parent) {
  if(tree[parent] == '\0')
    cout<<"Can't set child of "<<(parent * 2) + 1<<", no parent found!!!\n";
  else
    tree[(parent * 2) + 1] = leftChild;
  return 0;
}

int setRightChild(char rightChild, int parent) {
  if(tree[parent] == '\0')
    cout<<"Can't set child of "<<(parent * 2) + 2<<" , no parent found!!!\n";
  else
    tree[(parent * 2) + 2] = rightChild;
  return 0;
}

int printTree() {
  cout<<"\n";
  for(int i = 0; i < 10; i++) {
    if(tree[i] != '\0')
      cout<<tree[i]<<" ";
    else
      cout<<" -- ";
  }
  cout<<"\n";
  return 0;
}

int main() {
  root('A');
  setRightChild('C', 0);
  setLeftChild('D', 1);
  setRightChild('E', 1);
  setRightChild('F', 2);
  printTree();
  return 0;
}