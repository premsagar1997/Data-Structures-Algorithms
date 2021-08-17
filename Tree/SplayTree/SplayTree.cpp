#include<iostream>
using namespace std;

typedef struct node {
  int key;
  struct node* left;
  struct node* right;
}Node;

Node* createNode(int key) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->left = newNode->right = NULL;
  return newNode;
}

void preorder(Node* root) {
  if (root == NULL)
    return;
  
  cout<<root->key<<" ";
  preorder(root->left);
  preorder(root->right);
}

Node* rotateLeft(Node* x) {
  Node* y = x->right;
  Node* T2 = y->left;
  
  //perform rotation
  y->left = x;
  x->right = T2;

  return y;
}

Node* rotateRight(Node* y) {
  Node* x = y->left;
  Node* T2 = x->right;

  //perform rotation
  x->right = y;
  y->left = T2;

  return x;
}

/**This function brings the key at root if key is present in tree.
 * If key is not present, then it brings the last accessed item at root.
 * Function modifies the tree ans return the new root
 */
Node* splay(Node* root, int key) {
  //base case (root is null or key is present at root)
  if (root == NULL || root->key == key)
    return root;

  //If key lies in left subtree
  if (key < root->key) {
    //key is not in tree
    if (root->left == NULL)
      return root;

    //Zig - Zig (Left Left)
    if (key < root->left->key) {
      //first recursively bring the key as root of left-left
      root->left->left = splay(root->left->left, key);
      //do first rotation for root, second rotation is done after else
      root = rotateRight(root);
    } else if (key > root->left->key) { //Zig-Zag (Left Right)
      //first recursively bring the key as root of left-right
      root->left->right = splay(root->left->right, key);
      //do first rotation for root->left
      if (root->left->right != NULL)
        root->left = rotateLeft(root->left);
    }
    //do second rotation for root
    return root->left == NULL ? root : rotateRight(root); 
  } else { //If key lies in right subtree
    //key is not in tree
    if (root->right == NULL)
      return root;

    if (key > root->right->key) { //Zag-Zag (Right Right)
      //bring the ket as root of right-right & do first rotation
      root->right->right = splay(root->right->right, key);
      root = rotateLeft(root);
    } else if (key < root->right->key) { //Zag-Zig (Right Left)
      //bring the key as root of right-left
      root->right->left = splay(root->right->left, key);
      //do first rotation for root->right
      if (root->right->left != NULL)
        root->right = rotateRight(root->right);
    }
    //do second rotation for root
    return root->right == NULL ? root : rotateLeft(root);
  }
}

Node* search(Node* root, int key) {
  return splay(root, key);
}

int main() {
  Node* root = createNode(100);
  root->left = createNode(50);
  root->right = createNode(200);
  root->left->left = createNode(40);
  root->left->left->left = createNode(30);
  root->left->left->left->left = createNode(20);

  root = search(root, 20);
  cout<<"\nPreorder traversal of splay tree \n";
  preorder(root);
  cout<<"\n";
  return 0;
}
