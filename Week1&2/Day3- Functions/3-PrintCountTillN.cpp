#include <iostream>
using namespace std;

void countTillN(int n) {
  for(int num = 1; num <= n; num++) {
    cout << num << " ";
  }
}

int main() {

    int n;
    cout << "Enter N: ";
    cin >> n;
    countTillN(n);
    
}