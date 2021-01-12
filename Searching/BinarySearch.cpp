#include<iostream>
using namespace std;

/** Recursive Implementation of Binary Search
 * Binary Search - algorithm that finds the position of a target value within a sorted array
 * @param - array, left bound, right bound, element
 * @return - position of target value
 * Complexity - O(log N)
 */
int binarySearch(int arr[], int l, int r, int item) {
    if(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == item)
            return mid;
        else if(arr[mid] > item)
            return binarySearch(arr, l, mid - 1, item);
        else if(arr[mid] < item)
            return binarySearch(arr, mid + 1, r, item);
    }
    return -1;
}

/** Iterative Implementation of Binary Search
 * Binary Search - algorithm that finds the position of a target value within a sorted array
 * @param - array, left bound, right bound, element
 * @return - position of target value
 * Complexity - O(log N)
 */
int binary_search(int arr[], int l, int r, int item) {
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == item)
            return mid;
        else if(arr[mid] > item)
            r = mid - 1;
        else if(arr[mid] < item)
            l = mid + 1;
    }
    return -1;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int item = 2, n = 9;
    int index = binary_search(arr, 0, n - 1, item);
    int index1 = binarySearch(arr, 0, n - 1, item);
    if(index == -1)
        cout<<"Item not found"<<endl;
    else
        cout<<"Item found at index: "<<index<<endl;
    return 0;
}