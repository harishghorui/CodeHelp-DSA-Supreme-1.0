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

  void sleep() {
    cout << "Sleeping" << endl;
  }

  int getWeight() {
    return weight;
  }
  void setWeight(int w) {
    weight = w;
  }

// Constructors-->>

  // Default Constructor-->> visual reference of default constructor
  Animal() {
    this->weight = 0;
    this->age = 0;
    this->type = "";
    cout << "Constructor1 is Called" << endl;
  }

// Destructor-->>

  ~Animal() {
    cout << "Destructor Called" << endl;
  }
};

int main() {

  // Object Creation-->>

  // Destructor-->> 
    // static calls destructor automatically-->>
    // call destructor manually for dynamic-->>

  Animal a; // static destructor called

  Animal* b = new Animal();

  delete b; // manually call for destructor
}