/* th.h
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */

// main file header
 
 
#ifndef TH_H
#define TH_H

 #include <random>


struct XYCoords
{
  int x;
  int y;
};

 /* Random number generation function */
inline int randomGen(int min, int max) {

  // Seed with a real random value, if available
  std::random_device rd;
 
  // Choose a random mean between min and max
  std::default_random_engine e1(rd());
  std::uniform_int_distribution<int> uniform_dist(min, max);
  return uniform_dist(e1);

}


#endif

