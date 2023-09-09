#include <iostream>
using namespace std;

class Box {
    int width;
    Box(int val) : width(val) {
        width *= 2;
    };
    // Yes-> contructor can be made private
    
    public:
    int getX() {
        return width;
    }

    void setX(int val) {
        this->width = val;
    }

    friend class Boxfactory;
};

class Boxfactory {
    // to access private D.M/M.F
    public:
    Box getABox(int _w) {
        return Box(_w);
    }
};

int main() {
    
    Boxfactory bfact;
    Box b = bfact.getABox(6);
    cout << b.getX() << endl;
}