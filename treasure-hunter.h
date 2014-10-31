// treasure-hunter.h
// Jason McGough, Maria Miller
// Artificial Intelligence - Fall 2014

#ifndef TREASURE_HUNTER_H
#define TREASURE_HUNTER_H

#include <iostream>

// Use a graph of nodes, find all possible paths from start
// to exit. Then calculate knapsack on viable paths.

class Node {
public:

 struct value {
  bool isWall = false;
  bool isTreasure = false;
  bool isTrap = false;
 } nodeValue;

 Node* ptrTop = NULL;
 Node* ptrRight = NULL;
 Node* ptrLeft = NULL;
 Node* ptrBottom = NULL;

};

class Graph {

 vector<vector<Node> > graph;

};


#endif