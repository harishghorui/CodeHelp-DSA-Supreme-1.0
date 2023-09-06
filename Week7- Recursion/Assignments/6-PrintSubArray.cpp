#include <iostream>
#include <vector>
using namespace std;

void printSubArray(vector<int>&arr, int&n, int start, int end) {
  //base case
  if(end >= n) return;
  
  //ek case
  for(int i = start; i <= end; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  
  //re 
  printSubArray(arr, n, start, end+1);
}

int main() {
  vector<int> arr = {1,2,3,4,5};
  int n = arr.size();
  for(int i = 0; i < n; i++) {
    printSubArray(arr, n, i, i);
  }

  return 0;
}