#include <iostream>
using namespace std;

void checkPrimeNum(int n) {
  if(n == 1 || n == 0) {
    cout << n << " is neither Prime nor Composite";
    return;
  }
  for(int i = 2; i < n; i++) {
    if(n%i == 0) {
      cout << "Not a Prime Number";
      return;
    }
  }
  cout << "Prime Number";
}

int main() {
  
    int n;
    cout << "Enter N: ";
    cin >> n;
    checkPrimeNum(n);
}