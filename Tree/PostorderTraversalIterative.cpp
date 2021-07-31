// An iterative postorder traversal of a binary tree
// Time Complexity - O(n)

#include<iostream>
#include<stack>
using namespace std;

typedef struct node {
  int key;
  struct node *left;
  struct node *right;
}Node;

Node* createNode(int key) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->left = newNode->right = NULL;
  return newNode;
}

/** Alorithm - Post order traversal using 2 stacks
 * 1 Push root to first stack
 * 2 Loop while first stack is not empty
 *    2.a Pop a node from first stack and push it to second stack
 *    2.b Push left & right children of the popped node to first stack
 * 3 Print contents of second stack
*/
void postorder(Node* root) {
  if (root == NULL)
    return;

  stack<Node*> st1;
  stack<Node*> st2;
  st1.push(root);
  Node* current = NULL;
  while (!st1.empty()) {
    current = st1.top();
    st1.pop();
    st2.push(current);
    if (current->left != NULL)
      st1.push(current->left);
    if (current->right != NULL)
      st1.push(current->right);
  }

  while (!st2.empty()) {
    cout<<st2.top()->key<<" ";
    st2.pop();
  }
}

/**Postorder traversal using one stack
 */
void postOrderTraversal(Node* root) {
  if (root == NULL)
    return;

  stack<Node*> st;
  Node* current = root; //set current as root
  do {
    //push the right child and then current into stack
    //set current as current->left
    while (current != NULL) { //move to leftmost node
      if (current->right != NULL)
        st.push(current->right);
      st.push(current);
      current = current->left;
    }

    //pop an item from stack & set it to current
    if (!st.empty()) {
      current = st.top();
      st.pop();
    }

    //If the popped item has a right child and the right child is at top of stack,
    //then remove the right child from stack, push the current back and set current as current's right child.
    if (current->right != NULL && !st.empty() && current->right == st.top()) {
      st.pop();
      st.push(current);
      current = current->right;
    } else if(current) {
      //print current's data and set current as NULL.
      cout<<current->key<<" ";
      current = NULL;
    }

  } while (!st.empty());
}

int main() {
  Node* root = createNode(30);
  root->left = createNode(20);
  root->left->left = createNode(10);
  root->left->right = createNode(25);
  root->left->left->left = createNode(5);
  root->right = createNode(50);
  root->right->left = createNode(45);
  postorder(root);
  cout<<endl;
  postOrderTraversal(root);
  cout<<endl;
  return 0;
}
