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
  this->mapExit.location_x = i;
  this->mapExit.location_y = j;

}

void Maze::placeBegin() {

  int i, j = 0;
  i = randomGen(0, ROWS-1);
  j = randomGen(0, COLS-1);
  if(this->map[i][j] != EXIT) {
    this->map[i][j] = BEGIN;
    this->mapBegin.location_x = i;
    this->mapBegin.location_y = j;
  }

}

 /* Place treasure and  set x, y values in mapTreasure. */
void Maze::placeTrsr() {

  /* BUG ** My compiler will not enter while statement 
   * when setT is declared on the same line as i and j. --Maria */
  int setT = 0;
  int j, i =0;

  /* int setT, j, i = 0; */
  
  while(setT < 1) {
    i = randomGen(0,ROWS-1);
    j = randomGen(0,COLS-1);
    if(this->map[i][j] != EXIT && this->map[i][j] != BEGIN) {
      this->map[i][j] = TRSR;
      mapTreasure.location_x = i;
      mapTreasure.location_y = j;
      ++setT;
    }
  }
}

/* Exit of current maze stores values of next map's Begin x and y */
void Maze::setExitNext(int x, int y) {

  this->mapExit.next_x = x;
  this->mapExit.next_y = y;

}

