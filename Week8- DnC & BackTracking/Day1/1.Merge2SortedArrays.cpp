#include <iostream>
#include <vector>
using namespace std;

int main() {
  int arr1[] = {2,4,6};
  int arr2[] = {3,5,7,9,11};
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  cout << size1 << endl;
  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << size2 << endl;
  
  int i = 0;
  int j = 0;
  vector<int> ans;

  while(i <= 3 && j <= 5) {
    if(i >= 3 && j < 5) {
      ans.push_back(arr2[j]);
      j++;
    }
    else if(i < 3 && j >= 5) {
      ans.push_back(arr1[i]);
      i++;
    }
    else if(arr1[i] < arr2[j]) {
      ans.push_back(arr1[i]);
      i++;
    }
    else if(arr1[i] > arr2[j]) {
      ans.push_back(arr2[j]);
      j++;
    }
  }

  for(auto i : ans) {
    cout << i << " ";
  }
}

// int i = 0; // pointer of arr1
// int j = 0; // pointer of arr2
// vector<int> ans;
  
// while(i < size1 || j < size2) {
//   if(i != size1 && j != size2) {
//     if(arr1[i] < arr2[j]) {
//       ans.push_back(arr1[i]);
//       i++;
//     }
//     if(arr2[j] < arr1[i]) {
//       ans.push_back(arr2[j]);
//       j++;
//     }
//   }

//   if(i == size1) {
//     ans.push_back(arr2[j]);
//     j++;
//   }
//   if(j == size2) {
//     ans.push_back(arr1[i]);
//     i++;
//   }
// }
