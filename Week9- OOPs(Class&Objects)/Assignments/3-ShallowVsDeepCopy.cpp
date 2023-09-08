#include <iostream>
using namespace std;

class abc {
    public:
    int x;
    int *y;

    //Initialization List -->>
    abc(int _x, int _y) : x(_x), y(new int(_y)) {}

    // A Default dump Copy constructor -->>
    abc(const abc &obj) {
        x = obj.x;
        y = obj.y;
    }

    void print() const {
        printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);
    }

};

//Deep Copy -->> custom constructor
// class abc2 {
//     public:
//     int x;
//     int *y;

//     //Initialization List -->>
//     abc2(int _x, int _y) : x(_x), y(new int(_y)) {}

//     // Our Smart Copy constructor -->>
//     abc2(const abc2 &obj) {
//         x = obj.x;
//         y = new int (*obj.y);
//     }

//     void print() const {
//         printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);
//     }
// };

int main() {

    // 1.Shallow Coping Example -->>
    abc a(1, 2);
    cout << "Printing a\n";
    a.print();

    // New Object to duplicate the content of object 'a' -->>
    abc b(a); // a default copy constructor is called
    cout << "Printing b\n";
    b.print(); //by shallow copying it has same ptr as object 'a'

    *b.y = 10;
    cout << "Printing b\n";
    b.print();

    cout << "Printing a\n";
    a.print(); // as the pointer is also same, value of y is changed
    

    // 2.One more prb in Shallow Copy-->>
    /*
    abc *c = new abc(1, 2);
    abc d = *c;
    delete c;
    d.print(); //after deleting 'c' as the d.y was also pointing to the same
    // and while system deleting d, there will be malloc: double free problem
    // becoz system will again try to delete the same pointer
    */

   
    // 3.Deep Coping Example -->>
    /*
    abc2 a(10, 20);
    cout << "Printing a\n";
    a.print();

    // New Object to duplicate the content of object 'a' -->>
    abc2 b(a); // a default copy constructor is called
    cout << "Printing b\n";
    b.print(); //by shallow copying it has same ptr as object 'a'

    *b.y = 15;
    cout << "Printing b\n";
    b.print();

    cout << "Printing a\n";
    a.print(); // as the pointer is also same, value of y is changed
    */

    return 0;
}