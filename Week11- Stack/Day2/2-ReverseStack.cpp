#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack <int>& st, int &target) {

    // base case
    if(st.empty()) {
        st.push(target);
        return;
    }

    //single case
    int temp = st.top();
    st.pop();

    // Rec
    insertAtBottom(st, target);

    //backtrack
    st.push(temp);
}

void reverseStack(stack<int> &st) {
    //base case
    if(st.empty()) {
        return;
    }

    //single case
    int target = st.top();
    st.pop();

    //rec
    reverseStack(st);

    insertAtBottom(st, target);
}

int main() {

    stack <int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    reverseStack(st);

    // Printing stack-->>
    cout << "After Reverse: " << endl;
    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}