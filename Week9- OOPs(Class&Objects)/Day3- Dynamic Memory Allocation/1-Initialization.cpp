#include <iostream>
using namespace std;

int main() {
    
    // Initialize-->>
    int* a = new int;
    delete a; // <<--Deallocate


    // Inintialize Array-->>
    int n = 5;
    int* b = new int[n];
    delete []b; // <<--Deallocate


    // Inintialize 2D Array-->>
    int row = 5;
    int col = 5;
    int ** arr = new int*[row];
    for(int i = 0; i < row; i++) {
        arr[i] = new int[col];
    }

    // Printing 2D Array-->>
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << arr[i][j] << " " ;
        }
        cout << endl;
    }

    // Deallocate 2DArray-->>
    for(int i = 0; i < row; i++) {
        delete []arr[i];
    }
    delete []arr;
}