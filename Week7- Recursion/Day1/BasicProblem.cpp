#include <iostream>
using namespace std;

int factorial(int n) {
  int ans = 1;
  
  //base condition
  if(n <= 1) {
    return n;
  }

  // recursive relation
  ans = n * factorial(n-1);
  
  return ans;
}

void printCounting(int n) {
  if(n == 0) return ; // base condition

  printCounting(n-1); // recursive relation

  cout << n << " "; // processing
}

void printReverseCounting(int n) {
  if(n == 0) return ; // base condition

  cout << n << " "; // processing

  printReverseCounting(n-1); // recursive relation
}

int fibSeries(int n) {
  if(n == 1) return 0; // base condition
  if(n == 2) return 1;
  
  return fibSeries(n-1) + fibSeries(n-2); //Processing + relation
}

int main() {
  int n;
  cout << "Enter N: ";
  cin >> n;

  //cout << "Factorial is: " << factorial(n);
  //printCounting(n);
  //printReverseCounting(n);
  cout << "Fib Nth term is: " << fibSeries(n);
}