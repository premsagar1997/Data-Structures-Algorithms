/**
  Time Complexity-
  Best case: O(N log (N))
  Average case: O( N log (N))
  Worst case: O(n^2)
  */

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    
    while (start < end) {
        while (arr[start]<= pivot) {
            start++;
        }
        
        while (arr[end] > pivot) {
            end--;
        }
        
        if (start < end) {
          swap(arr[start], arr[end]);  
        }
    }
    
    swap(arr[lb], arr[end]);
    
    return end;
}

void quickSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int pi = partition(arr, lb, ub);
        quickSort(arr, lb, pi - 1);
        quickSort(arr, pi + 1, ub);
    }
}


int main() {
    int arr[] = { 12, 23, 21, 11, 24, 20, 35, 25 };
    int len = 8;
    
    //Call Quick short
    quickSort(arr, 0, 7);
    
    for (int i = 0; i < len; i++) {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    
    return 0;
}
