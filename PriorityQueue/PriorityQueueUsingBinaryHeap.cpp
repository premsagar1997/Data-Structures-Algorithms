//Priority queue implementation using binary heap
#include<iostream>
using namespace std;

int heap[100];
int size = -1;

void shiftUp(int i);
void shiftDown(int i);
int parent(int i);
int leftChild(int i);
int rightChild(int i);
void insertNode(int x);
void deleteNode();
void display();

//It will return index of the parent node of the given node
int parent(int i) {
  return (i-1)/2;
}

//It will return index of the left child of the given node
int leftChild(int i) {
  return (2*i)+1;
}

//It will return index of the right child of the given node
int rightChild(int i) {
  return (2*i)+2;
}

//funtion to shift up the node to maintain the heap property
//time complexity - O(logN)
void shiftUp(int i) {
  while(i > 0 && heap[parent(i)] < heap[i]) {
    int p = parent(i);
    int temp = heap[p];
    heap[p] = heap[i];
    heap[i] = temp;
    i = p;
  }
}

//funtion to shift down the node to maintain the heap property
//time complexity - O(logN)
void shiftDown(int i) {
  int index = i;
  int left = leftChild(i);
  int right = rightChild(i);
  
  if (left <= size && heap[left] > heap[index]) {
    index = left;
  }

  if (right <= size && heap[right] > heap[index]) {
    index = right;
  }

  if(i != index) {
    int temp = heap[i];
    heap[i] = heap[index];
    heap[index] = temp;
    shiftDown(index);
  }
}

//funtion to insert element  in the binary heap
//time complexity - O(logN)
void insertNode(int x) {
  size = size + 1;
  heap[size] = x;
  shiftUp(size);
}

//funtion to remove element having highest priority
//time complexity - O(logN)
void deleteNode() {
  if (size == -1) {
    cout<<"Queue is empty"<<endl;
    return;
  }
  int x = heap[0];
  heap[0] = heap[size];
  size = size - 1;
  shiftDown(0);
  cout<<"Element with highest priority is deleted: "<<x<<endl;
}

//Funtion to diplay element
void display() {
  if (size == -1) { //if queue is empty
    cout<<"Queue is empty"<<endl;
    return;
  }
  for (int i = 0; i <= size; i++) {
    cout<<heap[i]<<" ";
  }
  cout<<endl;
}

int main() {
  int ch, x, y;
  do {
    cout<<"\n1->Equeue\n2->Dequeue\n3->Display\n4->Exit\n";
    cin>>ch;
    switch(ch) {
      case 1:
        cout<<"Enter element: ";
        cin>>x;
        insertNode(x);
        break;
      case 2:
        deleteNode();
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
        break;
      default:
        cout<<"Invalid option!!!"<<endl;
        break;
    }
  } while(ch != 4);
  return 0;
}
