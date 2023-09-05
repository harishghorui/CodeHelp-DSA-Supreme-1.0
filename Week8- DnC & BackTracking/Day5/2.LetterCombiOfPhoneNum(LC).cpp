#include <iostream>
#include <vector>
using namespace std;

void combination(string digits, int index, string output, vector<string>& ans, vector<string>&mapping) {

  //base case
  if(index >= digits.length()) {
    ans.push_back(output);
    return;
  }

  //ek case- >> include index
  int singleDigit = digits[index] - '0';
  string numValue = mapping[singleDigit];
  
  for(int i = 0; i < numValue.length(); i++) {
    //including index
    output.push_back(numValue[i]);

    //RE-->> including index of next number
    combination(digits, index+1, output, ans, mapping);

    //backtracking
    output.pop_back();
  }
}

int main() {
  // Letter Combinations of a Phone Number (LC)
  string digits = "235";
  vector<string> ans;

  //handling edge case-->>
  if(digits.length() == 0) {
    cout << "No Combination";
    return 0;
  }
  
  int index = 0;
  string output = "";

  vector<string> mapping(10);
  mapping[2] = "abc";
  mapping[3] = "def";
  mapping[4] = "ghi";
  mapping[5] = "jkl";
  mapping[6] = "mno";
  mapping[7] = "pqrs";
  mapping[8] = "tuv";
  mapping[9] = "wxyz";

  combination(digits, index, output, ans, mapping);

  for(auto i : ans) {
    cout << i << " ";
  }
}