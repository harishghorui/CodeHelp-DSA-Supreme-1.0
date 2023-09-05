#include <iostream>
using namespace std;

class Fruits {
  public:
    string name;
};

// Mango inherits Fruits
class Mango : public Fruits {
  public:
    int quantity;
};

// Alphanso inherits Mango
class Alphanso : public Mango {
  public:
    int sugarLevel;
};

int main() {

  Alphanso a;
  cout << a.name << "- " << a.quantity << " " << a.sugarLevel << " " << endl;
}