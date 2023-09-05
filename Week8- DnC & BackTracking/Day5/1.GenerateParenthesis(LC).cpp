#include <iostream>
#include <vector>
using namespace std;

void solveParenthesis(int n, int open, int close, vector<string>&ans, string output) {
  //base case
  if(open == 0 && close == 0) {
    ans.push_back(output);
    return;
  }

  //ek case
  //include '(' -->>
  if(open > 0) {
    output.push_back('(');
    solveParenthesis(n, open-1, close, ans, output);

    //backtracking
    output.pop_back();
  }

  //include ')' -->>
  if(open < close) {
    output.push_back(')');
    solveParenthesis(n, open, close-1, ans, output);

    //backtracking
    output.pop_back();
  }
  
}

int main() {
  int n = 3; // (n) pairs of parenthesis
  //generate all combinations

  int open = n; //count of '(' open bracket
  int close = n; //count of ')' close bracket
  vector<string> ans;
  string output = "";
  
  solveParenthesis(n, open, close, ans, output);

  for(auto i : ans) {
    cout << i << ", ";
  }
}