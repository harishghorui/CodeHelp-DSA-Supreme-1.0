#include <iostream>
#include <vector>
using namespace std;

// Function to print the chessboard configuration
void printSolution(vector<vector<int> >&board, int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << board[i][j] << " "; // Print the value at the current cell (0 for empty, 1 for Queen)
    }
    cout << endl; // Move to the next row
  }

  cout << endl; // Separate different solutions
}

// Function to check if it's safe to place a Queen at a given position
bool isSafe(int n, int row, int col, vector<vector<int> >&board) {
  // Check left
  int i = row;
  int j = col;
  while(j >= 0) {
    if(board[i][j] == 1) {
      return false; // Another Queen is present in the same row on the left
    }
    j--;
  }

  // Check left-down diagonal
  i = row;
  j = col;
  while(j >= 0 && i < n) {
    if(board[i][j] == 1) {
      return false; // Another Queen is present in the left-down diagonal
    }
    j--;
    i++;
  }

  // Check left-up diagonal
  i = row;
  j = col;
  while(j >= 0 && i >= 0) {
    if(board[i][j] == 1) {
      return false; // Another Queen is present in the left-up diagonal
    }
    j--;
    i--;
  }

  // No Queen present in the attacking positions
  return true;
}

// Function to solve the N-Queens problem using backtracking
void solveBoard(int n, int col, vector<vector<int> >&board) {
  // Base case: all columns are processed, print the solution
  if(col >= n) {
    printSolution(board, n);
    return;
  }

  // Recursive case: try placing a Queen in each row of the current column
  for(int row = 0; row < n; row++) {
    if(isSafe(n, row, col, board)) {
      // Place the Queen in the current cell
      board[row][col] = 1;
      // Recur for the next column
      solveBoard(n, col+1, board);
      // Backtrack and remove the Queen from the current cell
      board[row][col] = 0;
    }
  }
}

int main() {
  int n = 9; // Size of the chessboard and number of Queens
  int col = 0; // Start column for placing the Queens

  // Create an empty chessboard
  vector<vector<int> > board(n, vector<int>(n, 0));

  // Start solving the N-Queens problem
  solveBoard(n, col, board);

  return 0;
}