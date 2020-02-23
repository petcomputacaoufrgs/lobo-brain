#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>
#include "agent.hpp"

using namespace std;
typedef vector<vector<char>> Tabuleiro;


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
		Agent p1();
		Agent p2();
		char playing_symbol;	// acho que isso nao precisa existir
		bool finished;
		Tabuleiro board;
		unsigned int hash; // talvez de pra tirar

	public:

		State(Agent p1, Agent p2, char playing_symbol, bool finished, Tabuleiro board);//class constructor
		void setBoard(Tabuleiro board);
		void setPosition(int i, int j, char player);
		unsigned int getHash();
		void print();
		vector<unsigned int> getPossibleMovesHashes(char player, bool jump);
		Tabuleiro getBoard();

		float winner(int *rep);//verifica se o jogo houve vencedor, empatou, ou nao terminou

		vector<vector<int>> availablePositions();//verifica as possiveis posicoes para jogar. retorna um vetor de tuplas

		vector<Tabuleiro> possibleBoards(bool jump);// gera os possiveis tabuleiros de movimentacao de determinada peca

		void updateState();//atualiza o estado do jogo, se o jogador 1 ou 2 joga, atualizando a movimentação

		void giveReward(int *rep); // da a recompensa no final de cada jogo, atraves do metodo feedReward

		void reset();//reseta todos atributos da classe State

		void play_train(int rounds); //treina o algoritmo

		void play_human();//joga contra o humano
};

Tabuleiro initialBoard();

vector<vector<int>> possibleJumpMoves(int player_pos, State state);
vector<vector<int>> possibleMoves(int player_pos);

#endif
