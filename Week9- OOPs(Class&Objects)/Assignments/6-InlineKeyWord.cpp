#include <iostream>
using namespace std;

inline void fun(int num) {
    // inline keyword will replace funtion calling statement 
    // from this body/cout statement
    // resulting in less stack overhead
    cout << num << endl;
    cout << num*2 << endl;
}

int main() {
    int num = 5;
    fun(num);
    fun(num);
}