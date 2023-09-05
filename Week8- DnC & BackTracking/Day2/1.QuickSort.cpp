#include <iostream>
using namespace std;

int partition(int* arr, int low, int high) {
  //step1: choose Pivot Index
  int pivotIndex = low;

  //step2: find right position of Pivot Element and place it there
  int count = low;
  for(int i = low+1; i <= high; i++) {
    if(arr[i] <= arr[pivotIndex]) {
      count++;
    }
  }

  //after loop we will have correct index of Pivot Element, then swap
  swap(arr[count], arr[pivotIndex]);
  pivotIndex = count; //after swap, correct the Pivot Index by updating

  //step3: Place smaller in left of Pivot and bigger in right
  int i = low;
  int j = high;
  while(i < pivotIndex && j > pivotIndex) {
    while(arr[i] <= arr[pivotIndex]) {
      i++;
    }
    while(arr[j] > arr[pivotIndex]) {
      j--;
    }

    //2 cases ho sakte hai:
    //A->> found the element to swap
    //B->> No elements to swap
    if(i < pivotIndex && j > pivotIndex) {
      swap(arr[i], arr[j]);
    }
  }

  return pivotIndex;
}

void quickSort(int* arr, int low, int high) {
  //base case
  if(low >= high) return;

  //ek case= Partition logic-> return pivot Index
  int pivotIndex = partition(arr, low, high);

  //RE- Solve left part of pivotIndex
  quickSort(arr, low, pivotIndex-1);

  //RE- Solve right part of pivotIndex
  quickSort(arr, pivotIndex+1, high);
}

int main() {
  int arr[] = {8,1,3,4,1,4,4,4,3,3,20,50,30};
  // int n = sizeof(arr) / sizeof(arr[0]);
  int n = 13;
  int s = 0;
  int e = n-1;

  quickSort(arr, s, e);

  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}