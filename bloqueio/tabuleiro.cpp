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
Tabuleiro::Tabuleiro(Vertex *board)
{
	this->board = board;
}
