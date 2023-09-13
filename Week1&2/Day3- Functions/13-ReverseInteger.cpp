#include <iostream>
using namespace std;

int reverseInteger(int x) {
  //Leetcode Prob- Reverse Integer
  int ans = 0;
  while(x > 0) {
    int digit = x % 10;
    ans = ans * 10 + digit;
    x = x / 10;
  }
  return ans;
}


int main() {
  
    int n;
    cout << "Enter Number: ";
    cin >> n;
    cout << reverseInteger(n);
}