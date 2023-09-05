#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxCBS(vector<int>&nums, int&start, int&mid, int&end) {
  int maxLeftBorderSum = INT_MIN;
  int maxRightBorderSum = INT_MIN;

  //left max
  int localLeftMax = 0;
  for(int i = mid; i >= start; i--) {
    localLeftMax += nums[i];
    if(localLeftMax > maxLeftBorderSum) {
      maxLeftBorderSum = localLeftMax;
    }
  }

  //right max
  int localRightMax = 0;
  for(int i = mid+1; i <= end; i++) {
    localRightMax += nums[i];
    if(localRightMax > maxRightBorderSum) {
      maxRightBorderSum = localRightMax;
    }
  }

  return maxLeftBorderSum + maxRightBorderSum;
  
}

int maxSubArrayHelper(vector<int>&nums, int start, int end) {
  //base case
  if(start >= end) {
    return nums[start];
  }

  int mid = start + ((end - start) >> 1); //right shift to divide by 2
  
  //left part
  int maxLeftSum = maxSubArrayHelper(nums, start, mid);

  //right part
  int maxRightSum = maxSubArrayHelper(nums, mid+1, end);

  int maxCrossBorderSum = maxCBS(nums, start, mid, end);

  return max(maxLeftSum, max(maxRightSum, maxCrossBorderSum));
}

int main() {
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  int start = 0;
  int end = nums.size()-1;

  cout << maxSubArrayHelper(nums, start, end);

}