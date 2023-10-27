#include <iostream>
#include <stack>
using namespace std;

void findMid(stack<int>&st, int&totalSize) {
    //base case-->>
    if(totalSize/2 + 1 == st.size()) {
        cout << "Middle is: " << st.top();
        return;
    }
    if(st.empty()) {
        cout << "Empty Stack";
        return;
    }

    //single case
    int temp;
    temp = st.top();
    st.pop();

    //recc
    findMid(st, totalSize);

    //backtrck
    st.push(temp);
}

int main() {
    
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);

    int size = st.size();
    findMid(st, size);
}