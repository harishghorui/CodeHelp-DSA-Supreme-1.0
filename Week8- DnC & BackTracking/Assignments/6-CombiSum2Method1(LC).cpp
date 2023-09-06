#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void solveCombinationSum2(vector<int>& arr, int target, vector<vector<int>>&ans, vector<int>&output, int index) {
  //base case
  if(target <= 0) {
    if(target == 0) {
      ans.push_back(output);
    }
    return;
  }

  //ek case
  while(index < arr.size()) {
    output.push_back(arr[index]);
    solveCombinationSum2(arr, target-arr[index], ans, output, index+1);
    output.pop_back();
    index++;
  }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector<vector<int>> ans;
  vector<int> output;
  
  solveCombinationSum2(candidates, target, ans, output, 0);
  set<vector<int>> st;
  for(auto i : ans) {
    st.insert(i);
  }
  ans.clear();
  for(auto i : st) {
    ans.push_back(i);
  }
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