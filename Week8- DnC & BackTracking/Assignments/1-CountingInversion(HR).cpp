#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays and count inversions
long merge(vector<int>& arr, int s, int mid, int e, vector<int>& temp) {
  long count = 0; // Initialize inversion count
  int k = s; // Index for the temporary array
  int i = s; // Index for the left subarray
  int j = mid + 1; // Index for the right subarray

  // Merge the two subarrays
  while (i <= mid && j <= e) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      // Inversion found, add count of inversions
      count += mid - i + 1;
      temp[k++] = arr[j++];
    }
  }

  // Copy any remaining elements from the left subarray
  while (i <= mid) {
    temp[k++] = arr[i++];
  }

  // Copy any remaining elements from the right subarray
  while (j <= e) {
    temp[k++] = arr[j++];
  }

  // Copy merged elements back to the original array
  while (s <= e) {
    arr[s] = temp[s];
    s++;
  }

  return count; // Return the total count of inversions
}

// Merge sort function
long mergeSort(vector<int>& arr, int s, int e, vector<int>& temp) {
  long count = 0; // Initialize inversion count
  
  // Base case: If subarray has only one element or no elements, return 0
  if (s >= e) {
    return 0;
  }

  int mid = s + (e - s) / 2; // Calculate the middle index

  // Recursively sort and count inversions in the left and right subarrays
  count += mergeSort(arr, s, mid, temp); // Sort left subarray
  count += mergeSort(arr, mid + 1, e, temp); // Sort right subarray

  // Merge the two sorted subarrays and count inversions
  count += merge(arr, s, mid, e, temp);

  return count; // Return the total count of inversions for this subarray
}

int main() {
  vector<int> arr = {8,4,2,1};
  int n = arr.size();
  int s = 0;
  int e = n-1;
  vector<int> temp(arr.size(), 0);
  long count = mergeSort(arr, s, e, temp);

  cout << count;
}