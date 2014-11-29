/* maze.h
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

 // Maze implementation header
 

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <random>
#include "th.h"

/* Data for cell  value */
 enum node_t {WALL = 0, TRSR = 1, OPEN = 2, 
    TRAP = 3, EXIT = 4,  BEGIN = 5};

const int ROWS = 7;
const int COLS = 7;

// Arbitrary max number of wall cells in 7x7 maze.
const int WALL_MAX = 15;


// Treasure object, stores location, value and weight
 struct Treasure
 {
   int location_x;
   int location_y;
   int value;
   int weight;
 };

 // Trap object, stores location
 struct Trap
 {
   int location_x;
   int location_y;
 }
 

class Maze {
private:
// treasure list?
// trap list?

public:

  node_t smMaze[ROWS][COLS] = {
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN}
  };

  void placeWalls()
  void placeExit()
  void placeTrsr();
  void trapTeleport();
}; /* End Maze Class */


#endif

