#include <iostream>
#include <vector>
using namespace std;

int main() {

  vector<int> arr = {10,1,7,6,14,9};

  for(int round = 1; round < arr.size(); round++) {
    //fetch
    int val = arr[round], j = round-1;
    for(; j >= 0; j--) {
      //compare i from i-1
      if(arr[j] > val) {
        //shift i-1 to i
        arr[j+1] = arr[j];
      }
      else {
        break;
      }
    }
    //copy val to insert location
    arr[j+1] = val;
  }

  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  
  //Bubble Sort- Swap Largest Element to the extreme right
  /*
  vector<int> arr = {10,1,7,6,14,9};

  int n = arr.size();
  for(int round = 1; round < n; round++) {
    //every round will sort 1-largest element to the right
    bool swapped = false;
    for(int i = 0; i < n - round; i++) {
      //so it is confirmed largest element is sorted, so we run loop 1* less every iteration
      //moving largest element to fully right side by swapping
      if(arr[i] >= arr[i+1]) {
        swap(arr[i], arr[i+1]);
        swapped = true;
      }
    }
    if(swapped == false) {
      //Array sorted, no nedd to check further rounds
      break;
    }
  }
  
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  } */
  
  //Selection Sort- check is i smallest from i+1 to n & then swap
  /*
  vector<int> arr = {5,4,3,2,1};

  for(int i = 0; i < arr.size()-1; i++) {
    int minIndex = i, j = i+1;
    for(; j < arr.size(); j++) {
      if(arr[j] < arr[i]) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
  
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  } */
  return 0;
}