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
		int size;

		Tabuleiro(Vertex *firstPos, int size);
		Tabuleiro();

		Vertex* search(int pos);

		void pongHauKiInitialPositions();
		Tabuleiro setCurrentBoard(char player, char enemy, int from, int to, vector<int> playerPos, vector<int> enemyPos);

		void print();
};


Tabuleiro pongHauKiBoard();


#endif
