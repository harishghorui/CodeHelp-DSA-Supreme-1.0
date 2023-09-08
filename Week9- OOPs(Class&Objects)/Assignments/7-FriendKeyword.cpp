#include <iostream>
using namespace std;

// to access a private data member use friend keyword-->>

class A {
    private:
    int x;

    public:
    A(int _val) : x(_val) {}

    int getX() const { return x; }
    void setX(int _val) { x = _val; }

    friend class B; // friend keyword
};

class B {
    public:
    void print(const A &a) {
        cout << a.getX() << endl;
        cout << a.x << endl; // without friend keyword can't access private D.M
    }
};

int main() {

    A a(5);
    B b;
    b.print(a);
    
}