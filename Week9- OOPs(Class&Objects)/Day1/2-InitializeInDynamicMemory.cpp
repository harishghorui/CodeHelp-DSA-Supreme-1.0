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

  // 2. Dynamic Memory-->>
  
  Animal* suresh = new Animal; // <<--Object creation

  (*suresh).age = 12; // Syntax to access pointer
  cout << "Age of Suresh is " << (*suresh).age << endl;
  (*suresh).eat();
  //To access private property/function, getter&setter function is used-->>
  (*suresh).setWeight(50);

  // Alternate Syntax-->>
  suresh->type = "Cat";
  cout << "Suresh is a " << suresh->type << endl;
  cout << "Suresh Weight is " << suresh->getWeight() << endl;
}