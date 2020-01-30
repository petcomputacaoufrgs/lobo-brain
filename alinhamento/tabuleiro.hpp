#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include <string>

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
	private:
		vector<vector<char>> posicoes;
		unsigned int hash;

	public:

		Tabuleiro();
		Tabuleiro(vector<vector<char>> posicoes);

		vector<vector<char>> getPositions();
		void setPositions(vector<vector<char>>);
		void setPosition(int i, int j, char player);

		unsigned int getHash();
};

#endif
