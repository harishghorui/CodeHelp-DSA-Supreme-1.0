#include <iostream>
using namespace std;

int printNEvenSum(int n) {
  int sum = 0;
  for(int i = 2; i <= n; i += 2) {
    sum += i;
  }
  return sum;
}

int main() {
  
    int n;
    cout << "Enter N: ";
    cin >> n;
    cout << "Sum is " << printNEvenSum(n);
}