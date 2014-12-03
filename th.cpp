/* th.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

 // This is the main file
 
#include <iostream>
#include <vector>

#include "maze.cpp"
#include "ai.cpp"



int main() {

  bool game_loop;
  
  int i, j = 0;

  Hunter AI;

  std::cout << std::endl << std::endl << std::endl;
  
  for(i = 0; i < ROWS; ++i) {
    for(j = 0; j < COLS; ++j) {
      if(AI.aiMaze.map[i][j] == WALL) {
        std::cout << "\x1b[36m+ \x1b[39;49m";
      }
      else if(AI.aiMaze.map[i][j] == OPEN) {
        std::cout << "  ";
      }
      else if(AI.aiMaze.map[i][j] == EXIT) {
        std::cout << "\x1b[31;1mE \x1b[39;49m";
      }
      else if(AI.aiMaze.map[i][j] == BEGIN) {
        std::cout << "S ";
      }
      else {
        std::cout << "\x1b[33;1m0 \x1b[39;49m";
      }
    }
    std::cout << std::endl;
  }
  
  std::cout << std::endl << std::endl << std::endl;

                                         
} // end main()

