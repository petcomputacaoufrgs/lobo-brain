#include <iostream>
#include <vector>
#include <string>
#include "tabuleiro.hpp"
#include "evaluations.hpp"

using namespace std;

/***********************************************************************************************
*   funcaoVDE:                                                                                 *
*       - Especificacao:                                                                       *
*           - Verifica se a partir de um determinado tabuleiro passado como entrada,           *
*           houve vitoria, derrota ou empate (VDE) do jogador atual, ou seja, retorna o        *
*           valor heuristico do nodo                                                           *
*           - Para cada tabuleiro de alinhamento teremos uma funcao de VDE distinta            *                                                         *
*       -Entrada:                                                                              *
*           - Recebe como parametro o tabuleiro inicial (da forma que o jogo comecou),         *
*           o tabuleiro atual (como esta o jogo no momento que a funcao eh chamada),           *
*           o jogador atual e o oponente e o numero de repeticoes do tabuleiro inicial         *
*           (para checar possibilidade de empate)                                              *
*       - Saida:                                                                               *
*           - Retorna a pontuacao que o jogador recebe ao empatar, ganhar ou perder com        *
*           o tabuleiro passado                                                                *
*                                                                                              *
*       - Dados importantes:                                                                   *
*           - Retorna:                                                                         *
*               - 0 se o estado nao eh terminal                                                *
*		        - 100 se vitoria                                                               *
*              - -100 se derrota                                                               *
*              - -1 se empate                                                                  *
*                                                                                              *
*                                                                                              *
*       - Observacoes:                                                                         *
*           - Os valores escolhidos para vitoria e derrota                                     *
*           devem ser alterados se a altura da arvore                                          *
*           for muito grande, ou seja, ha um feature na implementacao que                      *
*           gera pesos para a pontuacao de acordo com a altura da arvore. Dessa forma,         *
*           quanto maior a altura da arvore, quer dizer que mais jogadas sao necessarias       *
*           para chegar em um determinado nodo, logo deve ocorrer uma diminuicao dessa         *
*           da pontuacao desse ramo.                                                           *
*                                                                                              *
*      - Mudancas importantes:                                                                 *
*           - Incrementava a variavel 'empate' caso ocorresse empate                           *
************************************************************************************************/
