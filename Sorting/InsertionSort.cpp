#include<iostream>
using namespace std;

/** Insertion Sort - One element from the collection is consumed in each iteration to find its correct position
 * i.e. the position to which it belongs in sorted array
 * @param - array and size
 * Complexity - O(N^2)
 */
void insertionSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int temp = arr[i], j = i;
        while(j > 0 && temp < arr[j - 1]) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main() {
    int arr[] = { 3, 4, 1, 2, 5, 7, 6, 8, 10, 9 };
    int n = 10;
    display(arr, n);
    insertionSort(arr, n);
    display(arr, n);
    return 0;
}
