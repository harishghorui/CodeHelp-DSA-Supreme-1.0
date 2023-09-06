#include <iostream>
#include <vector>
using namespace std;

int minCost4Tickets(vector<int>& days, vector<int>& cost, int i) {
  //base case
  if(i >= days.size()) return 0;

  //ek case
  // 1-Day Pass
  int case1 = cost[0] + minCost4Tickets(days, cost, i+1);

  // 7-Day Pass
  int j = i+1;
  while(j < days.size() && (days[j] - days[i]) < 7) {
    j++;
  }
  int case2 = cost[1] + minCost4Tickets(days, cost, j);

  // 30-Day Pass
  while(j < days.size() && (days[j] - days[i]) < 30) {
    j++;
  }
  int case3 = cost[2] + minCost4Tickets(days, cost, j);

  return min(case1, min(case2, case3));
}

int main() {
  vector<int> days = {2,5,10,30};
  vector<int> cost = {2,4,25};

  cout << minCost4Tickets(days, cost, 0);
}