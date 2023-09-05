#include <iostream>
using namespace std;

bool findKey(string name, int n, int i, char key) {
  // if(i >= n) return false;
  if(name[i] == '\n') return false; //base case- null char
  
  if(name[i] == key) return true;

  return findKey(name, n, i+1, key);
}

int main() {
  string name = "harishghorui";
  int length = name.length();
  int i = 0;
  char key = 'z';

  bool find = findKey(name, length, i, key);

  if(find) {
    cout << "Found Key";
  }
  else {
    cout << "Key Not Found";
  }

  return 0;
}