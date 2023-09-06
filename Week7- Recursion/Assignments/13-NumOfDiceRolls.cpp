#include <iostream>
using namespace std;

int numRollsToTarget(int n, int k, int target) {
    //base case
    if(n == 0 && target != 0) return 0;
    if(n != 0 && target == 0) return 0;
    if(n == 0 && target == 0) return 1;

    //ek case
    int ans = 0;
    int i = 1;
    while(i <= k) {
        ans = ans + numRollsToTarget(n-1, k, target-i);
    }
    return ans;
}

int main() {
  int n = 2;
  int k = 6;
  int target = 7;

  cout << numRollsToTarget(n, k, target);
}