#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void permutation(vector<int>& nums, vector<vector<int>>& ans, int i) {
  // Base case
  if (i >= nums.size()) {
    ans.push_back(nums);
    return;
  }

  unordered_map<int, bool> visited; // Keep track of visited numbers to avoid duplicates
  
  for (int j = i; j < nums.size(); j++) {
    if (visited.find(nums[j]) != visited.end()) {
      continue; // Skip if the number has been visited before in this iteration
    }
    
    visited[nums[j]] = true; // Mark the number as visited
    swap(nums[i], nums[j]); 
    permutation(nums, ans, i + 1);

    // Backtracking: revert the swap to explore other possibilities
    swap(nums[i], nums[j]);
  }
}


int main() {
  vector<int> nums = {0,0,3,0,3};
  vector<vector<int>> ans;
  
  permutation(nums, ans, 0);

  for(int i = 0; i < ans.size(); i++) {
    for(int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}