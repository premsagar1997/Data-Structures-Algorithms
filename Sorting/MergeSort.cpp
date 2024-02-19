//Time Complexity - O(N log N)
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int lb, int mid, int ub) {
    int n1 = mid - lb + 1;
    int n2 = ub - mid;
    
    int L[n1];
    int R[n2];
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[lb + i];
    }
    
    for (int i = 0; i < n1; i++) {
        R[i] = arr[mid + i + 1];
    }
    
    int i = 0;
    int j = 0;
    int k = lb;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    //copy remaining element
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    //copy remaining element
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}


int main() {
    int arr[] = { 12, 23, 21, 11, 24, 20, 35, 25 };
    int len = 8;
    
    //Call Merge short
    mergeSort(arr, 0, 7);
    
    for (int i = 0; i < len; i++) {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    
    return 0;
}
