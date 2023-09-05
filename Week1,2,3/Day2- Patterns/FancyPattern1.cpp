#include <iostream>
using namespace std;

int main() {

  // Fancy Pattern 1
   int n;
   cout << "Enter N: ";
   cin >> n;

  for(int row = 0; row < n; row++) {
    for(int col = 0; col < row+1; col++) {
      if(col != row) {
        cout << row+1 << "*";
      }
      else {
        cout << row+1;
      }
    }
    cout << endl;
  }

  for(int row = 0; row < n; row++) {
    for(int col = 0; col < n-row; col++) {
      if(col != n-row-1) {
        cout << n-row << "*";
      }
      else {
        cout << n-row;
      }
    }
    cout << endl;
  }
  
}