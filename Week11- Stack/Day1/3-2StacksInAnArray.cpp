#include <iostream>
using namespace std;

class stack {
    public:
    int size;
    int *arr;
    int top1;
    int top2;

    stack(int size) {
        this->size = size;
        arr = new int[size];
        this->top1 = -1;
        this->top2 = size;
    }

    // Funtions-->>

    void push1(int data) {
        // check stack overflow
        if(top2 - top1 == 1) {
            cout << "Stack1 Overflow";
        }
        else {
            top1++;
            arr[top1] = data;
        }
    }

    void pop1() {
        // check if stack underflow
        if(top1 == -1) {
            cout << "Stack1 Underflow";
        }
        else {
            top1--;
        }
    }

    void push2(int data) {
        if(top2 - top1 == 1) {
            cout << "Stack2 Overflow";
        }
        else {
            top2--;
            arr[top2] = data;
        }
    }

    void pop() {
        // check if stack underflow
        if(top2 == size) {
            cout << "Stack2 is Underflow";
        }
        else {
            top2++;
        }
    }

    // Just for visual ref. DO NOT IMPLEMENT ANYWERE!!!
    void printStack() {
        int i = 0;
        while(i <= size) {
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }

};

int main() {
    
    stack st(10);

    // Adding in Stack 1-->>
    st.push1(10);
    st.push1(20);
    st.push1(30);
    st.push1(40);

    // Adding in Stack 2-->>
    st.push2(60);
    st.push2(70);
    st.push2(80);
    st.push2(90);
    
    st.printStack();
}