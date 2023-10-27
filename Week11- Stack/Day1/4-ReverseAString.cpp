#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack <char> s;

    string str = "harish";
    for(int i = 0; i < str.size(); i++) {
        s.push(str[i]);
    }

    cout << "Reversed String: ";
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}