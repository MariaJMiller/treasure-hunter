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
    
    pos = aiMaze.mapBegin;

 }

 Hunter::~Hunter() {}
 

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
 
 
 // Pathfinding function, finds route to treasure
 // awful and sloppy, but I'm ready to be done with this porject...
 XYCoords Hunter::pathfinder(std::vector<Treasure>& list)
 {
   XYCoords north_tile;
   XYCoords south_tile;
   XYCoords east_tile;
   XYCoords west_tile;
   int flag;
   
   XYCoords goal = findNearestTreasure(list).pos;
   
   std::cout << goal.x << " " << goal.y << "\n";
   
   // similar to Dijkstra's, all outgoing distances are initially
   // set to "infinity".
   float north = std::numeric_limits<float>::max();
   float south = std::numeric_limits<float>::max();
   float east = std::numeric_limits<float>::max();
   float west = std::numeric_limits<float>::max();
  
   
   // this will be the minimal distance
   float min_val = std::numeric_limits<float>::max();
   
   
   // only calculate the north tile if it isn't the north boundary or a wall
   if(this->pos.y != 0)
   {
     north_tile.x = this->pos.x;
     north_tile.y = this->pos.x - 1;
     
     if(aiMaze.map[north_tile.x][north_tile.y] != 0)
       north = findDistance(north_tile, goal);
   }
   
   // only calculate the south tile if it isn't the south boundary or a wall
   if(this->pos.y != 29)
   {
     south_tile.x = this->pos.x;
     south_tile.y = this->pos.y + 1;
     
     if(aiMaze.map[south_tile.x][south_tile.y] != 0)
       south = findDistance(south_tile, goal);
   }
   
   // only calculate the west tile if it isn't the west boundary or a wall 
   if(this->pos.x != 0)
   {
     west_tile.x = this->pos.x - 1;
     west_tile.y = this->pos.y;
     
     if(aiMaze.map[west_tile.x][west_tile.y] != 0)
       west = findDistance(west_tile, goal);
   }
   
   // only calculate the east tile if it isn't the east boundary or a wall
   if(this->pos.x != 29)
   {
     east_tile.x = this->pos.x + 1;
     east_tile.y = this->pos.y;
     
     if(aiMaze.map[east_tile.x][east_tile.y] != 0)
       east = findDistance(east_tile, goal);
   }
   
//    std::cout << "COORDS " << north <<  " " << south << " " << east << " "  
//    << west << "\n";
   
   // min_val will be set to the smallest distance
   // flag will keep track of which tile to return
   if(north < min_val)
   {
     min_val = north;
     flag = 1;
   }
   
   if(south < min_val)
   {
     min_val = south;
     flag = 2;
   }
   
   if(east < min_val)
   {
     min_val = east;
     flag = 3;
   }
   
   if(west < min_val)
   {
     min_val = west;
     flag = 4;
   }
   
   // tile with the smallest distance to goal will be chosen as the 
   // destination tile.
   switch(flag)
   {
     case 1: return north_tile;
       break;
     case 2: return south_tile;
       break;
     case 3: return east_tile;
       break;
     case 4: return west_tile;
       break;
     default: 
     {
       std::cout << "Something has gone terribly wrong!\n\n";
       return this->pos; // has to return something I think
     }
   }
 }
 
 
#endif
 
 