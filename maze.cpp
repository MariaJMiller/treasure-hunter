/* maze.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */
 
// Maze implementation file

#include <iostream>
#include "maze.h"

/* Maze Constructor */
Maze::Maze() {

  /* Set all cells to OPEN */
  int i, j = 0;
  for(i = 0; i < ROWS; ++i) {
    for(j = 0; j < COLS; ++j) {
      this->map[i][j] = OPEN;
    }
  }

  this->placeWalls();
  this->placeExit();
  this->placeTrsr();
  this->placeBegin();
  this->setTreasureWV();

}

/* Maze Destructor */
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
  this->mapExit.x = i;
  this->mapExit.y = j;

}

void Maze::placeBegin() {

  int i, j = 0;
  i = randomGen(0, ROWS-1);
  j = randomGen(0, COLS-1);
  if(this->map[i][j] != EXIT) {
    this->map[i][j] = BEGIN;
    this->mapBegin.x = i;
    this->mapBegin.y = j;
  }

}

 /* Place treasure and set x, y values in mapTreasure. */
void Maze::placeTrsr() {

  /* BUG ** My compiler will not enter while statement 
   * when setT is declared on the same line as i and j. --Maria */
  int setT = 0;
  int j, i =0;

  /* int setT, j, i = 0; */
  
  while(setT < 1) {
    i = randomGen(0,ROWS-1);
    j = randomGen(0,COLS-1);
    /* Treasure location cannot overwrite map exit or begin. */
    if(this->map[i][j] != EXIT && this->map[i][j] != BEGIN) {
      this->map[i][j] = TRSR;
      mapTreasure.x = i;
      mapTreasure.y = j;
      ++setT;
    }
  }
}

/* Set treasure weight and value */
void Maze::setTreasureWV() {

  this->mapTreasure.value = randomGen(1, T_MAX_VALUE);
  this->mapTreasure.weight = randomGen(1, T_MAX_WEIGHT);

}

