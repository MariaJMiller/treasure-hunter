/* maze.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */
 
// Maze implementation file

#include <iostream>
#include "maze.h"

/* Constructor */
Maze::Maze() {
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
    i = randomGen();
    j = randomGen();
    this->smMaze[i][j] = WALL;
  }
} 
 
/* Place exit */
void Maze::placeExit() {
 
  int i, j = 0;

  i = randomGen();
  j = randomGen();
  this->smMaze[i][j] = EXIT;
}

 
 // Place treasure
void Maze::placeTrsr() {

  int setT, j, i =0;
  
  while(setT < 1) {
    i = randomGen();
    j = randomGen();
    if(this->smMaze[i][j] != EXIT) {
      this->smMaze[i][j] = TRSR;
      ++setT;
    }
  }
}

