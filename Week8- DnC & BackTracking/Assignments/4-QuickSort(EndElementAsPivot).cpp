#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>&arr, int start, int end) {
  //base case
  if(start >= end) {
    return;
  }

  //ek case
  int pivot = end; // end element as pivot
  int i = start - 1;
  int j = start;

  while(j <= end) {
    if(arr[j] < arr[pivot]) {
      i++;
      swap(arr[i], arr[j]);
    }
    j++;
  }
  
  //here we will get i+1 as correct index for pivot
  i++; swap(arr[i], arr[pivot]);
  pivot = i; // update the pivot index

  //left part by RE
  quickSort(arr, start, pivot-1); //else i-1 can be used for end index

  //right part by RE
  quickSort(arr, pivot+1, end); //else i+1 can be used for end index
  
}

int main() {
  vector<int> arr = {7,2,1,8,6,3,5,4};
  int start = 0;
  int end = arr.size()-1;
  
  quickSort(arr, start, end);

  for(auto i : arr) {
    cout << i << " ";
  }
}