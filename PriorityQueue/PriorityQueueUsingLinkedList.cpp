#include<iostream>
using namespace std;

struct node {
  int data;
  int priority;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

bool isEmpty();
void dequeue();
void enqueue(int data, int priority);
void display();

void dequeue() {
  if (isEmpty()) { //queue is empty
    cout<<"Queue is empty\n";
    return;
  }

  struct node *temp = front;
  if (front == rear) { //only one element is present in queue
    front = rear = NULL;
  } else {
    front = front->next;
  }
  cout<<"Deleted element is "<<temp->data<<" with priority "<<temp->priority<<endl;
  free(temp);
}

void enqueue(int data, int priority) {
  struct node *newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->priority = priority;
  
  if (isEmpty()) { //if queue is empty
    front = rear = newNode;
  } else {
    struct node *current = front;
    struct node *prev = NULL;
    while (current != NULL && current->priority > priority) {
      prev = current;
      current = current->next;
    }

    if (prev == rear) { //if element has lowest priority. Insert at last
      rear->next = newNode;
      rear = newNode;
    } else if (prev == NULL) { //if elemenet has highest priority
      newNode->next = front;
      front = newNode;
    } else {
      prev->next = newNode;
      newNode->next = current;
    }
  }
}

void display() {
  if (isEmpty()) {
    cout<<"Queue is empty\n";
    return;
  } else {
    struct node *temp = front;
    while (temp != NULL) {
      cout<<temp->data<<" with priority "<<temp->priority<<endl;
      temp = temp->next;
    }
  }
}

bool isEmpty() {
  return (front == NULL && rear == NULL);
}

int main() {
  int ch, ele, pri;
  do {
    cout<<"\n1->Enqueue\n2->Dequeue\n3->Display\n4->Exit\n";
    cin>>ch;
    switch (ch) {
      case 1:
        cout<<"Enter element and it's priority: ";
        cin>>ele>>pri;
        enqueue(ele, pri);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
      default:
        cout<<"Invalid option!!!";
        break;
    }
  } while (ch != 4);
  return 0;
}