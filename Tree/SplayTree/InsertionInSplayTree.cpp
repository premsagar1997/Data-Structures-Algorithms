#include<iostream>
using namespace std;

typedef struct node {
  int key;
  struct node *left, *right;
}Node;

Node* createNode(int key) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node* leftRotate(Node* x) {
  Node* y = x->right;
  Node* T2 = y->left;
  
  //perform rotation
  y->left = x;
  x->right = T2;

  return y;
}

Node* rightRotate(Node* y) {
  Node* x = y->left;
  Node* T2 = x->right;

  //perform rotation
  x->right = y;
  y->left = T2;

  return x;
}

void preOrder(Node* root) {
  if (root == NULL)
    return;

  cout<<root->key<<" ";
  preOrder(root->left);
  preOrder(root->right);
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
      root = rightRotate(root);
    } else if (key > root->left->key) { //Zig-Zag (Left Right)
      //first recursively bring the key as root of left-right
      root->left->right = splay(root->left->right, key);
      //do first rotation for root->left
      if (root->left->right != NULL)
        root->left = leftRotate(root->left);
    }
    //do second rotation for root
    return root->left == NULL ? root : rightRotate(root); 
  } else { //If key lies in right subtree
    //key is not in tree
    if (root->right == NULL)
      return root;

    if (key > root->right->key) { //Zag-Zag (Right Right)
      //bring the ket as root of right-right & do first rotation
      root->right->right = splay(root->right->right, key);
      root = leftRotate(root);
    } else if (key < root->right->key) { //Zag-Zig (Right Left)
      //bring the key as root of right-left
      root->right->left = splay(root->right->left, key);
      //do first rotation for root->right
      if (root->right->left != NULL)
        root->right = rightRotate(root->right);
    }
    //do second rotation for root
    return root->right == NULL ? root : leftRotate(root);
  }
}

Node* insert(Node* root, int key) {
  //if tree is empty
  if (root == NULL)
    return createNode(key);

  //bring the closest leat node to root
  root = splay(root, key);

  //if key is already present, then return root
  if (root->key == key)
    return root;

  //allocate memory for new node
  Node *newNode = createNode(key);

  //if key is smaller than root's key
  //make root as right child of new node
  //copy left child of root as left child of new node
  //make left child of root as NULL
  if (root->key > key) {
    newNode->right = root;
    newNode->left = root->left;
    root->left = NULL;
  } else {
    //if key is greater than root's key
    //make root as left child of new node
    //copy right child of root as right child of new node
    //make right child of root as NULL
    newNode->left = root;
    newNode->right = root->right;
    root->right = NULL;
  }

  return newNode; //return new node as new root of tree
}

int main() {
  Node* root = createNode(100);
  root->left = createNode(50);
  root->right = createNode(200);
  root->left->left = createNode(40);
  root->left->left->left = createNode(30);
  root->left->left->left->left = createNode(20);
  root = insert(root, 25);
  preOrder(root);
  cout<<endl;

  return 0;
}
