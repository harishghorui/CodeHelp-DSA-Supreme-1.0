#include <iostream>
using namespace std;

int main() {
  int a = 5;

  cout << "a = " << a <<endl;
  cout << "Address of a: " << &a <<endl;

  //A pointer is a variable that stores the memory address of an object
  //creating pointer
  int* ptr_a = &a;
  cout << "Address of a by pointer: " << ptr_a <<endl;

  //to access the value ptr is pointing to
  cout << "Value prt is pointing to: " << *ptr_a << endl;
}