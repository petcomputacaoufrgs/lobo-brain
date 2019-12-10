#include <vector>
#include <string>
#include <iostream>
#include "tree.hpp"
#include "VDE.cpp"

//nao funciona mas boto fe.. acho que so estora a memoria

using namespace std;

Node* max (Tree *game, Node *current_state, Node *alpha, Node *beta, int *n);
Node* min (Tree *game, Node *current_state, Node *alpha, Node *beta, int *n);

Node* max (Tree *game, Node *current_state, Node *alpha, Node *beta, int *n)
{
	Node *possible_choice;
	int stt = funcaoVDE(current_state->board, game->root->board, '1', '2', n);
	cout << "----------------------------max-------------------------------" << endl;
	if(stt) {       //o estado eh terminal, retorna o resultado
		cout << "terminal: " << stt << endl;
		current_state->value = stt;
		return current_state;
	}
	game->generateChildren(current_state, '1');	
	for (int i=0; i < current_state->children.size(); i++)
	{
		cout << current_state->children[i].board[0] << endl << current_state->children[i].board[1] << endl << current_state->children[i].board[2] << endl;
		possible_choice = min(game, &(current_state->children[i]), alpha, beta, n);
		
		if(possible_choice->value > alpha->value)
			alpha = possible_choice;
			
		if(beta->value < alpha->value)
			return beta;
	}
	
	return alpha;
}


Node* min (Tree *game, Node *current_state, Node *alpha, Node *beta, int *n)
{
	Node *possible_choice;
	int stt = funcaoVDE(current_state->board, game->root->board, '1', '2', n);
	cout << "----------------------------min-------------------------------" << endl;
	if(stt) {       //o estado eh terminal, retorna o resultado
		cout << "terminal: " << stt << endl;
		current_state->value = stt;
		return current_state;
	}
	game->generateChildren(current_state, '2');	
	for (int i=0; i < current_state->children.size(); i++)
	{
		cout << current_state->children[i].board[0] << endl << current_state->children[i].board[1] << endl << current_state->children[i].board[2] << endl;
		possible_choice = max(game, &(current_state->children[i]), alpha, beta, n);
		
		if(possible_choice->value < beta->value)
			beta = possible_choice;
			
		if(beta->value < alpha->value)
			return alpha;
	}
	
	return beta;
}

Node* decision(Tree *game, Node *current_state, int *n) //nem ideia
{
	vector<string> gen = {"000", "000", "000"};
	Node *choice;
	Node *alpha = new Node(gen);
	Node *beta  = new Node(gen);
	alpha->value = -100;
	beta->value  =  100; 
	choice = max(game, current_state, alpha, beta, n);	
	return choice;
}
			

int main()
{
	vector<string> start = {"121", "000", "212"};

    Tree* testree = new Tree(start);
	int n = 1;
	Node *choice = decision(testree, testree->root, &n);
	cout << "escolha:" << endl << choice->board[0] << endl << choice->board[1] << endl << choice->board[2] << endl;
}
