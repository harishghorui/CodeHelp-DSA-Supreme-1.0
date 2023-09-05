#include <iostream>
using namespace std;

int main() {

  // Flipped Solid Pattern
   int n;
   cout << "Enter N: ";
   cin >> n;

  for(int row = 0; row < n; row++) {
    for(int col = 0; col < n-row; col++) {
      cout << "* ";
    }
    for(int col = 0; col < row*2; col++) {
      cout << "  ";
    }
    for(int col = 0; col < n-row; col++) {
      cout << "* ";
    }
    cout << endl;
  }

  for(int row = 0; row < n; row++) {
    for(int col = 0; col < row+1; col++) {
      cout << "* ";
    }
    for(int col = 0; col < n*2-row*2-2; col++) {
      cout << "  ";
    }
    for(int col = 0; col < row+1; col++) {
      cout << "* ";
    }
    cout << endl;
  }
  
}