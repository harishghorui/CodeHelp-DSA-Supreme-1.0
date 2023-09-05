#include <iostream>
#include <vector>
using namespace std;

void printSubsequence(string &str, string output, int i, vector<string>& v) {
  //base case
  if(i >= str.size()) {
    v.push_back(output);
    return;
  }
  
  // exclude str in output
  printSubsequence(str, output, i+1, v);

  // include srt in output
  // output.push_back(str[i]);
  // printSubsequence(str, output, i+1, v);
  printSubsequence(str, output + str[i], i+1, v);
}

int main() {
  string str = "abcd";
  string output = " ";
  int i = 0;
  vector<string> v;
  
  printSubsequence(str, output, i, v);

  for(auto val : v) {
    cout << val << endl;
  }
}