#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void solveCombinationSum2(vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& output, int index) {
  
  // Base case
  if(target <= 0) {
    if(target == 0) {
      ans.push_back(output);
    }
    return;  // Regardless of the outcome, return from the current recursive call
  }

  //here mapping method can also be used-->>
  for(int i = index; i < arr.size(); i++) {
    // If the remaining target would become negative, skip this candidate
    if(target + arr[i] < 0) {
      break;
    }
    // Skip duplicate numbers to avoid duplicate combinations
    if(i > index && arr[i] == arr[i-1]) {
      continue;
    }
    
    output.push_back(arr[i]);
    // Recurse with reduced target and move to the next index
    solveCombinationSum2(arr, target - arr[i], ans, output, i + 1);
    
    // Backtrack: Remove the last element from the combination
    output.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector<vector<int>> ans;
  vector<int> output;
  
  solveCombinationSum2(candidates, target, ans, output, 0);

  return ans;
}

int main() {
  vector<int> candidates = {10,1,2,7,6,1,5};
  int target = 8;
  vector<vector<int>> ans = combinationSum2(candidates, target);

  for(int i = 0; i < ans.size(); i++) {
    for(int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}