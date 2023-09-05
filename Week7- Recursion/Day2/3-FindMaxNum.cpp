#include <iostream>
#include <limits.h>
using namespace std;

void findMaxNum(int arr[], int size, int i, int& max) {

  //code running only by doing pass by reference
  if(i >= size) return;

  if(arr[i] > max) {
    max = arr[i];
  }

  findMaxNum(arr, size, i+1, max);
}

int main() {
  int arr[6] = {80, 50, 60, 10, 90, 200};
  int size = 6;
  int i = 0;

  int max = INT_MIN;
  findMaxNum(arr, size, i, max);
  cout << "Max Num is: " << max;
}