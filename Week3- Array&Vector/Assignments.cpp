#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> printSpiralMatrix(vector<vector<int> > matrix) {
  vector<int> ans;
  int m = matrix.size();
  int n = matrix[0].size();
  //int totalElements = matrix.size()*matrix[0].size();
  int totalElements = m*n;
  int count = 0;
  
  int startRow = 0;
  int endCol = n-1;
  int endRow = m-1;
  int startCol = 0;

  while(count < totalElements) {
    for(int i = startCol; i <= endCol && count < totalElements; i++) {
      ans.push_back(matrix[startRow][i]);
      count++;
    }
    startRow++;
    
    for(int i = startRow; i <= endRow && count < totalElements; i++) {
      ans.push_back(matrix[i][endCol]);
      count++;
    }
    endCol--;
    
    for(int i = endCol; i >= startCol && count < totalElements; i--) {
      ans.push_back(matrix[endRow][i]);
      count++;
    }
    endRow--;
    
    for(int i = endRow; i >= startRow && count < totalElements; i--) {
      ans.push_back(matrix[i][startCol]);
      count++;
    }
    startCol++;
  }
  return ans;
}

vector<int> printWaveMatrix(vector<vector<int> > matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  int total_elements = m*n;
  int top_row = 0; int col = 0;
  int bottom_row = m-1;

  vector<int> ans;
  int count = 0;
  while(count < total_elements) {
    for(int i = top_row; i <= bottom_row && count < total_elements; i++) {
      ans.push_back(matrix[i][col]);
      count++;
    }
    col++;
    for(int i = bottom_row; i >= top_row && count < total_elements; i--) {
      ans.push_back(matrix[i][col]);
      count++;
    }
    col++;
  }
  return ans;
}

int main() {

  //Print Wave Matrix
  /*
  int row, col, total_elements;
  cout << "Enter Row: ";
  cin >> row;
  cout << "Enter Col: ";
  cin >> col;
  total_elements = row*col;
  
  vector<vector<int> > matrix(row, vector<int>(col));
  cout << "Enter "<< total_elements << " Elements: " <<endl;
  for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[i].size(); j++) {
      cin >> matrix[i][j];
    }
  }
  vector<int> ans = printWaveMatrix(matrix);
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  } */
  
  //Print Spiral Matrix- LeetCode
  /*
  int row, col, totalElements;
  cout << "Enter Row: ";
  cin >> row;
  cout << "Enter Col: ";
  cin >> col;
  totalElements = row*col;
  
  vector<vector<int> > matrix(row, vector<int>(col));
  cout << "Enter "<< totalElements << " Elements: " <<endl;
  for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[i].size(); j++) {
      cin >> matrix[i][j];
    }
  }
  vector<int> ans = printSpiralMatrix(matrix);
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  } */

  // Find First Repeating Element- GFG
  /*
  int arr[] = {1,5,3,4,3,5,6};
  int n = 7;
  unordered_map<int, int>hash;
  for(int i = 0; i < n; i++) {
    hash[arr[i]]++;
  }

  for(int i = 0; i < n; i++) {
    if(hash[arr[i]] > 1) {
      return i+1;
    }
  }
  return -1; */

  //Find Duplicate Number- LeetCode
  /*
  //Method 1- with sort function
  // int nums[] = {2,1,3,4,2};
  // int arraySize = sizeof(nums) / sizeof(nums[0]);
  // sort(nums,nums+arraySize);

  // for(int i = 0; i < 4; i++) {
  //   if(nums[i] == nums[i+1]) {
  //     cout << "Found Duplicate: "<< nums[i];
  //     break;
  //   }
  // }

  //Method 2- mark visited
  int nums[] = {1,2,3,4,2};
  while(nums[0] != nums[nums[0]]) {
    swap(nums[0], nums[nums[0]]);
  }
  cout << "Found Duplicate: " << nums[0]; */
  
  //Move all -ve Num to Left
  /*
  //Method-1
  vector<int> num{-1,2,-3,4,-5,6,0,3,-10};
  int start = 0;
  int end = num.size()-1;

  while(start < end) {
    if(num[start] < 0) {
      start++;
    }
    else if(num[end] >= 0) {
      end--;
    }
    else {
      swap(num[start++], num[end--]);
    }
  }
  
  for(int value: num) {
    cout << value << " ";
  }
  
  //Method-2
  // vector<int> num{-1,2,-3,4,-5,6,0,3,-10};
  // int start = 0;
  // int end = num.size()-1;

  // while(start < end) {
  //   if(num[start] >= 0) {
  //     swap(num[start], num[end]);
  //     end--;
  //   }
  //   else if(num[start] < 0) {
  //     start++;
  //   }
  // }

  // for(int value: num) {
  //   cout << value << " ";
  // } */
  
  //Sort Colors- Leetcode
  /*
  vector<int> num{2,1,0,1,2,0};
  int low = 0;
  int medium = 0;
  int high = num.size()-1;

  while(medium <= high) {
    if(num[medium] == 0) {
      swap(num[low], num[medium]);
      low++;
      medium++;
    }
    else if(num[medium] == 1) {
      medium++;
    }
    else {
      swap(num[medium], num[high]);
      high--;
    }
  }
  
  for(int value: num) {
    cout << value << " ";
  } */
  
}