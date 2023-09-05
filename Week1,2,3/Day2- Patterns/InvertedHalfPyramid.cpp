#include <iostream>
using namespace std;

int main() {

  // inverted half pyramid
   int row, col;
   cout << "Enter Row: ";
   cin >> row;

  for(int i = 0; i < row; i++) {
    for(int j = 0; j < row-i; j++) {
      cout << "* ";
    }
    cout << endl;
  }
  
}