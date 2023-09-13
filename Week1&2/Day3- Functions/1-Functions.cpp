#include <iostream>
using namespace std;

int main() {

  // bool a = true;
  // bool b = false;
  // cout << (a^b);

  // int a = -6;
  // a = a >> 1;
  // cout << a;

  int age;
  cout << "Enter Age: ";
  cin >> age;
  (age >= 18) ? cout << "Can Vote" : cout << "Cannot Vote";

  return 0;
}