/* ai.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */
 
 // AI implementation file
 
 
#ifndef AI_CPP
#define AI_CPP
 
 
#include "ai.h"

#include <math.h>
#include <algorithm>

 /* Constructor */
 Hunter::Hunter() {

    bag.max_weight = 120;
    bag.rem_weight = 120;

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
 void Hunter::pathfinder()
 {
   //probably A*
 }
 
 
#endif
 
 