#include <iostream>
using namespace std;

bool checkPalindrome(string&s, int start, int end) {
  //base case
  if(start >= end) {
    return true;
  }

  //ek case
  if(s[start] != s[end]) {
    return false;
  }

  //RE dek lega
  return checkPalindrome(s, start+1, end-1);
}

int main() {
  string s = "racetar";

  if(checkPalindrome(s, 0, s.size()-1)) {
    cout << "Palindrome";
  }
  else {
    cout << "Not Palindrome";
  }

  return 0;
}