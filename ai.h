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
   int total_value;
 };

 
 // the AI class itself 
 // major functions of the AI should be placed here
 class Hunter
 {
 private:
   XYCoords pos;
   
   int morale;  // Reduce this if teleported away from treasure
   
 public:
   Hunter();
   ~Hunter();

   TreasureBag bag;
   /* The Maze the AI will traverse */
   Maze aiMaze;
   
   int getMorale() { return morale; }
   void incMorale() { ++morale; }
   void decMorale() { --morale; }
   
   void setPos(XYCoords new_pos) { pos = new_pos;  }
   
   int getPosX() { return pos.x; }
   int getPosY() { return pos.y; }
   
   bool isBagFull(std::vector<Treasure>&);
   Treasure findNearestTreasure(std::vector<Treasure>&);
   void updateMap();
   XYCoords pathfinder(std::vector<Treasure>&, bool);
 };
 
 #endif
 
 