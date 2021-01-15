#include<iostream>
using namespace std;

/** Counting Sort
 * Complexity - O(N + K) where N is size of array and K is size of auxiliary array
 */
void countingSort(int arr[], int sortedArr[], int n) {
    int max = 0, j = 0;

    for(int i = 0; i < n; i++) {
        if(max < arr[i])
            max = arr[i];
    }

    int aux[max + 1];
    memset(aux, 0 , sizeof(aux));
    for(int i = 0; i < n; i++) {
        aux[arr[i]]++;
    }

    for(int i = 0; i <= max; i++) {
        int temp = aux[i];
        while(temp--) {
            sortedArr[j] = i;
            j++;
        }
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int arr[] = { 3, 4, 1, 2, 5, 7, 6, 8, 10, 9, 3 };
    int n = 11;
    int sortedArr[n];
    display(arr, n);
    countingSort(arr, sortedArr, n);
    cout<<"Counting Sort:\n";
    display(sortedArr, n);
    return 0;
}