/* ai.cpp
 * Jason McGough, Maria Miller
 * Artificial Intelligence - Fall 2014 */
 
 // AI implementation file
 
 
#ifndef AI_CPP
#define AI_CPP
 
 
#include "ai.h"

#include <math.h>

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
 float findDistance(int x1, int y1, int x2, int y2)
 {
   float distance, temp_x, temp_y;
   
   temp_x = (x1 - x2);
   temp_x *= temp_x;
   
   temp_y = (y1 - y2);
   temp_y *= temp_y;
   
   distance = sqrt(temp_x + temp_y);
   
   return distance;
 }
 
 
 // Finds the next piece of treasure the hunter will try to collect
 Treasure Hunter::findNearestTreasure(std::vector<Treasure>& list) 
 {
    int i = 0;
    float distance, temp;
    Treasure T;
    // TODO -- Check if list is empty
    /* Get distance of first Treasure, then distances of remaining list */
    distance = findDistance( this->x, this->y, list[0].x, list[0].y);
    for(i = 1; i < list.size(); ++i) {
      temp = findDistance( this->x, this->y, list[i].x, list[i].y); 
      if(temp < distance) {
        distance = temp; 
        T = list[i];
      }
    }
    /* If closest treasure fits in bag, return */
    if(T.weight <= bag.rem_weight) {
      return T;
    }
    /* Else remove that element from the list and call findNearestTreasure */
    else {
     // list.erase(list.begin())
      T = findNearestTreasure(list);
    }

   // for each treasure in treasure list
     // findDistance(hunter.x, hunter.y, treasure.x, treasure.y);
   // pick minimal distance from treasure list
   // target treasure must be able to fit into bag
   // if it cannot, pick next closest treasure
   // return to pathfinding function as goal point

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
 
 