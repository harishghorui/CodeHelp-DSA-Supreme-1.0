#include <iostream>
using namespace std;

int main() {

  // Numeric Full Pyramid- 2
  int n;
  cout << "Enter N: ";
  cin >> n;
  
  for(int row = 0; row < n; row++) {
    for(int col = 0; col < n-row-1; col++) {
      cout << "  ";
    }
    int count = 0;
    for(int col = 0; col < row+1; col++) {
      count = col+row+1;
      cout << count << " ";
    }
    count--;
    for(int col = 0; col < row; col++) {
      cout << count-- << " ";
    }
    cout << endl;
  }
  
}