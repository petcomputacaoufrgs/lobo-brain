#include "state.hpp"
#include "siphasher.hpp"
#include "evaluations.hpp"
#include <vector>
#include <iostream>

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


// referência
State start ({    {'2', '1', '2'},
									{'0', '0', '0'},
									{'1', '2', '1'}});

vector<vector<char>> initialBoard() {
		return start.getBoard();
}


/*
	=================
	Funções da Classe
	=================
/*


/* contrutores */

State::State(vector<vector<char>> board)
{
	this->board = board;
	this->hash = this->getHash();
}

State::State()
{

}

/* hash related */

unsigned int State::getHash() {

	/* só pra nao encurtar linha */
	vector<vector<char>> b = this->board;

	/* inicializando hasher */
	SipHasher hasher;

	/* varre as linhas */
	for(int i = 0; i < b.size(); i++) {

			/* varre cada linha jogando o char pro hasher */
			for(int k = 0; k < b[i].size(); k++) {
				hasher << b[i][k];
			}

	}

	return hasher.finish();
}

/* positons related */

vector<vector<char>> State::getBoard() {
	return this->board;
}

void State::setBoard(vector<vector<char>> board) {
	this->board = board;
	this->hash = this->getHash();
}

void State::setPosition(int i, int j, char player) {
	this->board[i][j] = player;
	this->hash = this->getHash();
}

void State::print() {

	vector<vector<char>> t = this->getBoard();

	cout << "\t=============" << endl ;

	for(int i=0; i<3; i++) {
		cout << '\t';
		for(int j=0; j<3; j++) {
			cout << "| " << t[i][j] << " ";
		}
                cout << "|" << endl;
	}

	cout << "\t=============" << endl ;

}
