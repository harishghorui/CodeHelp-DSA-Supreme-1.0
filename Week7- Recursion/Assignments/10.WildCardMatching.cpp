#include <iostream>
using namespace std;

bool wildCardMatching(string&s, int si, string&p, int pi) {
  //base case
  if(si == s.size() && pi == p.size()) {
    return true;
  }

  if(si == s.size()) {
    while(pi < p.size()) {
      if(p[pi] != '*') {
        return false;
      }
      else return true;
    }
  }

  //single char matching
  if(s[si] == p[pi] || '?' == p[pi]) {
    return wildCardMatching(s, si+1, p, pi+1);
  }
  
  if(p[pi] == '*') {
    //treat '*' as empty or null
    bool caseA = wildCardMatching(s, si, p, pi+1);

    //let '*' consume 1char
    bool caseB = wildCardMatching(s, si+1, p, pi);

    return caseA || caseB;
  }

  //char doesn't match condition
  return false;
}

int main() {
  string s = "abcdefg";
  string p = "ab*fg";
  int si = 0;
  int pi = 0;

  cout << wildCardMatching(s, si, p, pi);
}