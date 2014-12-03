/* th.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

 // This is the main file
 
#include <iostream>
#include <vector>

#include "maze.cpp"
#include "ai.cpp"

#include <stdio.h>
#include <ctype.h>

int main() {

  bool game_loop = true;
  char choice;
  
  int i, j = 0;
  

  while(game_loop)
  {
    std::cout << " Start a treasure Hunt? [y/n]: ";
    std::cin >> choice;
    tolower(choice);
    
    if(choice == 'y') game_loop = true;
    else 
    {
      game_loop = false;
      break;
    }
    
    Hunter AI;
    
    // Prints out map to console (with ANSI colors!)
    std::cout << std::endl << std::endl << std::endl;
    
    for(i = 0; i < ROWS; ++i) {
      for(j = 0; j < COLS; ++j) {
        if(AI.aiMaze.map[i][j] == WALL) {
          std::cout << "\x1b[34mX \x1b[39;49m";
        }
        else if(AI.aiMaze.map[i][j] == OPEN) {
          std::cout << "  ";
        }
        else if(AI.aiMaze.map[i][j] == EXIT) {
          std::cout << "\x1b[31;1mE \x1b[39;49m";
        }
        else if(AI.aiMaze.map[i][j] == BEGIN) {
          std::cout << "S ";
        }
        else {
          std::cout << "\x1b[33;1m0 \x1b[39;49m";
        }
      }
      
      std::cout << std::endl;
    }
    
    std::cout << "\nBag space remaining: " << AI.bag.rem_weight << " units\n";
    std::cout << "Collected treasure value: \n";
    std::cout << "Remaining treasure value: \n";
    std::cout << std::endl << std::endl << std::endl;
  }
  
  return 0;         
} // end main()

