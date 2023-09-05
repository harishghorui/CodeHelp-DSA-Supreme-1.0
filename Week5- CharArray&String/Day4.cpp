#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool customComparator1(int a, int b) {
  return a > b;
}

bool customComparator2(char a, char b) {
  return a > b;
}

int main() {

  // Custom Comparator
  
  vector<int> num = {5,9,4,6,8,2,7,3,1};
  cout << "Sort Before Comparator: ";
  for(auto i : num) {
    cout << i << " ";
  }
  cout << endl;
  
  sort(num.begin(), num.end(), customComparator1);
  cout << "Sort After Comparator: ";
  for(auto i : num) {
    cout << i << " ";
  }
  cout << endl << endl;

  string s = "harishghorui";
  cout << "Sort Before Comparator: " << s;
  cout << endl;
  sort(s.begin(), s.end(), customComparator2);
  cout << "Sort After Comparator: " << s;


  return 0;
}