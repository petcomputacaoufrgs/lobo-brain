#include "tabuleiro.hpp"
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

	/* numeros primos pro  hashing */
	vector<unsigned int> p = {8219, 7103, 9209, 4789, 3547};

	/* unsingned para fazer wrapping e nao dar merda caso overflow */
	unsigned ihash = p[4];

	/* só pra nao encurtar linha */
	vector<vector<char>> m = this->posicoes;

	unsigned index = 0;

	/* varre as linhas */
	for(int i = 0; i < m.size(); i++) {

			vector<char> s = m[i];

			for(int k = 0; k < s.size(); k++) {
				/* o mod ta ai pra ser genérico pra qualquer tamanho de tab, wrapping */
				ihash = p[0] * ((unsigned) s[i] + index) ^ ihash * p[3];
			}

			index++;
	}
	return ihash;
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
