#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//hash map creation-->> to track where are previous queen placed
unordered_map<int, bool> leftRow;
unordered_map<int, bool> bottomLeftDiagonal;
unordered_map<int, bool> upperLeftDiagonal;

void printSolution(vector<vector<char> >&board, int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << board[i][j] << " " ;
    }
    cout << endl;
  }

  cout << endl ;
}

bool isSafe(int n, int row, int col) {

  //check leftRow
  if(leftRow[row] == true) {
    return false;
  }
  //left bottomLeft
  if(bottomLeftDiagonal[row+col] == true) {
    return false;
  }
  //left upperLeft
  if(upperLeftDiagonal[n-1+row-col] == true) {
    return false;
  }

  //here it means there is no Queen placed in above co-ord
  return true;
}

void solveBoard(int n, int col, vector<vector<char> > &board) {

  //base case
  if(col >= n) {
    printSolution(board, n);
    return;
  }

  //ek case
  for(int row = 0; row < n; row++) {
    if(isSafe(n, row, col)) {
      //we can place the queen & (board[][] == 1) means queen placed
      board[row][col] = 'Q';
      
      //mark maps-->>
      leftRow[row] = true;
      bottomLeftDiagonal[row+col] = true;
      upperLeftDiagonal[n-1+row-col] = true;

      //RE call--> recursion baki sab dek lega
      solveBoard(n, col+1, board);
      
      //backtracking->>
      board[row][col] = '_';
      leftRow[row] = false;
      bottomLeftDiagonal[row+col] = false;
      upperLeftDiagonal[n-1+row-col] = false;
    }
  }
}

int main() {
  int n = 4;
  int col = 0;

  //matrix of empty spaces where Queen's can be placed-->>
  vector<vector<char> > board(n, vector<char>(n, '_'));

  solveBoard(n, col, board);
}