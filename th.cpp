/* th.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

 // This is the main file
 
#include <iostream>

#include "th.h"
#include "maze.h"


int main() {

  Maze Maze1;

  int i, j = 0;

  Maze1.placeWalls();
  Maze1.placeExit();
  Maze1.placeTrsr();

  // ERROR CHECKING** Cout array values 
  for(i = 0; i < ROWS; ++i) {
    for(j = 0; j < COLS; ++j) {
      std::cout << Maze1.smMaze[i][j] << " ";
    }
    std::cout << std::endl;
  }





                                                    


} // end main()