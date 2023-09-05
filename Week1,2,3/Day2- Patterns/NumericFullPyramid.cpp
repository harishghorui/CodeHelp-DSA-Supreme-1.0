#include <iostream>
using namespace std;

int main() {

  // Numeric Full Pyramid- incomplete
  int n;
  cout << "Enter N: ";
  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n-i-1; j++) {
      cout << "  ";
    }
    int j = 0, count = j+i+1;
    while(j < i+1) {
      cout << count << " ";
      j++;
    }

    for(int k = 0; k < i; k++) {
      cout << --count << " ";
    }
    cout << endl;
  }
  
}