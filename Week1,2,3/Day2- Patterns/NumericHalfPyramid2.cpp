#include <iostream>
using namespace std;

int main() {

  // Numeric Half Pyramid- 2
  int n;
  cout << "Enter N: ";
  cin >> n;

  int count = 1;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < row+1; col++) {
      cout << count++ << " ";
    }
    cout << endl;
  }
  
}