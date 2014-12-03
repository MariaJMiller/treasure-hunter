/* maze.h
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

 // Maze implementation header
 

#ifndef MAZE_H
#define MAZE_H


#include "th.h"
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

/* Max number of traps on maze */
const int MAX_TRAPS = 4;

// Treasure object, stores location, value and weight
 struct Treasure
 {
   XYCoords pos;
   int value;
   int weight;
 };

 // Trap object, stores location
 struct Trap
 {
   XYCoords pos;
   XYCoords jump;
 };

/* Exit object stores location of exit */
 struct Exit
 {
   XYCoords pos;
 };

/* Begin object, stores location. */
 struct Begin 
 {
   XYCoords pos;
 };

/* Maze class contains maze */
class Maze {
private:
  std::vector<Trap> trapList;

public:

  Exit mapExit;
  Begin mapBegin;
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
  void printTreasureList();

}; /* End Maze Class */


#endif

