#include <iostream>
using namespace std;

int printNSum(int n) {
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int main() {
    
    int n;
    cout << "Enter N: ";
    cin >> n;
    cout << "Sum is " << printNSum(n);
  
}