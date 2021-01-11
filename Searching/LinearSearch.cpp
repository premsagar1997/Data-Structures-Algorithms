#include<iostream>
using namespace std;

/** Task: It will search item in array. If item is present then return its position else return -1
 * @param array, size and item
 * @return int i.e. position
 * Complexity: O(N)
 */
int linearSearch(int arr[], int n, int item) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == item)
            return i;
    }
    return -1;
}

/** Task: Improve linear search complexity i.e. worst-case complexity
 * If element not found - improve complexity from O(N) to O(N/2)
 * If element found at last index - improve complexity fromO(N) to O(1)
 * @param array, size and item
 * @return int i.e. index
 */
int improvedLinearSearch(int arr[], int n, int item) {
    int index = -1, left = 0, right = n - 1;
    while(left <= right) {
        //check in left half section of array
        if(arr[left] == item) {
            index = left;
            break;
        }

        //check in right half section of array
        if(arr[right] == item) {
            index = right;
            break;
        }

        left++;
        right--;
    }
    return index;
}

int main() {
    int arr[] = { 41, 32, 23, 4, 52, 96, 97, 48, 9 };
    int item = 52;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = linearSearch(arr, n, item);
    int index1 = improvedLinearSearch(arr, n, item);
    if(index == -1)
        cout<<"Item not found"<<endl;
    else
        cout<<"Item found at index: "<<index<<endl;
    return 0;
}