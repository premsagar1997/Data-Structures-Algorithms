#include<iostream>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/** Selection Sort - algorithm is based on the idea of finding the minimum or maximum element in an unsorted array
 * and then putting it in its correct position in a sorted array. 
 * @param - array, and size
 * Complexity - O(N^2)
 */
void selectionSort(int arr[], int n) {
    int min;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i], &arr[min]);
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
    selectionSort(arr, n);
    display(arr, n);
    return 0;
}