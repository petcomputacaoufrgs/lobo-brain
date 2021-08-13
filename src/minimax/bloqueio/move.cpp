#include <stdio.h>
#include <iostream>
#include <vector>
#include "move.hpp"
#include "vertex.hpp"

using namespace std;

vector<int> searchFreeNeighbours(Vertex* v) {

  vector<int> freeNeighbours;

  if(v != NULL) {// verifica se o vertice passado nao existe

    vector<Vertex*> neighbours = v->neighbours;// vizinhos do vertice v

    for(vector<Vertex*>::iterator it = neighbours.begin(); it != neighbours.end(); it++) {// percorre todos os vizinhos do vertice v
      if((*it)->player == '0'){// verifica se a posicao esta desocupada
        freeNeighbours.push_back((*it)->pos); // NOTE: talvez esteja errado
      }
    }
  }
  return freeNeighbours;
}
