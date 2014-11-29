/* maze.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */
 
// Maze implementation file

#include <iostream>
#include "maze.h"

/* Constructor */
Maze::Maze() {

  /* Set all initial values to OPEN */
  int i, j = 0;
  for(i = 0; i < ROWS; ++i) {
    for(j = 0; j < COLS; ++j) {
      this->map[i][j] = OPEN;
    }
  }

  this->placeWalls();
  this->placeExit();
  this->placeTrsr();
}

/* Destructor */
Maze::~Maze() {

}
 
/* Place walls in maze */
void Maze::placeWalls() {

  int i, j, setW = 0;

  for(setW = 0; setW < WALL_MAX; ++setW) {
    i = randomGen(0,ROWS-1);
    j = randomGen(0,COLS-1);
    this->map[i][j] = WALL;
  }
} 
 
/* Place exit */
void Maze::placeExit() {
 
  int i, j = 0;

  i = randomGen(0,ROWS-1);
  j = randomGen(0,COLS-1);
  this->map[i][j] = EXIT;
}

 
 // Place treasure and create Treasure object.
void Maze::placeTrsr() {

  /* BUG ** My compiler will not enter if statement 
   * when setT is declared on the same line as i and j; */
  int setT = 0;
  int j, i =0;

  /* int setT, j, i = 0; */
  
  while(setT < 1) {
    i = randomGen(0,ROWS-1);
    j = randomGen(0,COLS-1);
    if(this->map[i][j] != EXIT) {
      this->map[i][j] = TRSR;
      mapTreasure.location_x = i;
      mapTreasure.location_y = j;
      ++setT;
    }
  }
}

