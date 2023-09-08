#include <iostream>
using namespace std;

int x = 4; // Global Variable

void fun(int x) {
    x = x + 3;
    cout << x << endl;
    cout << ::x << endl;
}

int main() {
    
    x = x + 2;
    cout << x << endl;
    int x = 20;

        {
            int x = 55; // most local variable
            cout << x << endl; // will give preference to most local variable
        }
    
    cout << x << endl; // here most local variable is x = 20
    cout << ::x << endl; // if same varible 'x' is present, to access global "::" scope operator

    cout << endl;
    fun(::x);
}