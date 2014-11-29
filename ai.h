/* ai.h
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */
 
 // AI implementation header
 
 
#ifndef AI_H
#define AI_H
 
#include "maze.h"
   
#include <vector>
 
// This structure will track the current and maximum weight
// the AI can carry, as well as a list of the treasure collected 
 struct Bag
 {
   int max_weight;
   int rem_weight;
   std::vector<Treasure> haul;
 };
 
 
 // This structure will contain the AI's copy of the map
 // I'll wait until we know more about the map to do this
 struct AI_Map
 {
   node_t aiMaze[ROW]{COL];
 };
 
 // the AI class itself 
 // major functions of the AI should be placed here
 class Hunter
 {
 private:
   int morale;  // Just for fun, I'll explain later :D
   
 public:
   Hunter();
   ~Hunter();
   
   int getMorale();
   void incMorale() { ++morale; }
   void decMorale() { --morale; }
   
   void findPath();
   void checkMap();
   void updateMap();
   void collectTreasure();
 };
 
 #endif
 
 