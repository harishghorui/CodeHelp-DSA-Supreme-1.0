#include <iostream>
using namespace std;

class Animal {
    public:

    void speak() {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal {
    public:
    // without overriding
};

class Cat : public Animal {
    public:
    // overriding function-->>
    void speak() {
        cout << "Meow" << endl;
    }
};

int main() {
    
    Animal obj1;
    obj1.speak();

    Dog obj2;
    obj2.speak(); // only inherits

    Cat obj3;
    obj3.speak(); // Runtime Polymorphism (overriding function)
}