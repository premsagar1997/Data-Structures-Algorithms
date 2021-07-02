#include<iostream>
#define N 5
using namespace std;

int st1[N], st2[N];
int top1 = -1, top2 = -1;

void push1(int x);
void push2(int x);
int pop1();
int pop2();
void enqueue(int x);
void dequeue();
void display();
void peek();
bool isQueueEmpty();

void enqueue(int x) {
  push1(x);
}

void dequeue() {
  if (isQueueEmpty()) {
    cout<<"Queue is empty"<<endl;
  } else {
    while (top1 != -1) {
      push2(pop1());
    }
    int el = pop2();
    cout<<"dequeued element "<<el<<endl;
    while (top2 != -1) {
      push1(pop2());
    }
  }
}

void push1(int data) {
  if (top1 == N-1) {
    cout<<"Queue is full"<<endl;
  } else {
    st1[++top1] = data;
  }
}

void push2(int data) {
  if (top2 == N-1) {
    cout<<"Queue is full"<<endl;
  } else {
    st2[++top2] = data;
  }
}

int pop1() {
  if (top1 == -1 ) {
    return -1;
  } else {
    int x = st1[top1];
    top1--;
    return x;
  }
}

int pop2() {
  if(top2 == -1) {
    return -1;
  } else {
    int x = st2[top2];
    top2--;
    return x;
  }
}

void display() {
  if (isQueueEmpty()) {
    cout<<"Queue is empty"<<endl;
  } else {
    for (int i = 0; i <= top1; i++)
      cout<<st1[i]<<" ";
    cout<<endl;
  }
}

void peek() {
  if (isQueueEmpty())
    cout<<"Queue is empty"<<endl;
  else
    cout<<st1[0]<<endl;
}

bool isQueueEmpty() {
  if (top1 == -1 && top2 == -1)
    return true;
  return false;
}

int main() {
  int op, x;
  do {
    cout<<"\n1->Enqueue\n2->Dequeue\n3->Display\n4->Peek\n5->Exit\n";
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
