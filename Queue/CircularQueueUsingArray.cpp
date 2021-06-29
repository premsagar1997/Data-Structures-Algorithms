#include<iostream>
#define N 5
using namespace std;

int queue[N];
int front = -1, rear = -1;

void enqueue(int x) {
  if (rear == -1 && front == -1) { //queue is empty
    front = rear = 0;
    queue[rear] = x;
  } else if ((rear+1)%N == front) { //queue is full
    cout<<"Queue is full\n";
  } else {
    rear = (rear+1)%N;
    queue[rear] = x;
  }
}

void dequeue() {
  if (rear == -1 && front == -1) //queue is empty
    cout<<"Queue is empty!!!\n";
  else if (front == rear) //queue has only one element
    rear = front = -1;
  else
    front = (front+1)%N;
}

void display() {
  if (rear == -1 && front == -1) {
    cout<<"Queue is empty!!!\n";
    return;
  }
  int temp = front;
  while (temp != rear) {
    cout<<queue[temp]<<" ";
    temp = (temp+1)%N;
  }
  cout<<queue[rear]<<endl;
}

void peek() {
  if (rear == -1 && front == -1) //queue is empty
    cout<<"Queue is empty!!!\n";
  else
    cout<<"Peek element is "<<queue[front]<<endl;
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