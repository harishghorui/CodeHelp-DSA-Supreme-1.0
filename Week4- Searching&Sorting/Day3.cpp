#include <iostream>
#include <vector>
using namespace std;

int searchInNearlySortedArray(vector<int> arr, int target) {
  int start = 0;
  int end = arr.size()-1;
  int mid = start + (end-start)/2;

  while(start < end) {
    if(arr[mid] == target) {
      return mid;
    }
    else if(mid+1 < arr.size() && arr[mid+1] == target) {
      return mid+1;
    }
    else if(mid-1 >= start && arr[mid-1] == target) {
      return mid-1;
    }
    else if(target > arr[mid]) {
      start = mid+2;
    }
    else {
      end = mid-2;
    }
    mid = start + (end-start)/2;
  }
  return -1;
}

int findQuotient(int divident, int divisor) {
  int start = 0;
  int end = abs(divident);
  int mid = start + (end-start)/2;
  //mid = quotient;

  int ans = 1;
  while(start <= end) {
    if(abs(mid*divisor) == abs(divident)) {
      ans = mid;
      break;
    }
    else if(abs(mid*divisor) > abs(divident)) {
      end = mid - 1;
    }
    else {
      ans = mid;
      start = mid + 1;
    }
    mid = start + (end-start)/2;
  }

  if((divident>0 && divisor>0) || (divident<0 && divisor<0)) {
    return ans;
  }
  else {
    return -ans;
  }
}

int findEvenPair(vector<int> pairs) {
  int start = 0;
  int end = pairs.size()-1;
  int mid = start + (end-start)/2;

  int ans;
  while(start <= end) {
    //if there is single index in arr- return
    if(start == end) {
      return start;
    }

    //observation- pairs in left side of ans is in index even-odd
    else if(mid % 2 == 0) {
      if(pairs[mid] == pairs[mid+1]) {
        start = mid + 2;
      }
      else {
        end = mid;
      }
    }

    //observation- pairs in right side of ans is in index odd-even
    else {
      if(pairs[mid] == pairs[mid-1]) {
        start = mid + 1;
      }
      else {
        end = mid - 1;
      }
    }
    mid = start + (end-start)/2;
  }
  return ans;
}

int main() {

  vector<int> pairs = {1,1,2,2,600,3,3,4,4,3,3,4,4};
  int ans = findEvenPair(pairs);

  cout << "Found at Index: " <<ans;
  
  // Divide 2 Numbers using Binary Search
  /*
  int divident = -21;
  int divisor = 7;

  int ans = findQuotient(divident, divisor);
  cout << "Found Answer: " << ans;
  */
  
  //Binary Search in a Nearly Sorted Array
  /*
  vector<int> arr = {10,3,40,20,50,80,70};
  int target = 100;

  int ans = searchInNearlySortedArray(arr, target);
  if(ans >= 0) {
    cout << "Found Target at Index: " << ans;
  }
  else {
    cout << "Not Found";
  } */
  
  return 0;
}