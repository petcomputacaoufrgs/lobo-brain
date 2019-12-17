#ifndef tabuleiro_H
#define tabuleiro_H

#include <vector>

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
		vector<vector<char>> posicoes;
		
		Tabuleiro(vector<vector<char>> posicoes);
};

#endif
