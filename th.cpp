// th.cpp
// Jason McGough, Maria Miller
// Artificial Intelligence - Fall 2014

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "th.h"

/* Data for cell  value */
enum node_t {WALL = 0, TRSR = 1, OPEN = 2, 
      TRAP = 3, EXIT = 4,  BEGIN = 5};

const int ROWS = 7;
const int COLS = 7;
// Arbitrary max number of treasure in 7x7 maze.
const int TRSR_MAX = 2;   

int main() {

  int i, j = 0;

  node_t initArray[ROWS][COLS] = {
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN},
      { OPEN,OPEN,OPEN,OPEN,OPEN,OPEN,OPEN}
      };

/* Set exit and beginning, j and i are frequently the same
 * number. */
i = randomGen();
j = randomGen();

//std::cout << i << " " << j << std::endl;
initArray[i][j] = BEGIN;

while(initArray[i][j] != OPEN) {
  i = randomGen();
  j = randomGen();
}

//std::cout << i << " " << j << std::endl;
initArray[i][j] = EXIT;

                                                    


} // end main()