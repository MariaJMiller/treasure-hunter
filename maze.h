/* maze.h
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

 // Maze implementation header
 

#ifndef MAZE_H
#define MAZE_H

#include <random>
#include <vector>


/* Data for cell  value */
 enum node_t {WALL = 0, TRSR = 1, OPEN = 2, 
    TRAP = 3, EXIT = 4,  BEGIN = 5};

// Arbitrary max number of wall cells in maze.
const int WALL_MAX = 150;

/* Size of maze */
const int ROWS = 30;
const int COLS = 30;

/* Treasure max value and weight */
const int T_MAX_VALUE = 100;
const int T_MAX_WEIGHT = 20;

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
   int x;
   int y;
   int value;
   int weight;
 };

 // Trap object, stores location
 struct Trap
 {
   int x;
   int y;
 };

/* Exit object stores location of exit */
 struct Exit
 {
    int x;
    int y;
 
 };

/* Begin object, stores location. */
 struct Begin 
 {
    int x;
    int y;
 };

/* Maze class contains maze */
class Maze {
private:
// trap list?

public:

  Treasure mapTreasure;
  Exit mapExit;
  Begin mapBegin;

  Maze();
  ~Maze();
  
  /* Map is initialized in constructor */
  node_t map[ROWS][COLS];

  void placeWalls();
  void placeExit();
  void placeTrsr();
  void placeBegin();
  void setTreasureWV();
  void trapTeleport();

}; /* End Maze Class */


#endif

