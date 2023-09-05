#include <iostream>
using namespace std;

int main() {

  // Full Numeric Pyramid
  int n;
  cout << "Enter N: ";
  cin >> n;

  for(int row = 0; row < n; row++) {
    for(int col = 0; col < n-row-1; col++) {
      cout << "  ";
    }
    int col = 0;
    for(; col < row+1; col++) {
      cout << col+1 << " ";
    }
    col--;
    for(; col >= 1; col--) {
      cout << col << " ";
    }
    cout << endl;
  }
  
}