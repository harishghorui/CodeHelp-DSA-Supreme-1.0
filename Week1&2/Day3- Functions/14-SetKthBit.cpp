#include <iostream>
using namespace std;

int setKthBit(int n, int k) {
  int mask = 1 << k;
  return n | mask;
}

int main() {
  
    int n, k;
    cout << "Enter Number: ";
    cin >> n;
    cout << "Enter Kth Bit: ";
    cin >> k;
    cout << setKthBit(n, k);
}