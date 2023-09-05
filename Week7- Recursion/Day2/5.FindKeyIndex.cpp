#include <iostream>
using namespace std;

void findKeyIndex(string& name, int& n, int i, char& key, int& keyIndex) {
  if(name[i] == '\0') return;

  if(name[i] == key) {
    keyIndex = i;
    return;
  }

  findKeyIndex(name, n, i+1, key, keyIndex);
}

int main() {
  string name = "harishghorui";
  int n = name.length();
  int i = 0;
  char key = 'i';

  int keyIndex = -1;
  findKeyIndex(name, n, i , key, keyIndex);

  if(keyIndex != -1) {
    cout << "Key found at Index: " << keyIndex;
  }
  else {
    cout << "Key Not Found";
  }

  return 0;
}