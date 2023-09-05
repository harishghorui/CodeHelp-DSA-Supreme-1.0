#include <iostream>
using namespace std;

void solve(int arr[]) {
  cout <<"Size inside solve function " << sizeof(arr) << endl;
  cout <<"arr: " << arr << endl;
  cout << "&arr: " << & arr << endl;

  arr[0] = 50;
}

int main() {
  cout << "Hello...!!!" << endl << endl;
  // int arr[10];
  // arr[0] = 55;
  // arr[1] = 89;
  // arr[2] = 65;
  // int *ptr = arr;

  // cout << arr[0] << endl;
  // cout << arr[9] << endl;
  // cout << arr << endl;
  // cout << &arr << endl;
  // cout << &arr[0] << endl;
  // cout << &arr[1] << endl;
  // cout << ptr << endl;
  // cout << &ptr << endl;

  // cout << *arr << endl;
  // cout << *arr + 1 << endl;
  // cout << *(arr) + 1 << endl;
  // cout << *(arr + 1) << endl;
  // cout << *(arr + 2) << endl;

  // cout << sizeof(arr) << endl;
  // cout << sizeof(arr[0]) << endl;
  // cout << ptr << endl;
  // cout << sizeof(ptr) << endl;
  // cout << sizeof(*ptr) << endl;

  // char name[10] = "harish";
  // char* cptr = &name[0];
  // cout << "Size of Name: " << sizeof(name) << endl;
  // cout << "Size of cptr: " << sizeof(cptr) << endl << endl;

  // cout << name << endl;
  // cout << &name << endl;
  // cout << *(name + 3) << endl;
  // cout << cptr << endl;
  // cout << &cptr << endl;
  // cout << *(cptr + 3) << endl;
  // cout << cptr + 2  << endl;
  // cout << *cptr << endl;
  // cout << cptr + 8 << endl;

  int arr[10] = {1,2,3,4};
  cout << "Size inside main function. " << sizeof(arr) << endl;
  cout << arr << endl;
  cout << &arr << endl;

  //printing array inside main
  for(int i=0; i<10; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << endl << "Now calling solve function" << endl << endl;

  solve(arr);

  cout << endl << "Wapas main function me aagye h " << endl;

  for(int i=0; i<10; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}