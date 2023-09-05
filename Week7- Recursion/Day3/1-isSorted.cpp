#include <iostream>
using namespace std;

bool isSorted(int arr[], int i, int n) {
  if(i >= n) return true;

  if(arr[i-1] > arr[i]) {
    return false;
  }
  
  return isSorted(arr, i+1, n);
}

int main() {
  int arr[4] = {10,12,14,13};
  int n = 4;
  int i = 1;
  
  if(isSorted(arr, i, n)) {
    cout << "Array Sorted";
  }
  else {
    cout << "Not Sorted";
  }
}