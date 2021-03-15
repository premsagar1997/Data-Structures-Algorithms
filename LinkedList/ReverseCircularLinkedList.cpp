#include<iostream>
using namespace std;

typedef struct node {
  int data;
  struct node *next;
}Node;

Node * tail = NULL;

Node* createNode(int data) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void createList() {
  int arr[4] = { 4, 3, 2, 1 };
  for(int i = 0; i < 4; i++) {
    Node *newNode = createNode(arr[i]);
    if(tail == NULL) {
      tail = newNode;
      tail->next = newNode;
    } else {
      newNode->next = tail->next;
      tail->next = newNode;
    }
  }
}

void displayList() {
  if(tail == NULL) {
    cout<<"List is empty\n";
  } else {
    Node *temp = tail->next;
    while(temp->next != tail->next) {
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<temp->data<<'\n';
  }
}

void reverseCircularList() {
  if(tail == NULL) {
    cout<<"List is empty\n";
  } else {
    Node *prevNode, *currentNode, *nextNode;
    currentNode = tail->next;
    nextNode = currentNode->next;
    while(currentNode != tail) {
      prevNode = currentNode;
      currentNode = nextNode;
      nextNode = currentNode->next;
      currentNode->next = prevNode;
    }
    nextNode->next = tail;
    tail = nextNode;
  }
}

int main() {
  createList();
  displayList();
  reverseCircularList();
  displayList();
  return 0;
}