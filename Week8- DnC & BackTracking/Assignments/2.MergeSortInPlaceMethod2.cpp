#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void merge(vector<int>&arr, int start, int mid, int end) {
  int totalSize = end - start + 1;
  // int gap = ceil(total_len/2);
  int gap = (totalSize/2) + (totalSize%2);
  
  while(gap > 0) {
    int i = start;
    int j = start + gap;
    while(j <= end) {
      if(arr[i] > arr[j]) {
        swap(arr[i], arr[j]);
      }
      i++;
      j++;
    }
    // gap = gap <= 1 ? 0 : ceil(gap/2);
    gap = gap <= 1 ? 0 : (gap/2) + (gap%2);
  }
}

void mergeSort(vector<int>&arr, int start, int end) {
  //base case
  if(start >= end) {
    return;
  }

  int mid = (start + end) >> 1;
  //leftPart
  mergeSort(arr, start, mid);

  //rightpart
  mergeSort(arr, mid+1, end);

  //merge 2 sorted arrays
  merge(arr, start, mid, end);
}

int main() {
  vector<int> arr = {10,6,9,5,2,7};
  int start = 0;
  int end = arr.size()-1;

  mergeSort(arr, start, end);
  for(auto i : arr) {
    cout << i << " ";
  }
}