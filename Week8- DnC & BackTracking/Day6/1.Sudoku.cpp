#include <iostream>
#include <vector>
using namespace std;

bool isSafe(char num, int row, int col, int n, vector<vector<char> >&board) {

  for(int i = 0; i < n; i++) {
    //check row->>
    if(board[row][i] == num) return false;

    //check col->>
    if(board[i][col] == num) return false;

    //check 3*3 box->>
    if(board[3*(row/3)+i/3][3*(col/3)+i%3] == num) 
      return false;
    
  }
  
  return true;
}

bool solveSudoku(vector<vector<char> >&board, int n) {
  //No Base Case-->> bcoz we will solve board by placing numbers in actual board and if all the empty cell been filled, that means puzzle is solved and will return bool
  
  //ek case-->> solve for 1cell
  //traverse cells by for-for loop
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      //check for empty cell
      if(board[i][j] == '.') {
        //try fill nums from 1-9
        for(char num = '1'; num <= '9'; num++) {
          //check num can be filled by isSafe
          if(isSafe(num, i, j, n, board)) {
            board[i][j] = num;

            //RE dek lega-->>
            bool remainingCellsSoln = solveSudoku(board, n);

            if(remainingCellsSoln == true) {
              return true;
            }
            //backtrack -->> incase remainingCellSoln is false
            board[i][j] = '.';
          }
        }
        return false;
      }
    }
  }
  return true;
}

int main() {
  vector<vector<char> > board = {
  {'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'},
  };

  int n = 9;

  cout << solveSudoku(board, n) << endl << endl;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}