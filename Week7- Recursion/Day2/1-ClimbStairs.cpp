#include <iostream>
using namespace std;

int climbStairs(int n) {
  if(n == 0 || n == 1) return 1; // base case

  return climbStairs(n-1) + climbStairs(n-2);
}

int main() {
  int n;
  cout << "Enter N: ";
  cin >> n;

  cout << "Ways to climb " << n << " stairs are: " << climbStairs(n);
}
