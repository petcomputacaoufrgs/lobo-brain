#include <vector>
#include <iostream>

#include "vertex.hpp"

using namespace std;

/**************************************************************
* Estrutura vertex:
*   - Armazena a posicao, ordenada de 0 a X de acordo com
*   o tabuleiro
*   - Possui um ponteiro para a proxima posicao do tabuleiro
*   - Possui um ponteiro para uma lista de vizinhos, que sao
*
*                                                             *
***************************************************************/

// construtor
Vertex::Vertex(int pos, char player)
{
    this->pos = pos;
    this->player = player;
    this->next = NULL;
    this->neighbours = {};
}

Vertex::Vertex()
{

}

// adicionar vizinhos da posição do vértice
void Vertex::addNeighbour(Vertex *newNeighbour)
{
  this->neighbours.push_back(newNeighbour);
}

// adicionar uma nova posição do tabuleiro
void Vertex::addVertex(Vertex *newVertex)
{
  this->next = newVertex;
}
