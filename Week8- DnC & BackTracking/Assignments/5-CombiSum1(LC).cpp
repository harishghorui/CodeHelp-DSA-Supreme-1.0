#include <iostream>
#include <vector>
using namespace std;

void solveCombinationSum(vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>&output, int index) {

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
    solveCombinationSum(arr, target-arr[index], ans, output, index);

    //backtracking
    output.pop_back();
    index++;
  }
}

int main() {
  vector<int> candidates = {2,3,5};
  int target = 8;

  vector<vector<int>> ans;
  vector<int> output;

  solveCombinationSum(candidates, target, ans, output, 0);

  for(int i = 0; i < ans.size(); i++) {
    for(int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}