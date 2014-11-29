/* th.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

 // This is the main file
 
#include <iostream>
#include <vector>

//#include "th.h"
#include "maze.h"
#include "ai.h"

/* Size of large maze is MAZE_SIZE x MAZE_SIZE */
const int MAZE_SIZE = 4;

int main() {

  int i,j,k = 0;
  /* largeMap vector contains pointer to each smaller maze that
   * creates the final large map used by the AI */
  std::vector<Maze*> largeMaze;

  /* Create MAZE_SIZE*MAZE_SIZE number of Maze objects for final maze. */
  for(i = 0; i < MAZE_SIZE*MAZE_SIZE; ++i) {

    Maze* m = new Maze();
    largeMaze.push_back(m);

  }

  /* Debugging only
  for(k = 0; k < MAZE_SIZE; ++k) {
  for(i = 0; i < ROWS; ++i) {
    for(j = 0; j < COLS; ++j){
      std::cout << largeMaze[k]->map[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  } 

  for(k = 0; k < largeMaze.size(); ++k) {
    std::cout << largeMaze[k]->mapTreasure.value << "\n";
  } */

/* Delete */
  for(i = 0; i < largeMaze.size(); ++i) {
    delete largeMaze[i];
  }

                                         
} // end main()

