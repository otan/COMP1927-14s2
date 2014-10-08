// Map.h ... interface to Map data type

#ifndef MAP_H
#define MAP_H

#include "Places.h"

typedef struct edge{
    Location start;
    Location end;
    Transport type;
} Edge;

// graph representation is hidden 
typedef struct MapRep *Map; 

// operations on graphs 
Map newMap();  
void destroyMap(Map g); 
void showMap(Map g); 
int numV(Map g);
int numE(Map g, Transport t);
int connections(Map g, Location start, Location end, Transport []);

#endif
