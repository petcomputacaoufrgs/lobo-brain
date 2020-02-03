#ifndef EVALUATIONS_H
#define EVALUATIONS_H

#include <iostream>
#include <vector>
#include <string>
#include "state.hpp"
#include "evaluations.hpp"

int tapatanEvaluation(State state, char jogador, char oponente, int *rep);
int picariaEvaluation(State state, State state_ini, char jogador, char oponente, int *rep);
int threeMensMorrisEvaluation(State state, State state_ini, char jogador, char oponente, int *rep);
int altanXaraacajEvaluation(State state, State state_ini, char jogador, char oponente, int *rep);

#endif
