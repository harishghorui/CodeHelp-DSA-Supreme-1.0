#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool orderDistribute(vector<int>& counts, vector<int>& quantity, int currOrder) {
  // Base case
  if (currOrder >= quantity.size()) {
    return true;
  }

  for (int i = 0; i < counts.size(); i++) {
    if (counts[i] >= quantity[currOrder]) {
      counts[i] -= quantity[currOrder]; // Distribute the order to the current count
      if (orderDistribute(counts, quantity, currOrder + 1)) {
        return true; // Recursive call successful, orders distributed
      }

      // Backtracking: Undo the distribution for other possibilities
      counts[i] += quantity[currOrder];
    }
  }

  return false; // Orders couldn't be distributed
}

int main() {
  vector<int> nums = {1, 1, 2, 2}; // Sample order counts
  vector<int> quantity = {2, 2}; // Sample order quantities

  // Count the occurrences of each order
  unordered_map<int, int> numCounts;
  for (auto i : nums) {
    numCounts[i]++;
  }

  // Collect the order counts into a vector and sort in descending order
  vector<int> counts;
  for (auto i : numCounts) {
    counts.push_back(i.second);
  }
  sort(counts.rbegin(), counts.rend());

  // Call the distribution function and print the result
  cout << orderDistribute(counts, quantity, 0);

  return 0;
}