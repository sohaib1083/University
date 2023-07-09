#include <iostream>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

// Check if the rat can move to the cell at the given position
bool canMove(int maze[][COLS], int visited[][COLS], int row, int col) {
  // Check if the cell is within the bounds of the maze
  if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
    return false;
  }
  // Check if the cell is a wall or has already been visited
  if (maze[row][col] == 1 || visited[row][col] == 1) {
    return false;
  }
  return true;
}

// Check if the rat can escape from the maze
bool canEscape(int maze[][COLS], int visited[][COLS], int row, int col) {
  // Check if the current position is one of the exit points
  if ((row == 0 && col == 3) || (row == 1 && col == 3) || (row == 2 && col == 3) || (row == 3 && col == 3)) {
    return true;
  }

  // Mark the current cell as visited
  visited[row][col] = 1;

  // Try moving in each direction
  if (canMove(maze, visited, row-1, col) && canEscape(maze, visited, row-1, col)) {
    return true;
  }
  if (canMove(maze, visited, row+1, col) && canEscape(maze, visited, row+1, col)) {
    return true;
  }
  if (canMove(maze, visited, row, col-1) && canEscape(maze, visited, row, col-1)) {
    return true;
  }
  if (canMove(maze, visited, row, col+1) && canEscape(maze, visited, row, col+1)) {
    return true;
  }

  return false;
}

int main() {
}