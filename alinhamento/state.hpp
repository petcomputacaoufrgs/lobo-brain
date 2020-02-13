#ifndef STATE_H
#define STATE_H

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
class State
{
	private:
		vector<vector<char>> board;
		unsigned int hash;

	public:

		State();
		State(vector<vector<char>> board);

		vector<vector<char>> getBoard();
		void setBoard(vector<vector<char>>);
		void setPosition(int i, int j, char player);

		unsigned int getHash();
		void print();
		vector<unsigned int> getPossibleNextStates(char player, bool jump);
};

vector<vector<char>> initialBoard();

#endif
