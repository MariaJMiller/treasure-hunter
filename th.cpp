// th.cpp
// Jason McGough, Maria Miller
// Artificial Intelligence - Fall 2014

#include <iostream>

#include "th.h"

/* Data for cell  value */
enum node_t {WALL = 0, TRSR = 1, OPEN = 2, 
      TRAP = 3, EXIT = 4,  BEGIN = 5};

const int ROWS = 7;
const int COLS = 7;

// Arbitrary max number of wall cells in 7x7 maze.
const int WALL_MAX = 15;

int main() {

  int i, j, setW, setT = 0;

  node_t initArray[ROWS][COLS] = {
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN}
      };

  /* Set walls */
  i,j = 0;
  for(setW = 0; setW < WALL_MAX; ++setW) {
    i = randomGen();
    j = randomGen();
    initArray[i][j] = WALL;
  }

  /* Place exit */
  i = randomGen();
  j = randomGen();
  initArray[i][j] = EXIT;

  /* Place treasure */
  setT = 0;
  while(setT < 1) {
    i = randomGen();
    j = randomGen();
    if(initArray[i][j] != EXIT) {
      initArray[i][j] = TRSR;
      ++setT;
    }
  }

  // ERROR CHECKING** Cout array values 
  for(i = 0; i < ROWS; ++i) {
    for(j = 0; j < COLS; ++j) {
      std::cout << initArray[i][j] << " ";
    }
    std::cout << std::endl;
  }





                                                    


} // end main()