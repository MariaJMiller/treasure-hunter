/* th.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

 // This is the main file
 
#include <iostream>
#include <vector>

#include "maze.cpp"
#include "ai.cpp"

/* Size of large maze is LM_ROWS*LM_COLS*/
const int LM_ROWS = 4;
const int LM_COLS = 4; 


int main() {

  int i,j,k = 0;

  Maze map_1;
  
  for(i = 0; i < ROWS; ++i) {
    for(j = 0; j < COLS; ++j) {
        std::cout << map_1.map[i][j] << " ";
    }
    std::cout << std::endl;
  }


                                         
} // end main()

