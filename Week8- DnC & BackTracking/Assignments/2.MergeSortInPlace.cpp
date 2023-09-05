#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>&arr, int start, int end) {
    
  int pivot = start;
  int pivotRightIndex = start;
  for(int i = pivot+1; i <= end; i++) {
    if(arr[i] <= arr[pivot]) {
      pivotRightIndex++;
    }
  }

  swap(arr[pivot], arr[pivotRightIndex]);

  int i = start;
  int j = pivotRightIndex;
  while(i < pivotRightIndex && j > pivotRightIndex) {
    while(arr[i] <= arr[pivotRightIndex]) {
      i++;
    }
    while(arr[j] > arr[pivotRightIndex]) {
      j--;
    }

    if(i < pivotRightIndex && j > pivotRightIndex) {
      swap(arr[i], arr[j]);
    }
  }

  return pivotRightIndex;
}

void quickSort(vector<int>&arr, int start, int end) {

  //base case
  if(start >= end) return;

  int pivotRightIndex = partition(arr, start, end);

  //leftPart
  quickSort(arr, start, pivotRightIndex-1);

  //rightPart
  quickSort(arr, pivotRightIndex+1, end);
  
}

void merge(vector<int>&arr, int start, int mid, int end) {
  int i = start; //iterator of leftPart
  int j = mid+1; //iterator of rightPart
  
  while(i <= mid) {
    if(arr[i] <= arr[j]) {
      i++;
    }
    else {
      swap(arr[i], arr[j]);
      i++;
      quickSort(arr, j, end);
    }
  }
}

void mergeSort(vector<int>&arr, int start, int end) {
  //base case
  if(start >= end) {
    return;
  }

  int mid = start+(end-start)/2;
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