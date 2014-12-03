/* ai.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */
 
 // AI implementation file
 
 
#ifndef AI_CPP
#define AI_CPP
 
 
#include "ai.h"

#include <math.h>
#include <algorithm>
#include <limits>

 /* Constructor */
 Hunter::Hunter() {

    bag.max_weight = 120;
    bag.rem_weight = 120;
    this->pos = aiMaze.mapBegin;
    pathfinder(this->aiMaze.trsrList);

 }

 Hunter::~Hunter() {}
 
 // TODO: test me
 // Checks the hunter's bag. If this returns true, 
 // then the hunter should start looking for the exit
 bool Hunter::isBagFull(std::vector<Treasure*>& list)
 {
   if(bag.rem_weight == 0)
   {
     return true;
   }
   
   // check the treasure list to see if the hunter can pick up anymore
   if(list.empty()) return true;
  
   // if any treasure can still fit, return false
   for(auto& trsr : list)
   {
     if(trsr->weight < bag.rem_weight) return false;
   }
 }
 
 //TODO: test me
 // Standard distance formula
 // finds the distance between the hunter and a piece of treasure
 float findDistance(XYCoords hunter, XYCoords trsr)
 {
   float distance, temp_x, temp_y;
   
   temp_x = (hunter.x - trsr.x);
   temp_x *= temp_x;
   
   temp_y = (hunter.y - trsr.y);
   temp_y *= temp_y;
   
   distance = sqrt(temp_x + temp_y);
   
   return distance;
 }
 
 
 // Finds the next piece of treasure the hunter will try to collect
 Treasure Hunter::findNearestTreasure(std::vector<Treasure>& list) 
 {
    int i, index = 0;
    float distance1, distance2 = 0;
    Treasure T;

    /* Get distance of each element in list */
    for(i = 0; i < list.size() -1; ++i) {
      distance1 = findDistance( this->pos, list[i].pos); 
      distance2 = findDistance( this->pos, list[i+1].pos);
      if(distance1 < distance2) {
        T = list[i];
        index = i;
      }
      else {
        T = list[i+1];
        index = i + 1;
      }
    }

    if(T.weight > bag.rem_weight) {
      list.erase(list.begin() + index);
      return findNearestTreasure(list);
    }

    else {
      return T;
    }

 }
 
 
 // Checks hunter's surroundings for valid movements
 void Hunter::checkPath()
 {
   // let's not allow diagonals
   // then only 4 squares need checked
 }
 
 
 // Compares complete maze map with hunter's map
 // Up to 2 moves of map will be revealed
 // Revealed portions of the map stay revealed
 void Hunter::updateMap()
 {
   
 }
 
 
 // Pathfinding function, finds route to treasure
 // awful and sloppy, but I'm ready to be done with this porject...
 void Hunter::pathfinder(std::vector<Treasure>& list)
 {
   XYCoords temp_pos = this->pos;
   XYCoords goal = findNearestTreasure(list).pos;

   std::cout << goal.x << " " << goal.y << "\n";
   
   // similar to Dijkstra's, all outgoing distances are initially
   // set to infinite.
   float north = std::numeric_limits<float>::max();
   float south = std::numeric_limits<float>::max();
   float east = std::numeric_limits<float>::max();
   float west = std::numeric_limits<float>::max();
   
   // this will be the minimal distance
   float min_val = std::numeric_limits<float>::max();
   
   
   // I'm forgetting to account for wall tiles here
   
   
   // only calculate the north tile if we aren't at the north boundary
   if(!temp_pos.y == 0)
   {
     temp_pos.y--;
     north = findDistance(temp_pos, goal);
     temp_pos.y++;
   }
   
   // only calculate the south tile if we aren't at the south boundary
   if(!temp_pos.y == 29)
   {
     temp_pos.y++;
     south = findDistance(temp_pos, goal);
     temp_pos.y--;
   }
   
   // only calculate the west tile if we aren't at the west boundary 
   if(!temp_pos.x == 0)
   {
     temp_pos.x--;
     west = findDistance(temp_pos, goal);
     temp_pos.x++;
   }
   
   // only calculate the east tile if we aren't at the east boundary
   if(!temp_pos.x == 29)
   {
     temp_pos.x++;
     east = findDistance(temp_pos, goal);
     temp_pos.x--;
   }
   
   std::cout << "COORDS " << north <<  " " << south << " " << east << " "  
    << west << "\n";
   // min_val will be set to the smallest distance
   if(north < min_val) min_val = north;
   if(south < min_val) min_val = south;
   if(east < min_val) min_val = east;
   if(west < min_val) min_val = west;
   
   // tile with the smallest distance to goal will be chosen as the 
   // destination tile.
   
   //not quite done yet
 }
 
 
#endif
 
 