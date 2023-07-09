#include <iostream>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

// Find the number of unique paths in the maze from the source to the destination
int numPaths(int maze[][COLS], int row, int col) {
  // Initialize the number of paths to 0
  int paths[ROWS][COLS] = {0};

  // Set the number of paths to the source cell to 1
  paths[0][0] = 1;

  // Iterate over the cells in the maze
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) 
    {
      // Check if the current cell is an open cell
      if (maze[i][j] == 1) {
        // Update the number of paths to the current cell by adding the number of paths to the cells to the north and west of it
        if (i > 0) paths[i][j] += paths[i-1][j];
        if (j > 0) paths[i][j] += paths[i][j-1];
      }
    }
  }

  // Return the number of paths to the destination cell
  return paths[row][col];
}

int main() {
  // Initialize the maze
  int maze[ROWS][COLS] = {
    {1, 1, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 0, 1},
    {1, 1, 1, 1}
  };

  cout << numPaths(maze, 3, 3) << endl; // should output 4

  return 0;
}
