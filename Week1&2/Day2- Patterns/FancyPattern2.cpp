#include <iostream>
using namespace std;

int main() {

  // Fancy Pattern 2- Method 1
  int n;
  cout << "Enter N: ";
  cin >> n;

  for (int row = 0; row < n; row++) {
    int col = 0;
    for (; col < row + 1; col++) {
      int ans = col + 1;
      char ch = ans + 'A' - 1;
      cout << ch << " ";
    }

    for (int col = row; col >= 1; col--) {
      int ans = col;
      char ch = ans + 'A' - 1;
      cout << ch << " ";
    }
    cout << endl;
  }
  
  /* Fancy Pattern 2- Method 2

  for(int row = 0; row < n; row++) {
    for(int col = 0; col < row+1; col++) {
      //int ans = col+1;
      char ch = col+1 + 'A' - 1;
      cout << ch << " ";
    }
    int count = row;
    for(int col = 0; col < row; col++) {
      //int ans = row-col;
      char ch = row-col + 'A' - 1;
      cout << ch << " ";
    }
    cout << endl;
  } */
}