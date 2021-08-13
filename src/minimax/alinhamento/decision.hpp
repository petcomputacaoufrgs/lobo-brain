#ifndef DECISION_H
#define DECISION_H

#include <vector>
#include <string>
#include <iostream>
#include "board.hpp"
#include "minimaxTree.hpp"
#include "evaluations.hpp"

using namespace std;
int minimax(Tree *game, Node *currentState, bool jump, int alpha, int beta, int *rep, bool isMax, int depth, int maxDepth);
Node* makeDecision(Tree *game, Node *currentState, bool jump, int *rep, int maxDepth);
void printBoard(Board board);

#endif
