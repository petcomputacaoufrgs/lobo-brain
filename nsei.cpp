#include <vector>
#include <string>
#include "tree.hpp"
#include "VDE.cpp"

Node::Node decision(Node current_state, Tree game) //nem ideia
{
	 max(game, current_state, -10, 10);	
}

Node max (Tree game, Node current_state, Node alpha, Node beta)
{
	if (current_state.children.empty()) //sei la - se terminou?
		current_state.value = get_utilidade(game, current_state);
	
	for (vector<Node>::iterator it = current_state.children.begin(); it != current_state.children.end(); it++)
	{
		possible_choice = min(it, alpha, beta);
		
		if(possible_choice.value > alpha.value)
			alpha = possible_choice;
			
		if(beta.value < alpha.value)
			return beta;
	}
	
	return alpha;
}


Node min (Tree game, Node current_state, Node alpha, Node beta)
{
	if (current_state.children.empty()) //sei la - se terminou?
		current_state.value = get_utilidade(game, current_state);
	
	for (vector<Node>::iterator it = current_state.children.begin(); it != current_state.children.end(); it++)
	{
		possible_choice = max(it, alpha, beta);
		
		if(possible_choice.value < beta.value)
			beta = possible_choice;
			
		if(beta.value < alpha.value)
			return alpha;
	}
	
	return beta;
}

int get_utilidade(Tree game, Node current_state)
{			
	tabuleiroInicial inicio;
	char atual[][];
	
	boardToCString(game.root->board, inicio.posicaoInicial);
	inicio.nVezesInicial = 2;
	
	boardToCString(current_state.board, atual);
	
	return funcaoVDE(atual, '0', inicio);
	
}
			
void boardToCString (vector<string> board, char board_str[][])
{
	fodase = 0;
	for (vector<string>::iterator it = board.begin(); it != board.end(); it++)
	{
		strcpy(board_str[fodase], it.c_str()); 
		
	}
}
