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
Tabuleiro::Tabuleiro(vector<vector<char>> posicoes)
{
	this->posicoes = posicoes;
}

Tabuleiro::Tabuleiro()
{

}

vector<vector<char>> Tabuleiro::getBoard(){
	return this->posicoes;
}
