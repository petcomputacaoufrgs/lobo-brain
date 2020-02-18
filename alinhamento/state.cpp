#include "state.hpp"
#include "siphasher.hpp"
#include "evaluations.hpp"
#include "tree.hpp"
#include "agent.hpp"
#include <vector>
#include <iostream>

using namespace std;
typedef vector<vector<char>> Tabuleiro;


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
State start(
			{	{'2', '1', '2'},
				{'0', '0', '0'},
				{'1', '2', '1'}
			});

vector<vector<char>> initialBoard() {
		return start.getBoard();
}



/*
	=================
	Funções da Classe
	=================
/*


/* Class Contructor */
State::State(Agent p1, Agent p2, char player_symbol, bool is_end, Tabuleiro board)
{
	this->p1 = Agent(p1);
	this->p2 = Agent(p2);
	this->player_symbol = player_symbol;
	this->is_end = is_end;
	this->board = board;
	this->hash = this->getHash();
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
/*
Essa funcão vai ser usada pra saber quais hashes devem
ser procurados na Q-table
*/
vector<unsigned int> State::getPossibleMovesHashes(char player, bool jump) {

	Tree* obj = new Tree();
	vector<State> states = obj->generateStates(*this, player, jump);
	vector<unsigned int> hashes;

	for(vector<State>::iterator it = states.begin(); it != states.end(); it++) {
		hashes.push_back((*it).getHash());
	}

	// Testing results
	cout << "Hashes:" << endl;
	for(int i = 0; i < hashes.size(); i++) {
		cout << "\t#" << hashes[i] << endl;
	}

	return hashes;

}

char winner(){

}

vector<vector<int>> availablePositions(){

}

void updateState(vector<int> position){

}

void giveReward(){

}

void reset(){

}

void play_train(int rounds){

}

void play_human(){

}



