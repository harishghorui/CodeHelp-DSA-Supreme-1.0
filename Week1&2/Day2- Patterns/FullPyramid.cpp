#include <iostream>
using namespace std;

int main() {

    // Full Pyramid
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
        if (j < n - i) {
            cout << " ";
        } else {
            cout << "* ";
        }
        }
        cout << endl;
    }

    /* Full Pyramid 2nd Method
    int n;
    cout << "Enter Row: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
        cout << " ";
        }
        for(int j = 0; j < i+1; j++) {
        cout << "* ";
        }
        cout << endl;
    } */
  
}