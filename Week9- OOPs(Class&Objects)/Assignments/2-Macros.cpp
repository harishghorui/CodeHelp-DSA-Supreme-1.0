#include <iostream>
using namespace std;

#define PI 3.14 
//before executing the code, the pre-processor will replace PI to value
#define MAXX(x, y) (x > y ? x : y)
// increases reusability, readability

float circleArea(float r) {
    return PI * r * r;
}

float circlePerimeter(float r) {
    return 2 * PI * r;
}

void fun() {
    int a = 10;
    int b = 15;
    cout << MAXX(a, b) << endl;
}

void fun2() {
    int c = 100;
    int d = 15;
    cout << MAXX(c, d) << endl;
}

void fun3() {
    int x = 100;
    int y = 155;
    int z = MAXX(x, y);
    cout << z << endl;
}

int main() {
    float r = 65.4;
    cout << circleArea(r) << endl;
    cout << circlePerimeter(r) << endl;
    fun();
    fun2();
    fun3();
}