/* maze.h
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

 // Maze implementation header
 

#ifndef MAZE_H
#define MAZE_H


#include "th.h"
#include <random>
#include <vector>


/* Data for cell  value */
 enum node_t {WALL = 0, TRSR = 1, OPEN = 2, 
    TRAP = 3, EXIT = 4,  BEGIN = 5};

/* Size of maze */
const int ROWS = 30;
const int COLS = 30;

/* Treasure max value and weight */
const int T_MAX_VALUE = 100;
const int T_MAX_WEIGHT = 20;

/* Max number of treasure on maze */
const int MAX_T = 20;



 /* Random number generation function */
inline int randomGen(int min, int max) {

  // Seed with a real random value, if available
  std::random_device rd;
 
  // Choose a random mean between min and max
  std::default_random_engine e1(rd());
  std::uniform_int_distribution<int> uniform_dist(min, max);
  return uniform_dist(e1);

}

// Treasure object, stores location, value and weight
 struct Treasure
 {
   XYCoords pos;
   int value;
   int weight;
   bool collected;
 };

 // Trap object, stores location
 struct Trap
 {
   XYCoords pos;
   XYCoords target;
 };


/* Maze class contains maze */
class Maze {
private:
// trap list?

public:

  //Treasure mapTreasure;
  XYCoords mapExit;
  XYCoords mapBegin;
  std::vector<Treasure>  trsrList;

  Maze();
  ~Maze();
  
  /* Map is initialized in constructor */
  node_t map[ROWS][COLS];

  void placeWalls();
  void placeExit();
  void placeTrsr();
  void placeBegin();
  void trapTeleport();

}; /* End Maze Class */


#endif

