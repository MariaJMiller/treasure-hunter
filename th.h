/* th.h
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

// main file header
 
 
#ifndef TH_H
#define TH_H

#include <iostream>
#include <random>


/* Generate random number */
inline int randomGen() {

  // Seed with a real random value, if available
  std::random_device rd;
 
  // Choose a random mean between 0 and 6
  std::default_random_engine e1(rd());
  std::uniform_int_distribution<int> uniform_dist(0, 6);
  return uniform_dist(e1);

}

#endif