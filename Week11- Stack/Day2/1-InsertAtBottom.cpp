#include <iostream>
#include <stack>
using namespace std;

void solve(stack <int>& st, int& target) {

    // base case
    if(st.empty()) {
        st.push(target);
        return;
    }

    //single case
    int temp = st.top();
    st.pop();

    // Rec
    solve(st, target);

    //backtrack
    st.push(temp);
}

void insertAtBottom(stack <int>& st) {

    if(st.empty()) {
        cout << "Stack Underflow" << endl;
        return;
    }

    int target = st.top();
    st.pop();

    solve(st, target);
}

int main() {

    stack <int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    insertAtBottom(st);

    // Printing stack-->>

    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}