#include <iostream>
using namespace std;

class Animal {
    public:

    // virtual keyword for Upcasting & Downcasting-->>
    virtual void speak() {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal {
    public:
    //overriding-->>
    void speak() {
        cout << "Barking" << endl;
    }
};

int main() {
    
    // Dynamicaly Object creating-->>
    // Animal* a = new Animal;
    // a->speak();

    // Dog* b = new Dog;
    // b->speak();

    //upcasting-->>
    Animal* a = new Dog;
    a->speak();

    //downcasting-->>
    Dog* b = (Dog*)new Animal;
    b->speak();

}