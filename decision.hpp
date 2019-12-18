#ifndef DECISION_H
#define DECISION_H

#include <vector>
#include <string>
#include <iostream>
#include "tabuleiro.hpp"
#include "tree.hpp"
#include "VDE.hpp"

using namespace std;

Node* max (Tree *game, Node *current_state, Node *alpha, Node *beta, int *n);
Node* min (Tree *game, Node *current_state, Node *alpha, Node *beta, int *n);
Node* decision(Tree *game, Node *current_state, int *n);

#endif