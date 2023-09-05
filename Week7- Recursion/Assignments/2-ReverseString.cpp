#include <iostream>
using namespace std;

void reverseString(string &str, int start, int end) {
  // base case
  if (start >= end)
    return;

  // ek case solve
  swap(str[start], str[end]);

  // recursion dek lega
  reverseString(str, start + 1, end - 1);
}

int main() {
  string str = "ghorui";
  int start = 0;
  int end = str.size() - 1;

  reverseString(str, start, end);
  cout << str;
}