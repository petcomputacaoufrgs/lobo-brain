#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
// #include <windows.h>

#include "tabuleiro.hpp"
#include "tree.hpp"
#include "VDE.hpp"
#include "decision.hpp"

using namespace std;

const int DEPTH_MAX = 2;

void printa_tab(Tabuleiro tab) {

	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			cout << "| " << tab.posicoes[i][j] << " ";
		}
                cout << "|" << endl;
	}

	cout << "====================\n\n" << endl ;

}

bool empate(int rep) {
	if(rep == 3) {
		return true;
	}
	return false;
}

/*****************************************************************************************
*  	 max/min/decision(minimax):                                                          *
*       - Especificacao:                                                                 *
*			- Executa o algoritmo minimax with alpha-beta pruning a fim de encontrar     *
*			a melhor jogada para a maquina realizar, ou seja, o algortimo executa uma    *
*			recursao mutia entre as duas funcoes min e max, com o objetivo de encontrar  *
*			uma maximizacao da jogada do jogador atual com o intuito de minimizar        *
*			os danos da possivel jogada do oponente, sempre levando como pressuposto     *
*			que o oponente executa sempre a melhor jogada (otima)                        *
*		                                                                                 *
*		- Entradas:                                                                      *
*			- Recebe umaa arvore do jogo, sempre criando filhos (possiveis jogadas)      *
*			recursivamente ao longo da execucao, o estado atual do jogo, alpha,          *
*			beta, e o numero de repeticoes do estado atual do jogo                       *
*			(condicao de parada para controlar o caso de empate)                         *
*                                                                                        *
* 		- Saida:                                                                         *
*			- Retorna ou o beta ou o alpha dependendo da melhor jogada,                  *
*			ou seja, retorna a melhr jogada dentre todas as as possiveis a partir        *
*			do tabuleiro passado como parametro                                          *
*			                                                                             *
*        - Observacoes:                                                                  *
*			- Sera implementado como feature o caso de niveis de dificuldade             *
*			que pode, eventualmente ser alterado pelo usuaro. O objetivo dessa           *
*			feature sera basicamente, a limitacao da eventual escolha otima da           *
*			jogada da maquina. Sera implementado uma verificacao, simplemente            *
*			para podar um detrminado ramo aleatorio da arvore                            *
*                                                                                        *
******************************************************************************************/
int minimax(Tree *game, Node *current_state, int alpha,
			  int beta, int *rep, bool isMax, int depth) {

// if(isMax) {
// 	cout << "\tMAX" << endl;
// }else{
// 	cout << "\tMIN" << endl;
// }

	// printa_tab(current_state->board);
	usleep(200000);


	// Valoração do tabuleiro atual
	int score = funcaoVDE(current_state->board, game->root->board, '1', '2', rep);


	/* CASOS TERMINAIS */

	// Ganhou
	if(score == 100) {
		cout << "TERMINAL 100" << endl;
		return score - depth;
	}

	// Perdeu
	if(score == -100) {
	cout << "TERMINAL -100" << endl;
		return score + depth;
	}

	// Nem quem ganhar vai perder e nem quem perder vai ganhar
	if(empate(*rep)) {
		cout << "TERMINAL 0" << endl;
		return 0;
	}

	// printf("\nprof = %d, max = %d\n", depth, DEPTH_MAX);

	// Atingiu a profundidade máxima
	if(depth >= DEPTH_MAX) {
		cout << "TERMINAL POR PROFUNDIDADE" << endl;
		cout << "VDE = " << score << endl;
		return score;
	}


	/* CASOS NÃO TERMINAIS */

	if(isMax) {

		int best = alpha;

		game->generateChildren(current_state, '1');

		for(int i = 0; i < current_state->children.size(); i++){

			// printa_tab(current_state->children[i]->board);

			int possible_choice = minimax(game, current_state->children[i],
																			alpha, beta, rep, !isMax, depth + 1);

			// printf("\nalpha = %d, beta = %d, best = %d, prof = %d, end = %p\n", alpha, beta, best, depth, &current_state);

			best = max(best, possible_choice);
			alpha = max(alpha, best);

			if(beta <= alpha)
					return best;
		}
		return best;

	}else{

		/* MINIMIZAR */

		int best = beta;

		// Popula toda a arvore de possibilidades
		game->generateChildren(current_state, '2');

		// Varre filhos do nodo atual, na procura da batida perfeita
		for(int i = 0; i < current_state->children.size(); i++){

			// printa_tab(current_state->children[i]->board);

			// Recursao, comecando pela esquerda dps filhos e incrementando profundidade
			int possible_choice = minimax(game, current_state->children[i],
																			alpha, beta, rep, !isMax, depth + 1);

			// printf("\nalpha = %d, beta = %d, best = %d, prof = %d, end = %p\n", alpha, beta, best, depth, &current_state);

			// Verifica se o resultado da recursao foi melhor do que aquele que se tem
			best = min(best, possible_choice);
			beta = min(beta, best);

			// poda
			if(beta <= alpha)
					return best;
		}// Fim das recursoes
		return best;
	}
}


/*

	***********************8
	moveVal == currentChoice->value
	bestMove == bestChoice->board

	Node* bestChoice;
	Node* currentChoice;

*/



// executa tudo e ve qual é a melhor jogada
// Node* decision(Tree *game, Node *current_state, int *n) {
//
// 	Tabuleiro gen ( {	{'0','0','0'},
// 										{'0','0','0'},
// 										{'0','0','0'}	} );
//
// 	// inicializar alpha e beta "vazios"
// 	Node *alpha = new Node(gen);
// 	Node *beta 	= new Node(gen);
//
// 	//nossos infinitos
// 	alpha->value = -10000;
// 	beta->value	 = 10000;
//
// 	// inicializar jogada
// 	Node *choice;
//
// 	// escolher jogada
// 	choice = max(game, current_state, alpha, beta, n);
//
// 	// retornar a jogada escolhida
// 	return choice;
//
// }


Node* decision(Tree *game, Node *current_state, int *rep) {

	//nossos infinitos
	int alpha = -10000;
	int beta = 10000;

	// inicializar jogada
	int currentChoice;
	Node* bestChoice;

	game->generateChildren(current_state, '1');

	for(int i = 0; i < current_state->children.size(); i++){
		// cout << "aaaaaaaaaaaaaa" << endl;
			currentChoice = minimax(game, current_state->children[i],
			alpha, beta, rep, false, 1);
			// cout << "bbbbbb" << endl;

			if (currentChoice > alpha){
				alpha = currentChoice;
				bestChoice = current_state->children[i];
				bestChoice->value = alpha;
			}
	}

	cout << "melhor valor heuristico: " << bestChoice->value << endl;

	// retornar a jogada escolhida
	return bestChoice;

}
