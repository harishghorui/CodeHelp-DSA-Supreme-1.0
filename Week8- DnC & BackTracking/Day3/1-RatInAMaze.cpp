#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, int row, int col, int maze[3][3], vector<vector<bool> >&visited) {
  
  if(x >= 0 && x < row && y >= 0 && y < col && maze[x][y] == 1 && visited[x][y] == 0) {

    return true;
  }
  else return false;
  
  // if(maze[x][y] == 1 && visited[x][y] == 0 &&
  //   (x >= 0 && y >= 0 && x < col && y < row)) {
    
  //   return true;
  // }
  // else return false; OUT OF BOUND->> checking maze & visited first
}

void ratInMaze(int maze[3][3], int row, int col, int srcX, int srcY, vector<vector<bool> >&visited, vector<string>&path, string output) {
  
  //base case
  if(srcX == row-1 && srcY == col-1) {
    path.push_back(output);
    return;
  }

  //Rat moving Direction-->>
  //Down -> srcX+1, srcY
  if(isSafe(srcX+1, srcY, row, col, maze, visited)) {
    visited[srcX+1][srcY] = true;
    ratInMaze(maze, row, col, srcX+1, srcY, visited, path, output + 'D');

    //backtracking -->>
    visited[srcX+1][srcY] = false;
  }

  //Right -> srcX, srcY+1
  if(isSafe(srcX, srcY+1, row, col, maze, visited)) {
    visited[srcX][srcY+1] = true;
    ratInMaze(maze, row, col, srcX, srcY+1, visited, path, output + 'R');

    //backtracking -->>
    visited[srcX][srcY+1] = false;
  }

  //Left -> srcX, srcY-1
  if(isSafe(srcX, srcY-1, row, col, maze, visited)) {
    visited[srcX][srcY-1] = true;
    ratInMaze(maze, row, col, srcX, srcY-1, visited, path, output + 'L');

    //backtracking -->>
    visited[srcX][srcY-1] = false;
  }

  //Up -> srcX-1, srcY
  if(isSafe(srcX-1, srcY, row, col, maze, visited)) {
    visited[srcX-1][srcY] = true;
    ratInMaze(maze, row, col, srcX-1, srcY, visited, path, output + 'U');

    //backtracking -->>
    visited[srcX-1][srcY] = false;
  }
  //This whole Right,Down,left,Up can be code in a Loop & char'L/R/D/U'

}

int main() {
  int maze[][3] = {{1,0,0}, 
                  {1,1,0}, 
                  {1,1,1}};

  //Handling Edge Cases -- >> 
  if(maze[0][0] == 0) {
    cout << "No Path Exist" << endl;
    return 0;
  }

  int row = 3;
  int col = 3;

  //Visited arr
  vector<vector<bool> > visited(row, vector<bool> (col, false));
  //mark source as true where rat is standing
  visited[0][0] = true;
  /* 2D Vector Initialisation -- >>
    We create a 2D vector containing "row" elements,
    each having the value "vector<bool> (col, false)".
    "vector<bool> (col, false)" means a vector having "col" elements,
    each of value "false".
  */

  vector<string> path;
  string output = "";

  ratInMaze(maze, row, col, 0, 0, visited, path, output);

  if(path.size() == 0) {
    cout << "No Path Exist" << endl;
    return 0;
  }
  
  for(auto i : path) {
    cout << i << " ";
  }

}