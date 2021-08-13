#ifndef EVALUATIONS_H
#define EVALUATIONS_H

#include <iostream>
#include <vector>
#include <string>
#include "board.hpp"
#include "evaluations.hpp"

int tapatanEvaluation(Tabuleiro tab, Tabuleiro tab_ini, char jogador, char oponente, int *repeticoes_inicial);
int picariaEvaluation(Tabuleiro tab, Tabuleiro tab_ini, char jogador, char oponente, int *repeticoes_inicial);
int threeMensMorrisEvaluation(Tabuleiro tab, Tabuleiro tab_ini, char jogador, char oponente, int *repeticoes_inicial);
int altanXaraacajEvaluation(Tabuleiro tab, Tabuleiro tab_ini, char jogador, char oponente, int *repeticoes_inicial);

#endif
