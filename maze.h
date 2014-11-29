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

// Arbitrary max number of wall cells in 7x7 maze.
const int WALL_MAX = 15;

const int ROWS = 7;
const int COLS = 7;

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
 };

 /* Random number generation function */
inline int randomGen(int min, int max) {

  // Seed with a real random value, if available
  std::random_device rd;
 
  // Choose a random mean between min and max
  std::default_random_engine e1(rd());
  std::uniform_int_distribution<int> uniform_dist(min, max);
  return uniform_dist(e1);

}

/* Maze class contains initial 7x7 maze */
class Maze {
private:
// treasure list?
// trap list?

public:

  Treasure mapTreasure;

  Maze();
  ~Maze();
  
  /* Initialized in constructor */
  node_t map[ROWS][COLS];

  void placeWalls();
  void placeExit();
  void placeTrsr();
  void trapTeleport();
}; /* End Maze Class */


#endif

