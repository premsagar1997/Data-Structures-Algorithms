#include<iostream>
#define N 5
using namespace std;

int queue[N];
int rear = -1;
int front = -1;

/** Task: Insert an element into queue
 * Complexity: O(1)
 * @return void
 * @param data-to be inserted
 */
void enqueue(int data) {
  if (rear == N - 1) {
    cout<<"Queue overflow!!!\n";
  } else if (rear == -1 && front == -1) {
    rear = front = 0;
    queue[rear] = data;
  } else {
    queue[++rear] = data;
  }
}

/** Task: Delete an element from queue
 * Complexity: O(1)
 * @return void
 */
void dequeue() {
  if (rear == -1 && front == -1)
    cout<<"Queue underflow\n";
  else if (rear == front) {
    cout<<"deleted element is "<<queue[front]<<endl;
    rear = front = -1;
  } else {
    cout<<"deleted element is "<<queue[front]<<endl;
    front++;
  }
}

void display() {
  if (rear == -1 && front == -1)
    cout<<"Queue underflow\n";
  else {
    for (int i = front; i <= rear; i++)
      cout<<queue[i]<<" ";
    cout<<endl;
  }
}

/** Task: display peek(front) element of queue
 * Complexity: O(1)
 * @return void
 */
void peek() {
  if (rear == -1 && front == -1)
    cout<<"Queue underflow\n";
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