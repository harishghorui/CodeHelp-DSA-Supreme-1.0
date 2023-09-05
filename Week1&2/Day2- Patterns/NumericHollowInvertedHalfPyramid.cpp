#include <iostream>
using namespace std;

int main() {

  // Numeric Hollow Inverted Half Pyramid
  int n;
  cout << "Enter N: ";
  cin >> n;

  for(int row = 0; row < n; row++) {
    for (int col = 0; col < n-row; col++) {
      if(col == 0 || row == 0 || col == n-row-1) {
        cout << col+row+1 << " ";
      }
      else {
        cout << "  ";
      }
    }
    cout << endl;
  }
  
}