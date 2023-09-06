#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;

int perfectSquares(int n) {
  //base case
  if(n == 0) return 1;
  if(n < 0) return 0;

  //ek case
  int ans = INT_MAX;
  int i = 1;
  int end = sqrt(n);
  
  while(i <= end) {
    int perfectSqr = i * i;
    int numOfPerfectSquare = 1 + perfectSquares(n - perfectSqr);
    
    if(numOfPerfectSquare < ans) {
      ans = numOfPerfectSquare;
    }
    ++i;
  }
  return ans;
}

int main() {
  int n = 12;
  cout << perfectSquares(n) - 1;
}
