#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int &key, int s, int e) {
  if (s > e)
    return -1; // base case, key not found

  int mid = (s + e) / 2;
  if (arr[mid] == key) { // recursive relation
    return mid;
  }

  if (arr[mid] < key) { // right search
    return binarySearch(arr, key, mid + 1, e);
  } else { // left search
    return binarySearch(arr, key, s, mid - 1);
  }
}

int main() {
  vector<int> arr = {12, 13, 16, 20, 30, 49}; // sorted array
  int n = arr.size();
  int key = 30;
  int start = 0;
  int end = n - 1;

  int ans = binarySearch(arr, key, start, end);
  cout << ans;
}