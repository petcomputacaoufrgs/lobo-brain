#include "tabuleiro.hpp"
#include "siphasher.hpp"
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


/* contrutores */

Tabuleiro::Tabuleiro(vector<vector<char>> posicoes)
{
	this->posicoes = posicoes;
	this->hash = this->getHash();
}

Tabuleiro::Tabuleiro()
{

}

/* hash related */

unsigned int Tabuleiro::getHash() {

	/* só pra nao encurtar linha */
	vector<vector<char>> m = this->posicoes;

	/* inicializando hasher */
	SipHasher hasher;

	/* varre as linhas */
	for(int i = 0; i < m.size(); i++) {

			/* varre cada linha jogando o char pro hasher */
			for(int k = 0; k < m[i].size(); k++) {
				hasher << m[i][k];
			}

	}

	return hasher.finish();
}

/* positons related */

vector<vector<char>> Tabuleiro::getPositions() {
	return this->posicoes;
}

void Tabuleiro::setPositions(vector<vector<char>> pos) {
	this->posicoes = pos;
	this->hash = this->getHash();
}

void Tabuleiro::setPosition(int i, int j, char player) {
	this->posicoes[i][j] = player;
	this->hash = this->getHash();
}
