#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack <int> &s, int &target) {
    //base case
    if(s.empty()) {
        s.push(target);
        return;
    }
    if(s.top() < target) {
        s.push(target);
        return;
    }

    // single case
    int temp = s.top();
    s.pop();

    // Rec
    insertSorted(s, target);

    //backtrack
    s.push(temp);
}

int main() {
    
    stack <int> s;
    s.push(1);
    s.push(3);
    s.push(4);
    s.push(6);
    s.push(8);

    int target = 5;

    insertSorted(s, target);

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}