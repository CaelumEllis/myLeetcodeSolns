#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include "is_edge.hpp"

// operations on points
bool operator==(const Point& x, const Point& y) {
  return x.row == y.row and x.col == y.col;
}

bool operator!=(const Point& x, const Point& y) {
  return not (x == y);
}

Point operator+(const Point& x, const Point& y) {
  return Point {x.row + y.row, x.col + y.col};
}

// given a maze (where # denotes walls) is there an edge between Point x 
// and Point y?  For this to be true x and y have to be represent valid 
// indices into the maze, maze at these points should not be a wall, and
// y has to be one square left, up, down, or right from x
bool isEdge(const std::vector<std::string>& maze, const Point& x, 
                                                  const Point& y) {
  size_t rows = maze.size();
  size_t columns = maze[0].size();
  //check that x and y are within bounds
  if(x.row < 0 || x.row >= rows || x.col < 0 || x.col >= columns){
    return false;
  }
   if(y.row < 0 || y.row >= rows || y.col < 0 || y.col >= columns){
    return false;
  }
  //check if they are actually empty spaces
  if(maze[x.row][x.col] != ' ' || maze[y.row][y.col] != ' '){
    return false;
  }

  //if they are an adjacent column or row the difference should return as 1
  int sameRow = std::abs(x.row - y.row);
  int sameCol = std::abs(x.col - y.col);
  //if != 1, they are either the same location, diagonal which is incorrect or more than 1 row or column apart
  return sameRow + sameCol == 1;
}
