#include <iostream>
using namespace std;

class Car {
  public:
    string name;
    int weight;

    void speed() {
      cout << "Speeding Up" << endl;
    }
};

class Scorpio : public Car {
    // inherits class Car
};

class Fortuner : public Car { 
    // inherits class Car
};


int main() {

  Scorpio f11;
  f11.speed();

  Fortuner i20;
  i20.speed();
}