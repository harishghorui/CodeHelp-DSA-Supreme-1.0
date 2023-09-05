#include <iostream>
using namespace std;

int main() {

  // Hollow Half Pyramid
  int n;
  cout << "Enter N: ";
  cin >> n;

  for(int row = 0; row < n; row++) {
    for(int col = 0; col < n-row-1; col++) {
      cout << "  ";
    }
    int start = 1;
    for(int col = 0; col < row*2+1; col++) {
      if(row == 0 || row == n-1) {
        if(col % 2 == 0) {
          cout << start++ << " ";
        }
        else {
          cout << "  ";
        }
      }
      else {
        if(col == 0) {
          cout << "1 ";
        }
        else if(col == row*2) {
          cout << row+1;
        }
        else {
          cout << "  ";
        }
      }
    }
    cout << endl;
  }
  
}