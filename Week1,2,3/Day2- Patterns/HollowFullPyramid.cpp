#include <iostream>
using namespace std;

int main() {

  // Hollow Full Pyramid
  int n;
  cout << "Enter Number: ";
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n-i-1; j++) {
     cout << "  ";
    }
    for(int j = 0; j < i*2+1; j++) {
      if(j == 0 || j == i*2 || i == n-1) {
       cout << "* ";
      }
      else {
       cout << "  ";
      }
    }
    cout << endl;
  }
  
}