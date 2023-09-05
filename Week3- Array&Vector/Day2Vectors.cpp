#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int findUniqueNum(vector<int> arr) {
  int ans = 0;
  for(int i = 0; i < arr.size(); i++) {
    ans = ans ^ arr[i];
  }
  return ans;
}

void unionOfVectors(vector<int> arr1, vector<int> arr2) {
  vector<int> unionVector;
  for(int i = 0; i < arr1.size(); i++) {
    unionVector.push_back(arr1[i]);
  }
  for(int i = 0; i < arr2.size(); i++) {
    unionVector.push_back(arr2[i]);
  }

  for(int i = 0; i < unionVector.size(); i++) {
    cout << unionVector[i] << " ";
  }
}

void intersectionVector(vector<int> arr, vector<int> brr, vector<int> ans){
  for(int i = 0; i < arr.size(); i++) {
    int element = arr[i];
    for(int j = 0; j < brr.size(); j++) {
      if(element == brr[j]) {
        ans.push_back(element);
        brr[j] = -1;
      }
    }
  }

  for(auto value: ans) {
    cout << value << " ";
  }
}

void findDuplicate(vector<int> arr, vector<int> brr, vector<int> ans){
  int mark = INT_MIN;
  for(int i = 0; i < arr.size(); i++) {
    int element = arr[i];
    //for marking duplicates in arr vector
    for(int j = i+1; j < arr.size(); j++) {
      if(element == arr[j]) {
        arr[j] = mark;
      }
    }
    //for marking duplicates in brr vector
    for(int j = 0; j < brr.size(); j++) {
      if(element == brr[j]) {
        brr[j] = mark;
      }
    }
  }
  //inserting elements in ans vector which are not marked
  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] != mark) {
      ans.push_back(arr[i]);
    }
  }
  for(int i = 0; i < brr.size(); i++) {
    if(brr[i] != mark) {
      ans.push_back(brr[i]);
    }
  }
  for(auto value: ans) {
    cout << value << " ";
  }
}

void findPairSum(vector<int> arr, int sum) {
  for(int i = 0; i < arr.size(); i++) {
    for(int j = i+1; j < arr.size(); j++) {
      if(arr[i] + arr[j] == sum) {
        cout << "Found Pair: " << arr[i] << " " << arr[j] <<endl;
      }
    }
  }
}

void findTripletSum(vector<int> arr, int target) {
  for(int i = 0; i < arr.size(); i++) {
    for(int j = i+1; j < arr.size(); j++) {
      for(int k = j+1; k < arr.size(); k++) {
        if(arr[i] + arr[j] + arr[k] == target) {
          cout << "Found Target triplets: " <<arr[i]<<" "<<arr[j]<<" "<<arr[k];
          cout <<endl;
        }
      }
    }
  }
}

vector<int> sortZerosOnes(vector<int> arr) {
  int start = 0, end = arr.size()-1;
  int i = 0;
  while(start <= end) {
    if(arr[i] == 1) {
      swap(arr[i], arr[end]);
      end--;
    }
    else if(arr[i] == 0) {
      swap(arr[i], arr[start]);
      start++;
      i++;
    }
  }
  return arr;
}

int main() {

  //Sort 0's & 1's
  /*
  vector<int> arr{0,1,1,0,1,1,0,0,1,0,0};
  vector<int> ans = sortZerosOnes(arr);
  for(auto value: ans) {
    cout << value << " ";
  }
  */
  
  //Find Triplet Sum
  /*
  vector<int> arr{10,20,30,40,50,50,90,60};
  int sum = 90;
  findTripletSum(arr, sum);
  */
  
  //Find Pair Sum
  /*
  vector<int> arr{1,2,3,4,5,5,9,1};
  int sum = 6;
  findPairSum(arr, sum);
  */
  
  //print vector without duplicates
  /*
  vector<int> arr{1,2,3,4,5,5,9,1};
  vector<int> brr{3,5,4,5,6,8,20,3};

  vector<int> ans;
  findDuplicate(arr, brr, ans);
  */
  
  //Intersection of Vectors
  /*
  vector<int> arr{1,2,3,4,5,5};
  vector<int> brr{3,5,4,5,6};

  vector<int> ans;
  intersectionVector(arr, brr, ans);
  */
   
  //Union of Vectors
  /*
  int n, m;
  cout << "Enter Size of Vector1: ";
  cin >> n;
  vector<int> arr1(n);
  cout << "Enter Elements: " <<endl;
  for(int i = 0; i < arr1.size(); i++) {
    cin >> arr1[i];
  }

  cout << "Enter Size of Vector2: ";
  cin >> m;
  vector<int> arr2(m);
  cout << "Enter Elements: " <<endl;
  for(int i = 0; i < arr2.size(); i++) {
    cin >> arr2[i];
  }

  unionOfVectors(arr1, arr2);
  */
  
  // Find Unique Number in a Vector
  /*
  int n;
  cout << "Enter N: ";
  cin >> n;

  vector<int> arr(n);
  for(int i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }
  int uniqueNum = findUniqueNum(arr);
  cout << "Unique Number is: " << uniqueNum;
  */
  
  // Vector is a Dynamic Array which doesn't have a fix size
  // Vector Initialisation
  
  vector<int> arr1(10, -2); //method1 where arr size is 10 & all elements is set to -2
  for(int i = 0; i < arr1.size(); i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;

  vector<int> arr2{10,20,30,40,50}; //method2
  for(int i = 0; i < arr2.size(); i++) {
    cout << arr2[i] << " ";
  }
  cout << endl << endl;
  
  vector<int> arr3; //method3
  cout << "Empty or Not: " << arr3.empty() << endl; // to check vector is empty or not
  arr3.push_back(5);
  arr3.push_back(6);
  arr3.push_back(7);
  arr3.push_back(8);
  arr3.push_back(9);
  arr3.push_back(10); // to insert an element in vector
  arr3.pop_back(); //to remove element at the end of an vector
  cout << "Size of arr3 is: " << arr3.size() <<endl; // to check size
  cout << "Capacity of arr3 is: " <<arr3.capacity() <<endl; //to check how many elements it can store

  for(int i = 0; i < arr3.size(); i++) {
    cout << arr3[i] << " ";
  }
  cout << endl;
  
  int n;
  cout << "Enter N: ";
  cin >> n;
  vector<int> arr4(n); //method4
  for(int i = 0; i < arr4.size(); i++) {
    cout << arr4[i] << " ";
  }
  cout << endl;
  cout << arr4.empty();
  
  return 0;
}