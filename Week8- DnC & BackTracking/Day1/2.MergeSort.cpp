#include <iostream>
#include <vector>
using namespace std;

void merge(int* arr, int s, int e) {
  int mid = (s+e)/2;

    int length1 = mid - s + 1;
    int length2 = e - mid;

  //new array to copy
  int* left = new int[length1];
  int* right = new int[length2];

  int k = s;
  for(int i = 0; i < length1; i++) {
    left[i] = arr[k];
    k++;
  }
  //k = mid + 1; //try not updating
  for(int i = 0; i < length2; i++) {
    right[i] = arr[k];
    k++;
  }

  //merge logic
  int leftIndex = 0; // pointers to iterate both temp arrays
  int rightIndex = 0;
  int mainArrayIndex = s;

  while(leftIndex < length1 && rightIndex < length2) {
    if(left[leftIndex] < right[rightIndex]) {
      arr[mainArrayIndex++] = left[leftIndex++];
    }
    else {
      arr[mainArrayIndex++] = right[rightIndex++];
    }
  }

  //incase of array(leftArray) is empty
  while(leftIndex < length1) {
    arr[mainArrayIndex++] = left[leftIndex++];
  }
  while(rightIndex < length2) {
    arr[mainArrayIndex++] = right[rightIndex++];
  }
}

void mergeSort(int* arr, int s, int e) {
  //base case- if (s==e) or (s > e)
  if(s >= e) return;

  int mid = (s + e) / 2;
  //ek case
  //left part solve karega RE
  mergeSort(arr, s, mid);

  //right part solve karega RE
  mergeSort(arr, mid+1, e);

  //merge kar sorting k saath
  merge(arr, s, e);
}

int main() {
  int arr[] = {4,13,5,2,12};
  int n = sizeof(arr) / sizeof(arr[1]);
  int s = 0;
  int e = n-1;

  mergeSort(arr, s, e);
  for(auto i : arr) {
    cout << i << " ";
  }
}