#include <iostream>
using namespace std;

class Encapsulation {
  private:
    int age;
    float weight;

  public:
    void eat() {
      cout << "Eating " << endl;
    }

    int getAge() {
      return this->age;
    }

    void setAge(int age) {
      this->age = age;
    }
};

int main() {

  //Object cration-->>
  Encapsulation example;
  example.eat();
  example.setAge(12);
  cout << "Age: " << example.getAge() << endl;
}