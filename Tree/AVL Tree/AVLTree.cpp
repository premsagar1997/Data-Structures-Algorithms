#include<iostream>
using namespace std;

struct node {
  int key;
  struct node *left;
  struct node *right;
  int height;
};

int max(int x, int y);
int height(struct node *N);

//function to get the height of the tree
int height(struct node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

//function to get max between two integers
int max(int x, int y) {
  return x > y ? x : y;
}

//function to create a node with given key
struct node *createNode(int key) {
  struct node *newNode = (struct node*)malloc(sizeof(struct node));
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->height = 1; //new node is initially added at leaf
  return newNode;
}