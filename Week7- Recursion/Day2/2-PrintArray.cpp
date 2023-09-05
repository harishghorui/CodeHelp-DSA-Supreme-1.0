#include <iostream>
using namespace std;

void printArray(int arr[], int size, int i) {
  if(i >= size) return;

  cout << arr[i] << " ";

  printArray(arr, size, ++i);
}

int main() {
  int arr[6] = {10,20,30,40,50, 60};
  int size = 6;
  int i = 0;
  
  printArray(arr, size, i);
}
