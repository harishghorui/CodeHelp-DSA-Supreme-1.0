#include <iostream>
#include <vector>
using namespace std;

class Animal {

private: // <<--Access Modifier
int weight;

public: // <<--Access Modifier

  // State/Properties-->>
  int age;
  string type;

  // Behavior/Function-->>
  void eat() {
    cout << "Eating" << endl;
  }

private: // <<--Access Modifier
  void sleep() {
    cout << "Sleeping" << endl;
  }

public:
  int getWeight() {
    return weight;
  }
  void setWeight(int w) {
    weight = w;
  }

};

int main() {

  // Object Creation-->> 1.static 2.dynamic

  // 1. Static Memory-->>
  
  Animal ramesh; // <<--Object Creation
  ramesh.age = 12; // to access class property (.dot)operator is used-->>
  ramesh.type = "Lion";
  cout << "Age of Ramesh is " << ramesh.age << endl;
  cout << "Ramesh is " << ramesh.type << endl;
  ramesh.eat();
  // ramesh.sleep(); // cant access because of private access modifier

  //To access private property/function, getter&setter function is used-->>
  ramesh.setWeight(120);
  cout << "Weight is " << ramesh.getWeight() << endl;
  
}