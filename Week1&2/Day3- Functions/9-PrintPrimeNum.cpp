#include <iostream>
using namespace std;

int printPrimeNumbers(int n) {
  for(int i = 2; i < n; i++) {
    if(n%i == 0) {
      return 0;
    }
  }
  return n;
}

int main() {
  
    int n;
    cout << "Enter N: ";
    cin >> n;
    if(n > 1) {
        for(int i = 2; i <= n; i++) {
        int ans = printPrimeNumbers(i);
        if(ans > 0) {
            cout << ans << " ";
        }
        }
    } else {
        cout << n << " is neither a Prime nor Composite";
    }

}