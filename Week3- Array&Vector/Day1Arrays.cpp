#include <iostream>
#include <limits.h>
using namespace std;

bool linearSearch(int arr [], int size, int n) {
  
  for(int i = 0; i < size; i++) {
    if(arr[i] == n) {
      return true;
    }
  }
  return false;
}

void findZerosOnes(int arr [], int size) {
  int zeros = 0, ones = 0;
  for(int i = 0; i < size; i++) {
    if(arr[i] == 1) {
      ones++;
    }
    else if(arr[i] == 0) {
      zeros++;
    }
  }
  cout << "Zero's are: " << zeros << endl;
  cout << "One's are: " << ones;
}

void findMaxNum(int arr [], int elements) {
  int maxNum = INT_MIN;
  for(int i = 0; i < elements; i++) {
    if(arr[i] > maxNum) {
      maxNum = arr[i];
    }
  }
  cout << "Max Num in Array is: " << maxNum;
}

void findMinNum(int arr [], int elements) {
  int minNum = INT_MAX;
  for(int i = 0; i < elements; i++) {
    if(arr[i] < minNum) {
      minNum = arr[i];
    }
  }
  cout << "Min Num in Array is: " << minNum;
}

void extremePrint(int arr[], int size) {
  int left = 0, right = size-1;
  while(left <= right) {
    if(left == right) {
      cout << arr[left++] << " ";
    }
    else {
      cout << arr[left++] << " ";
      cout << arr[right--] << " ";
    }
  }
}

void reverseArray(int arr[], int size) {
  int left = 0, right = size-1;
  while(left <= right) {
    if(left == right) {
      break;
    }
    arr[left] = arr[left] + arr[right];
    arr[right] = arr[left] - arr[right];
    arr[left] = arr[left] - arr[right];
    left++;
    right--;
  }
  /*while(left <= right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    left++;
    right--;
  } */
  /*while(left <= right) {
    swap(arr[left], arr[right]);
    left++;
    right--;
  } */
  cout << "Reversed Array: ";
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}

int main() {

  // Reverse an Array
  int arr [10] = {10, 20, 30, 40, 50, 60, 70};
  int elements = 7;
  reverseArray(arr, elements);
  
  /* Extreme Print in Array
  int arr[10] = {-5, 10, -8, -1, 50};
  int elements = 5;
  extremePrint(arr, elements); */
  
  /*Find Max Num in Array
  int arr[10] = {-5, -10, -8, -1, -20};
  int elements = 5;
  findMinNum(arr, elements); */
  
  /*Find Max Num in Array
  int arr[10] = {-5, -10, -8, -1, -20};
  int elements = 5;
  findMaxNum(arr, elements); */
  
  /* Count 0's & 1's in array
  int arr[10] = {0, 1, 2, 1, 0, 3, 1, 1, 0, 1};
  int size = 10;
  findZerosOnes(arr, size); */
  
  /* Linear Search
  int arr [5] = {1, 2, 3, -88, 45};
  int size = 5;
  int n;
  cout << "Enter N: ";
  cin >> n;

  if(linearSearch(arr, size, n)) {
    cout << "Found";
  }
  else {
    cout << "Not Found";
  } */
  
  /* Initialization
  int n;
  cout << "Enter N: ";
  cin >> n;

  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  } */

  return 0;
}