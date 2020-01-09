#ifndef DECISION_H
#define DECISION_H

#include <vector>
#include <string>
#include <iostream>
#include "tabuleiro.hpp"
#include "tree.hpp"
#include "VDE.hpp"

using namespace std;
int minimax(Tree *game, Node *current_state, int alpha, int beta, int *rep, bool isMax, int depth, int max_depth);
Node* decision(Tree *game, Node *current_state, int *rep, int max_depth);
void printa_tab(Tabuleiro tab);

#endif
