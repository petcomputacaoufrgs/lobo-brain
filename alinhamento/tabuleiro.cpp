#include "tabuleiro.hpp"
#include <vector>
#include <iostream>
#include <string>

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

void Tabuleiro::getHash() {

	hash<string> hash_aux;
	hash<string> hash;

	// varre as linhas
	for(int i = 0; i < this->posicoes.size(); i++) {
			string aux(this->posicoes[i].begin(), this->posicoes[i].end());
			hash(aux);
			cout << hash << endl;
	}
}
