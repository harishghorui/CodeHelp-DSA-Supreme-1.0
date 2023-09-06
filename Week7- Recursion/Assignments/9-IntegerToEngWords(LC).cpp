  #include <iostream>
#include <vector>
using namespace std;

// Map of English Words
vector<pair<int,string>> mp = {{1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninty"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

string numToWords(int num) {
  //base case
  if(num == 0) return "Zero";
  
  //ek case
  for(auto i : mp) {
    if(num >= i.first) {
      string a = ""; //Initial(1st) num of Number. eg: Number=123, a=1
      
      if(num >= 100) { //We do not need to divide furture if num smaller 100
        
        a = numToWords(num / i.first) + " ";
        //RE call. eg: number=12345, a = 12.
      }
      
      string b = i.second;

      string c = "";
      if(num % i.first != 0) {
        //Incase of number=1000 or number=20. % will get 0, RE call will not run & will only return i.second.
        c = " " + numToWords(num % i.first);
      }

      return a + b + c;
    }
  }
  return "";
}

int main() {
  int num = 1234567890;

  cout << numToWords(num);
  
}