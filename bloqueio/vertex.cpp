#include <vector>
#include <iostream>
#include "vertex.hpp"

using namespace std;

Vertex::Vertex(int pos, int player)
{
    this->pos = pos;
    this->player = player;
    this->next = NULL;
    this->neighbours = NULL;
}

void Vertex::addNeighbour(Vertex *newNeighbour)
{
  this->neighbours.push_back(newNeighbour);
}

void Vertex::addVertex(Vertex *newVertex)
{
  this->next.push_back(newVertex);
}
