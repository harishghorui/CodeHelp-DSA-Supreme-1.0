#include <iostream>
#include <stack>
using namespace std;

int main() {

    // creation-->>
    stack<int> st;

    // insertion-->>
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // removing-->>
    st.pop();

    // peek top-->>
    cout << "Top Element is: " << st.top() << endl;

    // size-->>
    cout << "Size of Stack is: " << st.size() << endl;

    // check empty-->>
    if(st.empty()) {
        cout << "Stack is Empty" << endl;
    }
    else {
        cout << "Stack is not Empty" << endl;
    }

    // accessing stack-->>
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    
    if(st.empty()) {
        cout << "Stack is Empty" << endl;
    }
    else {
        cout << "Stack is not Empty" << endl;
    }
    
}