#include <iostream>
using namespace std;

int main() {

  // Inverted Full Pyramid
  int n;
  cout << "Enter Row: ";
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
     cout << " ";
    }
    for(int j = 0; j < n-i; j++) {
     cout << "* ";
    }
    cout << endl;
  }
  
}