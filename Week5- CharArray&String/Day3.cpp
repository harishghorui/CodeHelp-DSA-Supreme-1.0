#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string removeSubstring(string& s, string part) {
  int i = 0;

  while( i < s.length() ) {
    if(s.substr(i, part.length()) == part ) {
      s.erase(i, part.length());
      i = 0;
    }
    else {
      i++;
    }
  }
  return s;
}

bool checkPalindrome(string s, int i, int j) {
  while(i <= j) {
    if(s[i] == s[j]) {
      i++;
      j--;
    }
    else {
      return false;
    }
  }
  return true;
}
bool validPalindrome(string s) {
  int i = 0;
  int j = s.size()-1;
  while(i <= j) {
    if(s[i] != s[j]) {
      return (checkPalindrome(s, i, j-1) || checkPalindrome(s, i+1, j));
    }
    else {
      i++;
      j--;
    }
  }
  return true;
}

int findMinDifference(vector<string>& timePoints) {
  vector<int> minutesArray;

  //step1 - convert strings hours/mins into integers 
  for(int i = 0; i < timePoints.size(); i++) {
    string curr = timePoints[i];
    
    int hours = stoi(curr.substr(0,2));
    int minutes = stoi(curr.substr(3,2));
    int totalMinutes = hours * 60 + minutes;
    minutesArray.push_back(totalMinutes);
    // if(totalMinutes != 0) {
    //   minutesArray.push_back(totalMinutes);
    // }
    // else {
    //   minutesArray.push_back(1440);
    // }
  }
  //step2- Integer Array
  sort(minutesArray.begin(), minutesArray.end());

  //step3- difference and calculate difference
  int mini = INT_MAX;
  int n = minutesArray.size();
  
  for(int i = 0; i < n-1; i++) {
    int diff = minutesArray[i+1] - minutesArray[i];
    if(diff < mini) {
      mini = diff;
    }
  }

  //missing something?? - yes (very Important step)
  int last_diff1 = (minutesArray[0] + 1440) - minutesArray[n-1];
  int last_diff2 = (minutesArray[n-1]) - minutesArray[0];
  int last_diff = min(last_diff1, last_diff2);
  mini = min(mini, last_diff);
  return mini;
}

int checkSubstr(string s, int i, int j, int n) {
  int count = 0;
  
  while(i >= 0 && j < n && s[i] == s[j]) {
    count++;
    i--;
    j++;
  }
  return count;
}
int findPalindromicSubstr(string s) {
  int count = 0;
  int n = s.length();
  
  for(int i = 0; i < n; i++) {
    count += checkSubstr(s, i, i, n);
    count += checkSubstr(s, i, i+1, n);
  }
  
  return count;
}

int main() {

  // Palindromic Substring
  string s = "aaa";
  cout << findPalindromicSubstr(s);
  
  
  // 4.Minimum Time Diffrence- LeetCode
  /*
  vector<string> timePoints = {"23:59","00:00"};
  cout << findMinDifference(timePoints);
  */
  
  // 3.Valid Palindrome- leetcode
  /*
  string s = "leverl";
  cout << validPalindrome(s);
  */
  
  // 2.Remove all occurrences of a substring - Method2 solved on LeetCode
  // Remove all occurrences of a substring - Method1
  /*
  string s = "daabcbaabcbc";
  string part = "abc";
  removeSubstring(s, part);
  cout << s;
  */
  
  // 1.Remove all adjacent duplicates in string- LeetCode
  // Solved on LeetCode
  return 0;
}