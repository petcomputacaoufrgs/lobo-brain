#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <iostream>

using namespace std;

class Vertex
{
    public:
        int pos;
        char player;
        vector<Vertex*> neighbours; // lista de adjacencia (cada vertice possui uma lista de vizinhos)

        Vertex* next;

        Vertex(int pos, char player); // na inicializacao do tabuleiro
        // as casa nao ocupadas devem ser inicizalizadas com 0

        void addNeighbour(Vertex *newNeighbour);//metodo para adicionar os vizinhos da posicao

        void addVertex(Vertex *newVertex);//adiciona vertice na lista de adjacencia, ordenada pelo valor da posicao

};

#endif
