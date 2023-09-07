#include <iostream>
using namespace std;

class Solve {
    public:
    // member variable-->>
    int val;

    // member function to overload the + operator
    void operator+(Solve& object2) {
        int value1 = this->val; // Get the value of the current object
        int value2 = object2.val; // Get the value of the second object
        cout << value1-value2 << endl; // Perform subtraction and print the result
    }
};

int main() {
    
    Solve object1, object2;
    object1.val = 7;
    object2.val = 2;

    // Calls the overloaded + operator, which performs subtraction-->>
    object1 + object2;
}