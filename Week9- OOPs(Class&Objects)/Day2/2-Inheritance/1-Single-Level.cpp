#include <iostream>
using namespace std;

// Inheritance (Single-Level) -->>
class Animal {
public:
  int age;
  float weight;

  void eat() { cout << "Eating " << endl; }
};

// Only(single) class Dog inherits class Animal
class Dog : private Animal {
public:
  void print() { cout << this->age; }
};

int main() {

  // Object-->>
  Dog rocky;
  // cout << rocky.age; // outside access
  rocky.print(); // inside access
}