#include <iostream>
using namespace std;

class Maths {
    public:

    int sum(int a, int b) {
        cout << "Calling Sum1" << endl;
        return a+b;
    }

    int sum(int a, int b, int c) {
        cout << "Calling Sum2" << endl;
        return a+b+c;
    }

    int sum(int a, float b) {
        cout << "Calling Sum3" << endl;
        return a+b;
    }

};

int main() {

    Maths object;
    cout << object.sum(5,3.2f) << endl;
}