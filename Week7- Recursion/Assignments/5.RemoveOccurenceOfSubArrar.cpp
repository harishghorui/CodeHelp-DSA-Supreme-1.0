#include <iostream>
using namespace std;

void removePart(string&s, string&part, int p1) {
  //base case
  if(p1 >= s.size()) {
    return;
  }

  //ek case
  if(s.substr(p1, part.size()) == part) {
    s.erase(p1, part.size());
    removePart(s, part, 0);
  }

  removePart(s, part, p1+1);
}

void removeOccurence(string&s, string&part) {
      //ek case
      int found = s.find(part);
      if(found != string::npos) {
        s.erase(found, part.size());
        removeOccurence(s, part);
      }
      else {
        //base case
        return;
      }
}

int main() {
  string s = "daabcbaabcbc";
  string part = "abc";
  int p1 = 0;

  removePart(s, part, p1);
  //removeOccurence(s, part);
  cout << s;
}