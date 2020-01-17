#include <stdio.h>
#include <iostream>
#include <vector>
#include "move.hpp"

using namespace std;

vector<int> searchFreeNeighbours(Vertex* v) {

  if(v != NULL) {

    vector<int> freeNeighbours;

    vector<Vertex*> neighbours = v->neighbours;

    for(vector<Vertex*>::iterator it = neighbours.begin(); it != neighbours.end(); it++) {

      if(it->player == '0')
        freeNeighbours.push_back(it->pos); // NOTE: talvez esteja errado

    }

    return freeNeighbours;

  }
  return NULL;
}
