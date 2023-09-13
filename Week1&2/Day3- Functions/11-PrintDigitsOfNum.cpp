#include <iostream>
using namespace std;

void printDigitsOfNumber(int num) {
  /* recursion funtion
  if(num <= 0) {
    return;
  }
  
  int remNum = num/10;
  printDigitsOfNumber(remNum);
  int digit = num % 10;
  
  cout << digit << endl;
  */
  
  for(; num > 0; num /= 10) {
    int digit = num % 10;
    cout << digit << " ";
  }
}


int main() {
  
    int num;
    cout << "Enter Number: ";
    cin >> num;
    printDigitsOfNumber(num);
  
}