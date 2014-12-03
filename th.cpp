/* th.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

 // This is the main file
 
#include <iostream>
#include <vector>

#include "maze.cpp"
#include "ai.cpp"



int main() {

  int i, j = 0;

  Hunter AI;

  std::cout << "Treasure Value: \n";

  AI.aiMaze.printTreasureList();

  std::cout << "\n";

  for(i = 0; i < ROWS; ++i) {
    for(j = 0; j < COLS; ++j) {
      if(AI.aiMaze.map[i][j] == WALL) {
        std::cout << "X ";
      }
      else if(AI.aiMaze.map[i][j] == OPEN) {
        std::cout << "- ";
      }
      else if(AI.aiMaze.map[i][j] == EXIT) {
        std::cout << "E ";
      }
      else if(AI.aiMaze.map[i][j] == BEGIN) {
        std::cout << "* ";
      }
      else {
        std::cout << "0 ";
      }
    }
    std::cout << "\n";
  }


  // Display treasure collected

                                         
} // end main()

