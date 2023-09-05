#include <iostream>
using namespace std;

int main() {
  
  // Hollow Square
  int row, col;
  cout << "Enter Row: ";
  cin >> row;
  cout << "Enter Col: ";
  cin >> col;

  for (int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(i == 0 || i == row-1 || j == 0 || j == col-1) {
        cout << "* ";
      }
      else {
        cout << "  ";
      }
    }
    cout << endl;
  }
}