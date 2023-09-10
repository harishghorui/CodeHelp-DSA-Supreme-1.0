#include <iostream>
using namespace std;

class Base {
    public:

    Base() {
        cout << "Base Ctor" << endl;
    }

    // ~Base() {
    //     cout << "Base Dtor" << endl;
    // }
    // Without virtual Dtor, Derived/child Dtor is not called

    virtual ~Base() {
        cout << "Base Dtor" << endl;
    }
};

class Derived : public Base {
    public:
    int *a;

    Derived() {
        a = new int[1000]; //without Virtual this may lead to memory leak
        cout << "Derived Ctor" << endl;
    }

    ~Derived() {
        cout << "Derived Dtor" << endl;
    }
};

int main() {

    Base *a = new Derived();
    delete a;

    return 0;
}