#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void solve(vector<int>&nums, int&max) {
  
  for(int i = 0; i < nums.size(); i++) {
    // Update the current maximum if the current element is greater
    if(nums[i] > max) {
      max = nums[i];
    }
    
    int maxi = nums[i]; // Initialize a variable to track the maximum sum ending at index i
    
    for(int j = i+1; j < nums.size(); j++) {
      maxi += nums[j]; // Add the next element to the current subarray sum
      
      if(maxi > max) {
        max = maxi;
      }
    }
  }
}


int main() {
  vector<int> nums = {-2,1};
  
  int max = INT_MIN;

  solve(nums, max);
  cout << max;
}