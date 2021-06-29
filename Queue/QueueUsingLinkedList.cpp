#include<iostream>
using namespace std;

struct node {
  int data;
  struct node *next;
};

struct node *rear = NULL;
struct node *front = NULL;

/** Task: Insert an element into queue
 * Complexity: O(1)
 * @return void
 * @param data-to be inserted
 */
void enqueue(int x) {
  struct node *newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = x;
  newNode->next = NULL;

  if (rear == NULL && front == NULL) { //queue is empty
    rear = front = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

/** Task: Delete an element from queue
 * Complexity: O(1)
 * @return void
 */
void dequeue() {
  if (rear == NULL && front == NULL) { //queue is empty
    cout<<"Queue underflow!!!"<<endl;
  } else if (rear == front) { //only one element is present in the queue
    struct node *temp = front;
    rear = front = NULL;
    free(temp);
  } else {
    struct node *temp = front;
    front = front->next;
    free(temp);
  }
}

void display() {
  if (rear == NULL && front == NULL) { //queue is empty
    cout<<"Queue underflow!!!"<<endl;
  } else {
    struct node *temp = front;
    while (temp != NULL) {
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
}

/** Task: display peek(front) element of queue
 * Complexity: O(1)
 * @return void
 */
void peek() {
  if (rear == NULL && front == NULL) { //queue is empty
    cout<<"Queue underflow!!!"<<endl;
  } else {
    cout<<"Peek element is "<<front->data<<endl;
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