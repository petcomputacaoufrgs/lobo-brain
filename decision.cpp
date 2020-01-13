#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "tabuleiro.hpp"
#include "tree.hpp"
#include "evaluations.hpp"
#include "decision.hpp"

#include <unistd.h>				// Uncomment 4 linux
// #include <windows.h>			// Uncomment 4 windows

using namespace std;


	/* FUNÇÔES AUXILIARES */


void printa_tab(Tabuleiro tab) {

	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			cout << "| " << tab.posicoes[i][j] << " ";
		}
                cout << "|" << endl;
	}

	cout << "=============\n\n" << endl ;

}

bool empate(int rep) {
	if(rep == 3) {
		return true;
	}
	return false;
}

/*****************************************************************************************
*  	 minimax/decision(minimax):                                                          *
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
*			(condicao de parada para controlar o caso de empate), a profundidade atual   *
*           que se encontra a  busca e um booleno para verificar se eh ou nao o jogador  *
*           que devemos maximizar a jogada                                               *
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
			  int beta, int *rep, bool isMax, int depth, int max_depth) {

	// Valoração do tabuleiro atual
	int score = evaluateTapatan(current_state->board, game->root->board, '1', '2', rep);


	/* CASOS TERMINAIS */


	// Ganhou
	if(score == 100) {
		current_state->value = score - depth;
		return current_state->value;
}

	// Perdeu
	if(score == -100) {
		current_state->value = score + depth;
		return current_state->value;
}

	// Nem quem ganhar vai perder e nem quem perder vai ganhar
	if(empate(*rep)) {
		current_state->value = 0;
		return current_state->value;
}
	// Atingiu a profundidade máxima
	if(depth >= max_depth) {
		current_state->value = score + depth; // NOTE: Somar o depth faz sentido aqui?
		return current_state->value;
}


	/* CASOS NÃO TERMINAIS */


	if(isMax) {


		/* MAXIMIZING */


		int best = alpha;

		// Gera as opossiveis jogadas a partir do estado atual do jogo
		game->generateChildren(current_state, '1');

		// Varre todos os filhos (tabuleiros) gerados
		for(int i = 0; i < current_state->children.size(); i++){

			int possible_choice = minimax(game, current_state->children[i],
								          alpha, beta, rep, !isMax, depth + 1, max_depth);

			// Encontra o melhor valor heuristico ate o estado atual do jogo
			best = max(best, possible_choice);
			alpha = max(alpha, best);

			// Alpha-Beta prunning
			if(alpha >= beta)
				return best;	// Beta cut-off
		}	//Fim das recursoes

		// Retorna o valor heuristico da melhor jogada
		return best;

	}else{


		/* MINIMIZING */


		int best = beta;

		// Popula toda a arvore de possibilidades
		game->generateChildren(current_state, '2');

		// Varre filhos do nodo atual, na procura da batida perfeita
		for(int i = 0; i < current_state->children.size(); i++){

			// Recursao, comecando pela esquerda dps filhos e incrementando profundidade
			int possible_choice = minimax(game, current_state->children[i],
																			alpha, beta, rep, !isMax, depth + 1, max_depth);

			// Verifica se o resultado da recursao foi melhor do que aquele que se tem
			best = min(best, possible_choice);
			beta = min(beta, best);

			// Alpha-Beta prunning
			if(alpha >= beta)
				return best;	// Alpha cut-off
		} // Fim das recursoes

		// Retorna o valor heuristico da melhor jogada
		return best;
	}
}



Node* decision(Tree *game, Node *current_state, int *rep, int max_depth) {

	// nossos infinitos
	int alpha = -10000;
	int beta = 10000;

	// inicializar jogada
	int currentChoice;
	Node* bestChoice;

	// Gera as possiveis jogadas a partir do estado atual do jogo
	game->generateChildren(current_state, '1');

	// Varre todas as possiveis jogadas selecionando a melhor delas
	for(int i = 0; i < current_state->children.size(); i++){

			// Encontra a melhor jogada atraves do retorno do valor heuristico
			currentChoice = minimax(game, current_state->children[i],
			alpha, beta, rep, false, 1, max_depth);

			// Verifica se é a melhor jogada a ser realizada
			if (currentChoice > alpha){
				alpha = currentChoice;
				bestChoice = current_state->children[i];
				bestChoice->value = alpha;
			}

	}

	// retornar a jogada escolhida
	return bestChoice;

}
