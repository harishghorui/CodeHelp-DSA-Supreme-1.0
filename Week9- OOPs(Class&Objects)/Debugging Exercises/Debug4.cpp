#include <iostream>
using namespace std;

class Shape {
public:
    void draw() {
        cout << "Drawing a shape" << endl;
    }
};

class Circle: public Shape {
public:
    void draw(int radius) {
        cout << "Drawing a circle with radius " << radius << endl;
    }
};

int main() {
    Circle c;
    c.draw();
    return 0;
}


// // Debugged --->>>
// #include <iostream>
// using namespace std;

// class Shape {
// public:
//     void draw() {
//         cout << "Drawing a shape" << endl;
//     }
// };

// class Circle: public Shape {
// public:
//     void draw(int radius) {
//         cout << "Drawing a circle with radius " << radius << endl;
//     }
// };

// int main() {
//     Circle c;
//     c.draw(56);
//     return 0;
// }