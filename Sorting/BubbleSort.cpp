//Bubble Sort
#include<iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/** Bubble Sort - It repeatedly swapping the adjacent elements if they are in wrong order
 * @param - array and array size
 * @return - void
 * Complexity - O(N^2)
 */
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

/** Optimized Bubble Sort -
 * Bubble sort algorithm can be optimized by stopping the algorithm if inner loop do not cause any swap operation
 * Complexity - Worst & Average Case - O(N^2)
 * Average Case - O(N), if array is already sorted
 */
void bubbl_sort(int arr[], int n) {
    bool flag;
    for (int i = 0; i < n - 1; i++) {
        flag = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = { 3, 4, 1, 2, 5, 7, 6, 8, 10, 9 };
    int n = 10;
    display(arr, n);
    bubbleSort(arr, n);
    display(arr, n);

    int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n1 = 10;
    display(arr1, n1);
    bubbl_sort(arr1, n1);
    display(arr1, n1);
    return 0;
}