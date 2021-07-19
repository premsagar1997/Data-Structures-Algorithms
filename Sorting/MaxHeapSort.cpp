/** Heap Sort
 * Time complexity of heapify is O(logN).
 * Time complexity of create and build heap is O(N)
 * Overall time complexity of Heap Sort is O(NlogN)
 */

#include<iostream>
#include<cmath>
using namespace std;

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = (i*2)+1;
  int right = (i*2)+2;

  if (left < n && arr[left] > arr[largest])
    largest = left;
  
  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (i != largest) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  //building max heap
  for (int i = n/2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  //deleting element
  for (int i = n - 1; i >= 0; i--) {
    //swap root node element with last node element
    int temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;
    //after deletion, heap property is disturbed, so call heapify at root node
    heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = { 36, 23, 10, 8, 4, 33, 25, 11, 22, 7, 20 };
  int n = 11;
  heapSort(arr, n);
  for (int i = 0; i < n; i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  return 0;
}