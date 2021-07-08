#include<iostream>
#define N 5
using namespace std;

struct priorityQueue {
  int data;
  int priority;
};

struct priorityQueue pQueue[N];
int rear = -1;

bool isFull();
bool isEmpty();
void enqueue();
void dequeue();
void display();
int getHighestPriority();

void enqueue(int data, int priority) {
  if (isFull()) {
    cout<<"Queue is full\n";
    return;
  }
  rear++;
  pQueue[rear].data = data;
  pQueue[rear].priority = priority;
}

void dequeue() {
  if (isEmpty()) {
    cout<<"Queue is empty\n";
    return;
  }
  //get highest priority
  int priority = INT_MIN;
  int index = -1;
  for (int i = 0; i <= rear; i++) {
    if (priority < pQueue[i].priority) {
      priority = pQueue[i].priority;
      index = i;
    }
  }
  //print element
  cout<<"Deleting element "<<pQueue[index].data<<" of priority "<<priority<<endl;
  //shift element
  for (int i = index; i < rear; i++)
    pQueue[i] = pQueue[i+1];
  rear--;
}

int getHighestPriority() {
  if (isEmpty())
    return -1;
  int p = INT_MIN;
  for (int i = 0; i <= rear; i++) {
    if (p < pQueue[i].priority)
      p = pQueue[i].priority;
  }
  return p;
}

bool isFull() {
  if (rear == N - 1)
    return true;
  return false;
}

bool isEmpty() {
  if (rear == -1)
    return true;
  return false;
}

void display() {
  if (isEmpty()) {
    cout<<"Queue is empty\n";
    return;
  }
  cout<<"\nElement  Priority\n";
  for (int i = 0; i <= rear; i++)
    cout<<pQueue[i].data<<"  "<<pQueue[i].priority<<endl;
}

int main() {
  int op, x, p;
  do {
    cout<<"\n1->Enqueue\n2->Dequeue\n3->Display\n4->Get Highest Priority\n5->Exit\n";
    cin>>op;
    switch (op) {
      case 1:
        cout<<"Enter element and priority ";
        cin>>x>>p;
        enqueue(x, p);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        p = getHighestPriority();
        if (p == -1)
          cout<<"Queue is empty\n";
        else
          cout<<"Highest priority "<<p<<endl;
        break;
      case 5:
        break;
      default:
        cout<<"Invalid option!!!\n";
    }
  } while (op != 5);
  return 0;
}