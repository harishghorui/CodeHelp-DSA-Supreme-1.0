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

void sortStack(stack <int> &s) {
    //base case
    if(s.empty()) {
        return;
    }

    //single case
    int target = s.top();
    s.pop();

    //Rec
    sortStack(s);

    insertSorted(s, target);
}

int main() {
    
    stack <int> s;
    s.push(10);
    s.push(5);
    s.push(8);
    s.push(15);
    s.push(7);

    sortStack(s);

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}