#include <iostream>
using namespace std;

void printPermutation(string& str, int i) {
  //base case
  if(i >= str.length()) {
    cout << str << " ";
    return;
  }

  for(int j = i; j < str.length(); j++) {
    //ek case-> swap
    swap(str[j], str[i]);

    //RE
    printPermutation(str, i+1);

    //backtracking-> to recreate the original input string
    swap(str[j], str[i]);
  }

}

int main() {
  string str = "abcd";

  printPermutation(str, 0);
}