/* maze.h
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */


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

class Maze {
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

  /* Place walls in maze */
  void placeWalls() {

    int i, j, setW = 0;

    for(setW = 0; setW < WALL_MAX; ++setW) {
      i = randomGen();
      j = randomGen();
      this->smMaze[i][j] = WALL;
    }

  }

  /* Place exit */
  void placeExit() {

    int i, j = 0;

    i = randomGen();
    j = randomGen();
    this->smMaze[i][j] = EXIT;

  }

  void placeTrsr() {

    int setT, j, i =0;
  
    while(setT < 1) {
      i = randomGen();
      j = randomGen();
      if(this->smMaze[i][j] != EXIT) {
        this->smMaze[i][j] = TRSR;
        ++setT;
        std::cout << "PLACE TREASURE" << std::endl;
      }
    }

  }
}; /* End Maze Class */


#endif