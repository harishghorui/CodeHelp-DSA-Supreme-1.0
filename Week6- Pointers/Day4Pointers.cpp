#include <iostream>
using namespace std;
// Double pointer  

void funct(int* p) {
  // how to pass single pointer
  
  // p = p + 1; // will not change the original value
  *p = *p + 1; // will change the value

}

void solve(int** ptr) {
  // how to pass double pointer
  // ptr = ptr + 1; // will not change the actual value
  // *ptr = *ptr + 1; // will not change the actual value
  **ptr = **ptr + 10; // here will change the actual value
}

void solve1(int& a, int*& p) {
  a++;
  p++;
}

int* solve2() {
  int a = 5;
  int* ans = &a;
  return ans;
}

int x;
int& solve3() {
  return x; // returned variable(x) must be global variable
}
int main() {
  // int a = 5;
  // int* p = &a;
  // int** q = &p;
  // cout << a << endl; // 5
  // cout << &a << endl; // 104
  // cout << p << endl; // 104
  // cout << &p << endl; // 216
  // cout << *p << endl; // 5
  // cout << q << endl; // 216
  // cout << &q << endl; // 328
  // cout << *q << endl; // 104
  // cout << **q << endl; // 5

  // int a = 5;
  // int* p = &a;
  
  // cout << "Before" << endl;
  // cout << a << endl;
  // cout << p << endl;
  // cout << *p << endl << endl;
  // funct(p);
  // cout << "After" << endl;
  // cout << a << endl;
  // cout << p << endl;
  // cout << *p << endl;

  // int a = 5;
  // int* p = &a;
  // int** q = &p;
  // solve(q);
  // cout << a << endl;

  // REFERENCE VARIABLE- same memory, different names
  // int a = 5;
  // int& b = a;
  // cout << b << endl;
  // a++;
  // cout << b << endl;
  // b++;
  // cout << b << endl;

  // passing by reference
  // int a = 5;
  // int* ptr = &a;
  // cout << "Before: " << endl;
  // cout << a << endl;
  // cout << ptr << endl << endl;
  // solve1(a, ptr);
  // cout << "After: " << endl;
  // cout << a << endl;
  // cout << ptr ;

  // Return by Reference
  // solve3() = 10;
  // cout << x;

  // VERY IMPORTANT Question
  cout << solve2();
  
}