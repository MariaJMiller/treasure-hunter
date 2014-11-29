/* th.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

 // This is the main file
 
#include <iostream>
#include <vector>

//#include "th.h"
#include "maze.h"
#include "ai.h"

/* Size of large maze is LG_ROWS*LG_COLS*/
const int LG_ROWS = 4;
const int LG_COLS = 4;

int main() {

  int i,j,k = 0;

  /* largeMap vector contains pointer to each smaller maze that
   * creates the final large map used by the AI */
  std::vector<Maze*> largeMaze;

  /* List of treasure objects on the maze */
  std::vector<Treasure*> treasureList;
  /* Treasure pointer */
  Treasure* t;

  /* Create LG_ROWS*LG_COLS number of Maze objects for final maze. */
  for(i = 0; i < LG_ROWS*LG_COLS; ++i) {
    Maze* m = new Maze();
    largeMaze.push_back(m);
  }

  /* Get treasure data from largeMaze and add to treasureList */
  for(i = 0; i < LG_ROWS*LG_COLS; ++i) {
    t = &largeMaze[i]->mapTreasure;
    treasureList.push_back(t);
  }


/* Delete largeMaze */
  for(i = 0; i < largeMaze.size(); ++i) {
    delete largeMaze[i];
  }

/* Clear treasureList, may not be necessary */
  for(i = 0; i < treasureList.size(); ++i) {
    treasureList[i] = NULL;
  }

                                         
} // end main()

