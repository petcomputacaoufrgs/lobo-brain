#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include "vertex.hpp"

using namespace std;


/**************************************************
*	Classe tabuleiro:                             *
* 		-Armazena um vetor de vetor de char       *
* 		que representa as posicoes do tabuleiro   *
*                                                 *
* 		- Uso:                                    *
*			- Tabuleiro exemplo (<vetor>);        *
*                                                 *
***************************************************/
class Tabuleiro
{
	public:
		Vertex* firstPos;

		Tabuleiro(Vertex *firstPos);

		Vertex* search(Tabuleiro tab, int pos);

		Tabuleiro pongHauKiBoard();
};

#endif
