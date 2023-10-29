#include <iostream>
#include <stack>
using namespace std;

bool validParenthesis(string &s, stack <char> &st) {
    // base case


    // single case
    for(int i = 0; i < s.size(); i++) {
        char currBrkt = s[i];

        if(currBrkt == '(' || currBrkt == '[' || currBrkt == '{') {
            // Opening bracket
            st.push(currBrkt);
        }
        else {
            // Closing brcket
            if(!st.empty()) {
                if(currBrkt == ')' && st.top() == '(') {
                    st.pop();
                }
                else if(currBrkt == '}' && st.top() == '{') {
                    st.pop();
                }
                else if(currBrkt == ']' && st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    if(st.empty()) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    
    string str = "(])" ;

    stack <char> s;
    cout << validParenthesis(str, s);
}