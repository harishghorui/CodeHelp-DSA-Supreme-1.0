#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void printRowSum(int arr[][3], int row, int col) {
  for(int i = 0; i < row; i++) {
    int sum = 0;
    for(int j = 0; j < col; j++) {
      sum += arr[i][j];
    }
    cout << "Sum of row no." << i+1 << " is: " << sum <<endl;
  }
}

void printColSum(int arr[][3], int row, int col) {
  for(int i = 0; i < row; i++) {
    int sum = 0;
    for(int j = 0; j < col; j++) {
      sum += arr[j][i];
    }
    cout << "Sum is: " << sum <<endl;
  }
}

bool linearSearch(int arr[][3], int row, int col, int n) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(arr[i][j] == n) {
        return true;
      }
    }
  }
  return false;
}

void findMaxMinNum(int arr[][3], int row, int col) {
  int maxi = INT_MIN;
  int min = INT_MAX;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(arr[i][j] >= maxi) {
        maxi = arr[i][j];
      }
      if(arr[i][j] <= min) {
        min = arr[i][j];
      }
    }
  }
  cout <<  "Max Num is: " << maxi <<endl;
  cout <<  "Min Num is: " << min <<endl;
}

void transposeArray(int arr[][3], int row, int col) {
  for(int i = 0; i < row; i++) {
    for(int j = i; j < col; j++) {
      swap(arr[i][j], arr[j][i]);
    }
  }
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  //2D Vector Initialisation- Method 1
  /*
  vector<vector<int> > arr;

  vector<int> a{1,2,3};
  vector<int> b{4,5,6,10};
  vector<int> c{7,8,9};

  arr.push_back(a);
  arr.push_back(b);
  arr.push_back(c);

  for(int i = 0; i < arr.size(); i++) {
    for(int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  } */

  //2D Vector Initialisation- Method 2
  // int row = 3, col = 5;
  // vector<vector<int> > arr(row, vector<int>(col, 0));

  // for(int i = 0; i < arr.size(); i++) {
  //   for(int j = 0; j < arr[i].size(); j++) {
  //     cout << arr[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int row = 5, col = 5;
  vector<vector<int> > arr(row, vector<int>(col, -8));
  for(int i = 0; i < arr.size(); i++) {
    for(int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  
  // Transpose of Matrix
  /*
  int arr[3][3];
  int row = 3, col = 3, n;
  cout << "Enter " << row*col << " Elements:" << endl;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cin >> arr[i][j];
    }
  }
  transposeArray(arr, row, col); */
  
  // Find Min Number
  /*
  int arr[3][3];
  int row = 3, col = 3, n;
  cout << "Enter " << row*col << " Elements:" << endl;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cin >> arr[i][j];
    }
  }
  findMaxMinNum(arr, row, col); */
  
  // Find Max Number
  /*
  int arr[3][3];
  int row = 3, col = 3, n;
  cout << "Enter " << row*col << " Elements:" << endl;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cin >> arr[i][j];
    }
  }
  cout <<  "Maxi Num is: " <<findMaxNum(arr, row, col); */
  
  // Linear Search
  /*
  int arr[3][3];
  int row = 3, col = 3, n;
  cout << "Enter " << row*col << " Elements:" << endl;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cin >> arr[i][j];
    }
  }
  cout << "Enter N: ";
  cin >> n;
  cout << linearSearch(arr, row, col, n); */
  
  // Print Col Sum
  /*
  int arr[3][3];
  int row = 3, col = 3;
  cout << "Enter " << row*col << " Elements:" << endl;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cin >> arr[i][j];
    }
  }
  printColSum(arr, row, col); */
  
  // Print Row Sum
  /*
  int arr[3][3];
  int row = 3, col = 3;
  cout << "Enter Elements:" << endl;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      cin >> arr[i][j];
    }
  }
  printRowSum(arr, row, col);
  */
  
}