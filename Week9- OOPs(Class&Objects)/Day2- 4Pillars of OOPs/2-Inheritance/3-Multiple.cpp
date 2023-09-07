#include <iostream>
using namespace std;

class A {
  public:
    int maths;
    int chemistry;

  A() {
    chemistry = 101;
  }
};

class B {
  public:
    int chemistry; // class A also has same member(Diamond prb)

  B() {
    chemistry = 404;
  }
};


// class C inherits both class A & B
class C : public A, public B {
  public:
    int physics;
};


int main() {

  C obj;
  // incase of same data member we use scope operator (::)
  cout << obj.physics << " " << obj.A::chemistry << " " << obj.maths << " " << endl;
}