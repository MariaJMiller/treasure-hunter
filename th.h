// th.h
// Jason McGough, Maria Miller
// Artificial Intelligence - Fall 2014

#ifndef TH_H
#define TH_H

#include <iostream>
#include <cstdlib>
#include <ctime>

/* Generate random number */
inline int randomGen() {
  std::srand(std::time(0));
  return std::rand() % 8;
}


#endif