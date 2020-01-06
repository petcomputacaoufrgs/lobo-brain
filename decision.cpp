#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>

#include <unistd.h>
#include <windows.h>

#include "tabuleiro.hpp"
#include "tree.hpp"
#include "VDE.hpp"
#include "decision.hpp"

using namespace std;

void printa_tab(Tabuleiro tab) {

	for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++) {
			cout << "| " << tab.posicoes[i][j] << " ";
		}
                cout << "|" << endl;
	}

	cout << "====================\n\n" << endl ;

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
Node* max (Tree *game, Node *current_state, Node *alpha, Node *beta, int *n) {

	cout << "	MAX\n";
	printa_tab(current_state->board);
	//usleep(10000);
	//Sleep(5000);

	// possivel jogada, analisada na iteracao
	Node *possible_choice;
	// verifica se é nodo terminal
	int stt = funcaoVDE(current_state->board, game->root->board, '1', '2', n);
	
	if(stt) {
		// é terminal

		cout << "\n\n\tESTADO TERMINAL MAX [" << stt << "]" << endl;

		current_state->value = stt;
		return current_state;
	}

	// n terminal

	// popula arvore de possibilidades
	game->generateChildren(current_state, '1');

	// varre filhos do nodo atual, na procura da batida perfeita
	for(int i=0; i < current_state->children.size(); i++) {

		cout << i << ", " << current_state->children.size() << endl;
		

		/*

		PARA FAZER NIVEIS DE DIFICULDADE
			- a ideia é podar a árvore aleatoriamente
			com base na dificuldade selecionada
			- ter um valor base

		if(proba < valor corte) {
			continue; //'pula essa rodada do for'
		}


		*/

		// vai pros casos minimais da situacao atual
		possible_choice = min(game,
			&(current_state->children[i]),
			alpha,
			beta,
			n);

		// troca alpha pelo valor da melhor jogada
		if(possible_choice->value > alpha->value)
			alpha = possible_choice;

		// tenta realizar poda alpha-beta
		if(beta->value <= alpha->value)
			return beta;
	}

	// retorna a melhor jogada maximal
	return alpha;
}

Node* min (Tree *game, Node *current_state, Node *alpha, Node *beta, int *n) {

	cout << "	MIN\n";
	printa_tab(current_state->board);
	//usleep(10000);
	//Sleep(5000);

	// aqui é tudo igual ao max mas da perspectiva do
	// oponente entao fodase le o outro

	Node *possible_choice;
	int stt = funcaoVDE(current_state->board, game->root->board, '1', '2', n);

	// VERIFICAR SE EMPATE = 3
	//	lembrar de criar (arrumar?) variavel empate global

	if(stt) {

		cout << "\n\n\tESTADO TERMINAL MIN [" << stt << "]" << endl;

		current_state->value = stt;
		return current_state;
	}

	game->generateChildren(current_state, '2');
	for(int i=0; i < current_state->children.size(); i++) {

		

		possible_choice = max(game,
			&(current_state->children[i]),
			alpha,
			beta,
			n);

		if(possible_choice->value < beta->value)
			beta = possible_choice;

		if(beta->value <= alpha->value)
			return alpha;
	}

	return beta;

}


// executa tudo e ve qual é a melhor jogada
Node* decision(Tree *game, Node *current_state, int *n) {

	Tabuleiro gen ( {	{'0','0','0'},
						{'0','0','0'},
						{'0','0','0'}	} );

	// inicializar alpha e beta "vazios"
	Node *alpha = new Node(gen);
	Node *beta 	= new Node(gen);

	//nossos infinitos
	alpha->value = -100000;
	beta->value	 = 100000;

	// inicializar jogada
	Node *choice;

	// escolher jogada
	choice = max(game, current_state, alpha, beta, n);

	// retornar a jogada escolhida
	return choice;

}


