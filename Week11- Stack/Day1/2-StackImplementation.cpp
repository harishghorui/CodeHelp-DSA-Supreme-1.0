#include <iostream>
using namespace std;

class Stack {
    private:
    int *arr;
    int top;
    int size;

    public:
    Stack(int size) {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    // Functions-->>

    void push(int data) {
        // space available-->>
        if(size-top > 1) {
            top++;
            arr[top] = data;
        }

        // space not available-->>
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop() {
        if(top == -1) {
            // Stack is Empty-->>
            cout << "Stack UnderFlow" << endl;
        }
        else {
            top--;
        }
    }

    int getTop() {
        if(top == -1) {
            cout << "Stack Empty";
        }
        else {
            return arr[top];
        }
    }

    int getSize() {
        return top+1;
    }
    
    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    
    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Size of Stack is: " << s.getSize() << endl;

    while(!s.isEmpty()) {
        cout << s.getTop() <<" ";
        s.pop();
    }
    cout << endl;

    if(s.isEmpty()) {
        cout << "Stack is Empty" << endl;
    }
    else {
        cout << "Size of Stack is: " << s.getSize() << endl;
    }

}