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
 struct TreasureBag
 {
   int max_weight;
   int rem_weight;
   std::vector<Treasure> haul;
 };
 
 
 // This structure will contain the AI's copy of the map
 // I'll wait until we know more about the map to do this
 struct AiMap
 {
   std::vector<node_t> map; 
 };
 
 // the AI class itself 
 // major functions of the AI should be placed here
 class Hunter
 {
 private:
   int x;
   int y;
   
   int morale;  // Just for fun, I'll explain later :D
   TreasureBag bag;
   AiMap known_map;
   
 public:
   Hunter();
   ~Hunter();
   
   int getMorale() { return morale; }
   void incMorale() { ++morale; }
   void decMorale() { --morale; }
   
   bool isBagFull(Treasure*);
   Treasure findNearestTreasure();
   void checkPath();
   void updateMap();
   void pathfinder();
 };
 
 #endif
 
 