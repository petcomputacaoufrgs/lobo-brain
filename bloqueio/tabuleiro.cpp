#include "tabuleiro.hpp"

using namespace std;

/**************************************************
*	Estrutura tabuleiro:                          *
* 		-Armazena um vetor de vetor de char       *
* 		que representa as posicoes do tabuleiro   *
*                                                 *
* 		- Uso:                                    *
*			- Tabuleiro exemplo (<vetor>);        *
*                                                 *
***************************************************/



// 0            3
// |  >  2  <   |
// 1 ---------- 4

// Construtor
Tabuleiro::Tabuleiro(Vertex *firstPos)
{
	this->firstPos = firstPos;
}

// Construtor
Tabuleiro::Tabuleiro()
{

}

// Funcao de busca para a lista de adjacencia
Vertex* search(Tabuleiro tab, int pos) {

	Vertex* aux = tab.firstPos;

	while(tab.firstPos != NULL) {
		if(aux->pos == pos)
			return aux;
		else
			aux = aux->next;
	}
	return NULL;
}


// Gera um novo tabuleiro completamente vazio, apenas com a estrutura do Pong Hsu K'i
Tabuleiro pongHauKiBoard(){

	Vertex* pos0 = new Vertex(0, '0');
	Vertex* pos1 = new Vertex(1, '0');
	Vertex* pos2 = new Vertex(2, '0');
	Vertex* pos3 = new Vertex(3, '0');
	Vertex* pos4 = new Vertex(4, '0');

	Tabuleiro board;
	board.firstPos = pos0;

	pos0->addNeighbour(pos1);
	pos0->addNeighbour(pos2);
	pos0->addVertex(pos1);
	pos1->addNeighbour(pos0);
	pos1->addNeighbour(pos2);
	pos1->addNeighbour(pos4);
	pos1->addVertex(pos2);
	pos2->addNeighbour(pos0);
	pos2->addNeighbour(pos1);
	pos2->addNeighbour(pos3);
	pos2->addNeighbour(pos4);
	pos2->addVertex(pos3);
	pos3->addNeighbour(pos2);
	pos3->addNeighbour(pos4);
	pos3->addVertex(pos4);
	pos4->addNeighbour(pos1);
	pos4->addNeighbour(pos2);
	pos4->addNeighbour(pos3);

	return board;

}
