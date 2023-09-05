#include <iostream>
#include <vector>
using namespace std;

int findPivotElement(vector<int> arr) {
  int start = 0;
  int end = arr.size()-1;
  int mid = start + (end-start)/2;

  while(start <= end) {
    if(mid-1 >= 0 && arr[mid] > arr[mid+1]) {
      return arr[mid];
    }
    else if(mid+1 < arr.size() && arr[mid] < arr[mid-1]) {
      return arr[mid-1];
    }
    else if(arr[mid] >= arr[start]) {
      start = mid+1;
    }
    else if(arr[mid] <= arr[end]) {
      end = mid-1;
    }
    mid = start + (end-start)/2;
  }

  return -1;
}

// Search in Rotated Sorted Array- Leetcode

double findSqrt(int target, int precision) {
  int start = 0;
  int end = target;
  int mid = start + (end-start)/2;
  double ans;

  //integer part
  while(start <= end) {
    if(mid*mid == target) {
      ans = mid;
      break;
    }
    else if(mid*mid > target) {
      end = mid - 1;
    }
    else {
      ans = mid;
      start = mid + 1;
    }
    mid = start + (end-start)/2;
  }

  //precision part
  double step = 0.1;
  for(int i = 0; i < precision; i++) {
    for(double j = ans; j*j <= target; j += step) {
      ans = j;
    }
    step /= 10;
  }
  
  return ans;
}

int binarySearch2Darray(int matrix[][4], int row, int col, int target) {
  int start = 0;
  int end = row*col-1;
  int mid = start + (end-start)/2;

  while(start <= end) {
    int rowIndex = mid/col;
    int colIndex = mid%col;
    int element = matrix[rowIndex][colIndex];
    
    if(element == target) {
      return mid;
    }
    else if(element < target) {
      start = mid + 1;
    }
    else {
      end = mid - 1;
    }
    mid = start + (end-start)/2;
  }

  return -1;
}

int main() {
  
  // Binary Search in 2D Array
  int matrix[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  int row = 3;
  int col = 4;
  int totalElements = row*col;
  int target = 12;

  int ans = binarySearch2Darray(matrix, row, col, target);
  
  if(ans >= 0) {
    cout << "Target Found at Index: "<< ans;
  }
  else {
    cout << "Target Not Found";
  }
  
  // Find Square Root
  /*
  int n, precision;
  cout << "Enter Number: ";
  cin >> n;

  cout << "Enter Precision: ";
  cin >> precision;

  cout << "Sqrt Root of " << n << " is: " << findSqrt(n,precision);
  */

  // Find Pivot Element
  /*
  vector<int> arr = {6,7,1,2,3,4,5,6};

  int ans = findPivotElement(arr);
  if(ans >= 0) {
    cout << "Pivot ELement is: " << ans;
  }
  else {
    cout << ans;
  } */
  
}