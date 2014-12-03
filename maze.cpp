/* maze.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */
 
// Maze implementation file

#include <iostream>
#include <stdlib.h>
#include <ctime>
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
  this->placeBegin();
  this->placeTrsr();
  this->trapTeleport();
}

/* Maze Destructor */
Maze::~Maze() {

}
 
/* Place walls in maze */
void Maze::placeWalls() {

  int i, j = 0;
  float perc = .3;
  double random_value = (double)rand() / (RAND_MAX);
  srand(time(0));

  for(i = 0; i < ROWS; ++i) {
    for(j = 0; j < COLS; ++j) {
      random_value = (double)rand() / (RAND_MAX);
      if(random_value < perc){
        this->map[i][j]= WALL;
      }
    }
  } 

 }

/* Place exit */
void Maze::placeExit() {
 
  int i, j = 0;
  i = randomGen(0,ROWS-1);
  j = randomGen(0,COLS-1);
  this->map[i][j] = EXIT;
  this->mapExit.pos.x = i;
  this->mapExit.pos.y = j;

}

void Maze::placeBegin() {

  int i, j = 0;
  int set = 0;

  while(!set) {
    i = randomGen(0, ROWS-1);
    j = randomGen(0, COLS-1);
    if(this->map[i][j] != EXIT) {
      this->map[i][j] = BEGIN;
      this->mapBegin.pos.x = i;
      this->mapBegin.pos.y = j;
      ++set;
    }
  }

}

 /* Place treasure and set x, y values in mapTreasure. */
void Maze::placeTrsr() {

  /* BUG ** My compiler will not enter while statement 
   * when setT is declared on the same line as i and j. --Maria */
  int setT = 0;
  int j, i =0;
  Treasure T;

  /* int setT, j, i = 0; */
  
  while(setT < MAX_T) {
    i = randomGen(0,ROWS-1);
    j = randomGen(0,COLS-1);
    /* Treasure location cannot overwrite map exit or begin. */
    if(this->map[i][j] != EXIT && this->map[i][j] != BEGIN) {
      this->map[i][j] = TRSR;
      T.pos.x = i;
      T.pos.y = j;
      T.value = randomGen(1, T_MAX_VALUE);
      T.weight = randomGen(1, T_MAX_WEIGHT);
      trsrList.push_back(T);
      ++setT;
    }
  }
}

void Maze::trapTeleport() {

  int i, j, numTraps = 0;
  Trap T;

  float perc = .5;
  double random_value = (double)rand() / (RAND_MAX);
  srand(time(0));

  for (i = 0; i <ROWS; ++i) {
    for (j = 0; j < COLS; ++j) {
      random_value = (double)rand() / (RAND_MAX);

      // Use percolation probabilty to "randomly" place a MAX_TRAPS # of trap
      if(random_value < perc){
        // Traps are only placed on open nodes 
        if(this->map[i][j] == OPEN && numTraps < MAX_TRAPS){
          T.pos.x = i;
          T.pos.y = j;
          T.jump.x = randomGen(0, ROWS-1);
          T.jump.y = randomGen(0, COLS-1);
          this->trapList.push_back(trap);
          ++numTraps;
        }
      }     
    }
  }  
}
