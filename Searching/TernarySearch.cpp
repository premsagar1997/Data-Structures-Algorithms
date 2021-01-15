#include<iostream>
using namespace std;

/** Ternary Search - 
 * @param - array, lower bound, upper bound and element
 * @return - position of target element
 * Complexity - O(log3 N)
 */
int ternarySearch(int arr[], int l, int r, int x) {
    if(r >= l) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        if(arr[m1] == x)
            return m1;
        if(arr[m2] == x)
            return m2;
        if(x < arr[m1])
            return ternarySearch(arr, l, m1 - 1 , x);
        else if(x > arr[m2])
            return ternarySearch(arr, m2 + 1, r, x);
        else
            return ternarySearch(arr, m1 + 1, m2 - 1, x);
    }
    return -1;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int item = 3, n = 9;
    int index = ternarySearch(arr, 0, n - 1, item);
    if(index == -1)
        cout<<"Item not found"<<endl;
    else
        cout<<"Item found at index: "<<index<<endl;
    return 0;
}