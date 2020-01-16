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
		Vertex* board;

		Tabuleiro(Vertex *board);
};

#endif
