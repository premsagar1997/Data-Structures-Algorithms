#include<iostream>
#define N 5
using namespace std;

int queue[N];
int rear = -1, front = -1;

void enqueueRear(int x);
void enqueueFront(int x);
void dequeueRear();
void dequeueFront();
void display();
void getFront();
void getRear();

void enqueueRear(int x) {
  if ((front == 0 && rear == N - 1) || front == rear + 1) {
    cout<<"Queue is full"<<endl;
  } else if (front == -1 && rear == -1) {
    front = rear = 0;
    queue[rear] = x;
  } else if (rear == N-1) {
    rear = 0;
    queue[rear] = x;
  } else {
    rear++;
    queue[rear] = x;
  }
}

void enqueueFront(int x) {
  if ((front == 0 && rear == N - 1) || front == rear + 1) {
    cout<<"Queue is full"<<endl;
  } else if (front == -1 && rear == -1) {
    front = rear = 0;
    queue[rear] = x;
  } else if (front == 0) {
    front = N-1;
    queue[front] = x;
  } else {
    front--;
    queue[front] = x;
  }
}

void dequeueRear() {
  if (front == -1 && rear == -1) {
    cout<<"Queue is empty"<<endl;
    return;
  }
  cout<<"Dequeued element is "<<queue[rear]<<endl;
  if (front == rear)
    front = rear = -1;
  else if (rear == 0)
    rear = N - 1;
  else
    rear--;
}

void dequeueFront() {
  if (front == -1 && rear == -1) {
    cout<<"Queue is empty"<<endl;
    return;
  }
  cout<<"Dequeued element is "<<queue[front]<<endl;
  if (front == rear)
    front = rear = -1;
  else if (front == N-1)
    front = 0;
  else
    front++;
}

void display() {
  if (front == -1 && rear == -1)
    cout<<"Queue is empty"<<endl;
  else {
    int i = front;
    while (i != rear) {
      cout<<queue[i]<<" ";
      i = (i+1)%N;
    }
    cout<<queue[rear]<<endl;
  }
}

void getFront() {
  if (front == -1 && rear == -1)
    cout<<"Queue is empty"<<endl;
  else
    cout<<"front element is "<<queue[front]<<endl;
}

void getRear() {
  if (front == -1 && rear == -1)
    cout<<"Queue is empty"<<endl;
  else
    cout<<"rear element is "<<queue[rear]<<endl;
}

int main() {
  return 0;
}
