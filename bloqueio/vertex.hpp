#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <iostream>

using namespace std;

class Vertex
{
    public:
        int pos; // posicao do vertice de acordo com o tabuleiro ([0, x])
        char player;
        
        Vertex(int pos, char player); // na inicializacao do tabuleiro
        // as casa nao ocupadas devem ser inicizalizadas com 0
        Vertex();

        vector<Vertex*> neighbours; // lista de adjacencia (cada vertice possui uma lista de vizinhos)

        Vertex* next; // ponteiro para a proxima posicao da lista de adj.

        void addNeighbour(Vertex *newNeighbour);//metodo para adicionar os vizinhos da posicao

        void addVertex(Vertex *newVertex);//adiciona vertice na lista de adjacencia, ordenada pelo valor da posicao

};

#endif
