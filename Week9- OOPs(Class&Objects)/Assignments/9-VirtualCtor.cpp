#include <iostream>
using namespace std;

class Animal {
    public:
    int x;

    // virtual Animal(int x) {
    //     this->x = x;
    // }
    
    //virtual can't be made bcoz there is no vtable exits before compliling
};

class Tiger : public Animal {
    public:
};

int main() {

    // Animal *a = new Animal(5);

}