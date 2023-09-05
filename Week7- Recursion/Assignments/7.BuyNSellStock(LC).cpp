#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int simpleIteration(vector<int>& prices) {
  int maxProfit = INT_MIN;
  
  for(int i = 0; i < prices.size(); i++) {
    for(int j = i; j < prices.size(); j++) {
      maxProfit = max(maxProfit, prices[j] - prices[i]);
    }
  }
  if(maxProfit <= 0) {
    return 0;
  }
  else return maxProfit;
}

void maxProfit(vector<int>&prices, int i, int&mini, int&profit) {
  // base case
  if(i >= prices.size()) return;

  // ek case
  if(prices[i] < mini) mini = prices[i];
  if((prices[i] - mini) > profit) profit = prices[i] - mini;

  // RE dek lega
  maxProfit(prices, i+1, mini, profit);
  // T.C & S.C >> O(n+1) >> O(n);
}

int main() {
  vector<int> prices = {7,1,5,3,6,4};
  int mini = INT_MAX;
  int profit = INT_MIN;
  
  cout << "Max Profit is: " << simpleIteration(prices) << endl;
  maxProfit(prices, 0, mini, profit);
  cout << "MAx Profit is: " << profit;
}