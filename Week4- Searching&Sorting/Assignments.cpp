#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int bsFindX(vector<int> nums, int start, int x) {
  int end = nums.size()-1;
  int mid = start + (end-start)/2;

  while(start <= end) {
    if(nums[mid] == x) {
      return mid;
    }
    else if(nums[mid] > x) {
      end = mid - 1;
    }
    else {
      start = mid + 1;
    }
    mid = start + (end-start)/2;
  }
  return -1;
}
int findKDiffPairs(vector<int> nums, int k) {
  // sort(nums.begin(), nums.end());
  // set<pair<int,int>> ans;
  
  // for(int i = 0; i < nums.size(); i++) {
  //   //searching k+i with BinarySearch
  //   if(bsFindX(nums, i+1, k+nums[i]) >= 0) {
  //     ans.insert(nums[i], nums[i]+k);
  //   }
  // }
  // return ans.size();
  return 0;
}

vector<int> findKClosestTwoPointerMethod(vector<int> arr, int k, int x) {
  int low = 0;
  int high = arr.size()-1;

  while(high-low >= k) {
    if(x - arr[low] > arr[high] - x) {
      low++;
    }
    else {
      high--;
    }
  }
  vector<int> ans;
  for(int i = low; i <= high; i++) {
    ans.push_back(arr[i]);
  }
  return ans;
}

int findLowerBound(vector<int> arr, int x) {
  int start = 0;
  int end = arr.size()-1;
  int mid = start + (end-start)/2;

  int ans = end;
  while(start <= end) {
    if(arr[mid] >= x) {
      end = mid - 1;
      ans = mid;
    }
    else if(arr[mid] < x) {
      start = mid + 1;
    }
    else {
      end = mid - 1;
    }
    mid = start + (end-start)/2;
  }
  return ans;
}
vector<int> findKClosestBSMethod(vector<int> arr, int k, int x) {
  int high = findLowerBound(arr, x);
  int low = high - 1;

  while(k--) {
    if(low < 0) {
      high++;
    }
    else if(high >= arr.size()) {
      low--;
    }
    else if(x - arr[low] > arr[high] - x) {
      high++;
    }
    else {
      low--;
    }
  }
  return vector<int> (arr.begin() + low + 1, arr.begin() + high);
}

int main() {

  //Find K- closest Elements - Method 2
  vector<int> arr = {1,2,3,4,5};
  int x = 3;
  int k = 4;
  
  vector<int> ans = findKClosestBSMethod(arr, k, x);
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  
  //Find K- closest Elements - Method 1
  /*
  vector<int> arr = {1,2,3,4,5};
  int x = 3;
  int k = 4;
  
  vector<int> ans = findKClosestTwoPointerMethod(arr, k, x);
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  } */
  
  //Find k- diffrence pairs in an Array- Leetcode 
  /*
  vector<int> nums = {3,1,4,1,5};
  int k = 2;

  findKDiffPairs(nums, k);
  */
}