#include <iostream>
#include <vector>
using namespace std;

void beautifulArrangement(int n, int& output, vector<int>& currPerm, int currNum) {
  // Base case
  if (currNum > n) {
    output++;
    return;
  }

  for (int j = 1; j <= n; j++) {
    // Check if the current position is available and the condition for a beautiful arrangement is met
    if (currPerm[j] == 0 && (currNum % j == 0 || j % currNum == 0)) {
      currPerm[j] = currNum;
      
       // Recursively explore possibilities
      beautifulArrangement(n, output, currPerm, currNum + 1);

      // Backtracking: Undo the placement for other possibilities
      currPerm[j] = 0;
    }
  }
}

int main() {
  int n = 4;
  int output = 0;
  vector<int> currPerm(n+1);
  beautifulArrangement(n, output, currPerm, 1);
  cout << output;
}