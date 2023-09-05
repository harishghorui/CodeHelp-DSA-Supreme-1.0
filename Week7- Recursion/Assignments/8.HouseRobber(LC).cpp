#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums, int i) {
  //base case
  if(i >= nums.size()) return 0;

  //ek case solve + RE dek lega
  int profit1 = nums[i] + rob(nums, i+2);
  int profit2 = rob(nums, i+1);

  return max(profit1, profit2);
}

int main() {

  //House Robber - LeetCode
  vector<int> nums = {2,7,9,3,1};

  int maxProfit = rob(nums, 0);
  cout << "Max Profit: " << maxProfit << endl;
}