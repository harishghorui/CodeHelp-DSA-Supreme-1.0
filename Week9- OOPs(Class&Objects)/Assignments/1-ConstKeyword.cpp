#include <iostream>
using namespace std;

class abc {
    int x;
    int *y;

    public:
    abc() {
        x = 0;
        y = new int(0);
    }

    int getX() const { // <<--const initialization for M.F
        // x = 50; // can't change
        return x;
    }
    void setX(int _val) {
        x = _val;
    }

    int getY() const {
        int a = 20;
        // y = &a; // can't change due to Const
        return *y;
    }
    void setY(int _val) {
        *y = _val;
    }

};

int main() {
    abc a;
    cout << a.getX() << endl;
    cout << a.getY() << endl;
}

int main2() {

    // 1. Initialization -->>
    // const int x = 10;
    // x = 15; // cannot change const variable

    // 2. const with pointers -->>
    // // const int *a = new int(2); // <<-- const data, non-const pointer
    // int const *a = new int(2); // <<-- same as line no.11
    // cout << *a << endl;
    // // *a = 10; // cant change the content of pointer
    // int b = 20;
    // a = &b; // pointer itself can be reassigned
    // cout << *a << endl;

    // 3. const pointer, non-const data -->>
    // int *const a = new int(2);
    // cout << *a << endl;
    // *a = 10; // non-const data can be updated
    // cout << *a << endl;
    // int b = 20;
    // // a = &b // cannot update due to const pointer

    // 4. Const data, const pointer -->>
    // const int *const a = new int(2);
    // *a = 10;
    // int b = 10;
    // a = &b; // both data & pointer cannot be changed

}