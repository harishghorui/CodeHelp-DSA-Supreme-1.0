#include <iostream>
#include <cmath>
using namespace std;

void binaryNumMethod1(int n) {
  int i = 0, binaryNum = 0;
  for(; n > 0; n /= 2) {
    int bits = n % 2;
    binaryNum = bits * pow(10, i++) + binaryNum;
  }
  cout << binaryNum;
}

void binaryNumMethod2(int n) {
  int i = 0, binaryNum = 0;
  for(; n > 0;) {
    int bits = (n & 1);
    binaryNum = bits * pow(10, i++) + binaryNum;
    n = n >> 1;
  }
  cout << binaryNum;
}

int binaryToDecimal(int n) {
  int decimal = 0, i = 0;
  while(n) {
    int bit = n % 10;
    decimal = decimal + bit * pow(2, i++);
    n /= 10;
  }
  return decimal;
}

int main() {
  int n;
  cout << "Enter N: ";
  cin >> n;
  //binaryNumMethod1(n);
  //binaryNumMethod2(n);
  cout << binaryToDecimal(n);
}