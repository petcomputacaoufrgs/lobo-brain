#include <vector>
#include <string>
#include <iostream>
#include "tabuleiro.hpp"
#include "tree.hpp"
#include "VDE.cpp"

using namespace std;

Node* max (Tree *game, Node *current_state, Node *alpha, Node *beta, int *n);
Node* min (Tree *game, Node *current_state, Node *alpha, Node *beta, int *n);

Node* max (Tree *game, Node *current_state, Node *alpha, Node *beta, int *n) {

	// possivel jogada, analisada na iteracao
	Node *possible_choice;
	// verifica se é nodo terminal
	int stt = funcaoVDE(current_state->board, game->root->board, '1', '2', n);
	
	if(stt) {
		// é terminal
		current_state->value = stt;
		return current_state;
	}

	// n terminal

	// popula arvore de possibilidades
	game->generateChildren(current_state, '1');

	// varre filhos do nodo atual, na procura da batida perfeita
	for(int i=0; i < current_state->children.size(); i++) {

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

	// aqui é tudo igual ao max mas da perspectiva do
	// oponente entao fodase le o outro

	Node *possible_choice;
	int stt = funcaoVDE(current_state->board, game->root->board, '1', '2', n);

	// VERIFICAR SE EMPATE = 3
	//	lembrar de criar (arrumar?) variavel empate global

	if(stt) {
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

	// inicializar alpha e beta "vazios"
	tabuleiro gen ( {	{'0','0','0'},
						{'0','0','0'},
						{'0','0','0'}	} );
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


//talvez nao deva ser uma main
// mas sim uma parada do tipo joga_ai{}
int main() {

	// tab.posicoesuleiro na posicao inicial
	// 0 = vazio
	// 1/2 = jogador
	tab.posicoesuleiro start = {	{'1', '2', '1'},
									{'0', '0', '0'},
									{'2', '1', '2'}		};

	// gera arvore do inicio
	Tree* test_tree = new Tree(start);
	// repeticoes inicias
	int rep = 0;
	// escolha de jogada
	Node *choice = decision(test_tree, test_tree->root, &rep);


}