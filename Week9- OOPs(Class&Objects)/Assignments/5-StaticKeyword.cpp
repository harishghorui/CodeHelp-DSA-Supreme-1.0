#include <iostream>
using namespace std;

class abc {
    public:
    static int x, y;

    //abc() : x(0) , y(0) {}

    static void print() {
        cout << x << " " << y << " " << endl;
    }
};

int abc::x;
int abc::y;

int main() {

    abc a;
    a.x = 20;
    abc::y = 10;
    abc::print(); //can also written like this bcoz its not function of any instance

    abc b;
    b.x = 25;
    b.y = 35;
    a.print(); // here we can see by updating b, a is also updated bcoz the class variable is updated
    abc::print();
}