#include<iostream>
using namespace std;

struct node {
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
  struct node *newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = x;
  newNode->next = NULL;
  if (front == NULL && rear == NULL) { //queue is empty
    front = rear = newNode;
    rear->next = front;
  } else {
    rear->next = newNode;
    rear = newNode;
    rear->next = front;
  }
}

void dequeue() {
  if (front == NULL && rear == NULL)
    cout<<"Queue is empty"<<endl;
  else if (front == rear) { //only one element is present
    struct node *temp = front;
    front = rear = NULL;
    free(temp);
  } else {
    struct node *temp = front;
    front = front->next;
    rear->next = front;
    free(temp);
  }
}

void peek() {
  if (front == NULL && rear == NULL)
    cout<<"Queue is empty"<<endl;
  else
    cout<<"Peek element is "<<front->data<<endl;
}

void display() {
  if (front == NULL && rear == NULL)
    cout<<"Queue is empty"<<endl;
  else {
    struct node *temp = front;
    while (temp->next != front) {
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<temp->data<<endl;
  }
}

int main() {
  int op, x;
  do {
    cout<<"1->Enqueue\n2->Dequeue\n3->Display\n4->Peek\n5->Exit\n";
    cin>>op;
    switch (op) {
      case 1:
        cout<<"Enter element ";
        cin>>x;
        enqueue(x);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        peek();
        break;
      case 5:
        break;
      default:
        cout<<"Invalid option!!!\n";
    }
  } while (op != 5);
  return 0;
}
