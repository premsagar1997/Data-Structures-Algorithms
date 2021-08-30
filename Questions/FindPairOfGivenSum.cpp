#include<iostream>
#include<unordered_set>
using namespace std;

//find pair of element of given sum in unsorted array
//time complexity - O(n)
//space complexity - O(n)
bool findPairInUnsortedArray(int arr[], int sum, int len) {
  unordered_set<int> st; //compliment

  for (int i = 0; i < len; i++) {
    if (st.find(arr[i]) != st.end())
      return true; //pair found

    st.insert(sum - arr[i]); //store complement of element in unordered set 
  }
  return false; //pair not found
}

//find pair of element of given sum in sorted array
//time complexity - O(n)
bool findPairInSortedArray(int arr[], int sum, int len) {
  int low = 0, high = len - 1;
  while (low < high) {
    int s = arr[low] + arr[high];
    if (s == sum)
      return true;
    else if (s > sum)
      high--;
    else if (s < sum)
      low++;
  }
  return false;
}

int main() {
  int arr[] = {1, 2, 3, 9};
  int arr1[] = {1, 2, 4, 4};
  int len = sizeof(arr)/sizeof(arr[0]);

  cout<<findPairInUnsortedArray(arr, 8, len)<<endl;
  cout<<findPairInUnsortedArray(arr1, 8, 4)<<endl;

  cout<<findPairInSortedArray(arr, 8, len)<<endl;
  cout<<findPairInSortedArray(arr1, 8, 4)<<endl;
}
