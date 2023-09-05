#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void solve(vector<int>& arr, int& maxi, int sum, int i) {
  // base case
  if(i >= arr.size()) {
     maxi = max(sum, maxi);
    return;
  }
  
  //include
  solve(arr, maxi, sum + arr[i], i+2);
  //exclude
  solve(arr, maxi, sum, i+1);
}

int main() {
  vector<int> arr = {1,2,3,5,4};
  int maxi = INT_MIN;
  int sum = 0;
  int i = 0;
  
  solve(arr, maxi, sum, i);
  cout << "Max is: " << maxi ;
}
