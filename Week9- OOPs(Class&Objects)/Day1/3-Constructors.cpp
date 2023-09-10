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

  // Constructors-->>

  // Default Constructor-->> visual reference of default constructor
  Animal() {
    this->weight = 0;
    this->age = 0;
    this->type = "";
    cout << "Constructor1 is Called" << endl;
  }

  // Parameterized Constructor-->>
  Animal(int weight) {
    this->weight = weight;
    cout <<"Constructor2 is Called, Weight is: " << weight << endl;
  }

  Animal(int age, string type) {
    this->age = age;
    this->type = type;
    cout << "Constructor3 is Called, age & type: " << age << " & " << type << endl;
  }

  // Copy Constructor-->>
  Animal(Animal&obj) {
    cout << "Copy Constructor Called" << endl;
  }


// Destructor-->>

  ~Animal() {
    cout << "Destructor Called" << endl;
  }
};

int main() {

  // Object Creation-->>

  // Contructors-->>
  // When creating object, constructor is called for initialization
  
  Animal suresh; // Constructor1
  
  Animal ramesh(102); // Constructor2
  
  Animal* mahesh = new Animal(15, "tiger"); // Constructor3

  Animal a;
  Animal b = a; // Constructor4-->> copy constructor gets called
  Animal c(b); // alternate way to call copy constructor

  // Destructor-->> 
    // static calls destructor automatically-->>
    // call destructor manually for dynamic-->>

  Animal d; //
}