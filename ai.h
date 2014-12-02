/* ai.h
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */
 
// AI implementation header
 
 
#ifndef AI_H
#define AI_H
 
#include "th.h"
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

 
 // the AI class itself 
 // major functions of the AI should be placed here
 class Hunter
 {
 private:
   XYCoords pos;
   
   int morale;  // Just for fun, I'll explain later :D
   
 public:
   Hunter();
   ~Hunter();

   TreasureBag bag;
   /* The Maze the AI will traverse */
   Maze aiMaze;
   
   int getMorale() { return morale; }
   void incMorale() { ++morale; }
   void decMorale() { --morale; }
   
   bool isBagFull(std::vector<Treasure*>&);
   Treasure findNearestTreasure(std::vector<Treasure>&);
   void checkPath();
   void updateMap();
   void pathfinder();
 };
 
 #endif
 
 