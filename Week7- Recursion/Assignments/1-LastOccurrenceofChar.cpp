#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int lastOccurence(string&str, char&ch, int i) {
  //base case
  if(i < 0) return -1;

  //ek cacse
  if(str[i] == ch) {
    return i;
  }

  //re
  return lastOccurence(str, ch, i-1);
  
}

int main() {
  string str = "abcddajhbd";
  int size = str.size()-1;
  char ch = 'b';

  cout << lastOccurence(str, ch, size);
}