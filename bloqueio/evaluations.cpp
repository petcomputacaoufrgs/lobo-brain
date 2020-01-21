#include <iostream>
#include <vector>
#include <string>
#include "tabuleiro.hpp"
#include "move.hpp"
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
*		        - 100 se vitoria                                                                   *
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


// VAMO MUDAR COM FLAG DE NUMERO DE PECAS
int pongHauKiEvaluation(Tabuleiro board, char player, char enemy, int *rep)
{
    Vertex* aux = board.firstPos;
    vector<int> freeNeighbors;
    int vamove = 0;


    /* TESTE DERROTA */


    // varre todo grafo
    while(aux != NULL){
      // se a casa ta ocupada pelo player
      if(aux->player == player){
        // popular lista de viziinhos vazios
        freeNeighbors = searchFreeNeighbours(aux);
        // se nao houver nenhum vizinho vazio
        if(freeNeighbors.empty())
          // Incrementa var aux
          vamove += 1;
      }
      aux = aux->next;
    }

    // perdeu pq nao tem casa pra ir
    if(vamove == 2)
      return -100;


    /* TESTA VITORIA */


    // prepara pra teste
    vamove = 0;
    aux = board.firstPos;

    // varre todo grafo
    while(aux != NULL){
      // se a casa ta ocupada pelo player
      if(aux->player == enemy){
        // popular lista de viziinhos vazios
        freeNeighbors = searchFreeNeighbours(aux);
        // se nao houver nenhum vizinho vazio
        if(freeNeighbors.empty())
          // Incrementa var aux
          vamove += 1;
      }
      aux = aux->next;
    }

    // ganhou pq o adversario nao tem casa pra ir
    if(vamove == 2)
      return 100;


    /* TESTA EMPATE */

    Tabuleiro inicial = pongHauKiBoard();
    inicial.pongHauKiInitialPositions();

    if(board == inicial) {
      (*rep)++;
      if (*rep == 3) {
          return 0;
      }
    }

    //n sei
    return 0;
}
