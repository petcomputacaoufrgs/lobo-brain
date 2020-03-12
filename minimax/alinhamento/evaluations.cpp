#include <iostream>
#include <vector>
#include <string>
#include "state.hpp"
#include "evaluations.hpp"

using namespace std;

/***********************************************************************************************
*   funcaoVDE:                                                                                 *
*       - Especificacao:                                                                       *
*           - Verifica se a partir de um determinado tabuleiro passado como entrada,           *
*           houve vitoria, derrota ou empate (VDE) do jogador atual, ou seja, retorna o        *
*           valor heuristico do nodo                                                           *
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

int tapatanEvaluation(State state, char jogador, char oponente, int *rep)
{

    vector<vector<char>> t = state.getBoard();
    vector<vector<char>> t_ini = initialBoard();

    int cont = 0;

    /*
      ===============================
                  TIE
      ===============================
    */

    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {

            if(t[i][j] == t_ini[i][j])
            {
                cont++;
                // cout << "cont = " << cont << endl;
            }
        }
    }

    // Tabuleiro igual ao do comeco -> empate
    // Retorna 0 e incrementa repeticoes do tab inicial
    if (cont == 9)
    {
        (*rep)++;
        if (*rep >= 3) {
            return 0;
        }
    }


    /*
      ===============================
                  WIN
      ===============================
    */

    if (t[0][0] == jogador)
    {
      if (t[0][1] == jogador && t[0][2] == jogador ||
            t[1][0] == jogador && t[2][0] == jogador ||
            t[1][1] == jogador && t[2][2] == jogador)
        {
            return 100;
        }
    }
    else if (t[0][2] == jogador)
    {
        if (t[1][1] == jogador && t[2][0] == jogador ||
            t[1][2] == jogador && t[2][2] == jogador)
        {
            return 100;
        }
    }
    else if (t[1][1] == jogador)
    {
        if(t[0][1] == jogador && t[2][1] == jogador ||
            t[1][0] == jogador && t[1][2] == jogador) {
            return 100;
        }
    }
    else if (t[2][0] == jogador)
    {
        if(t[2][1] == jogador && t[2][2] == jogador) {
            return 100;
        }
    }

    /*
      ===============================
                  LOSE
      ===============================
    */

	if (t[0][0] == oponente)
    {
      if (t[0][1] == oponente && t[0][2] == oponente ||
            t[1][0] == oponente && t[2][0] == oponente ||
            t[1][1] == oponente && t[2][2] == oponente)
        {
            return -100;
        }
    }
    else if (t[0][2] == oponente)
    {
        if (t[1][1] == oponente && t[2][0] == oponente ||
            t[1][2] == oponente && t[2][2] == oponente)
        {
            return -100;
        }
    }
    else if (t[1][1] == oponente)
    {
        if(t[0][1] == oponente && t[2][1] == oponente ||
            t[1][0] == oponente && t[1][2] == oponente) {
            return -100;
        }
    }
    else if (t[2][0] == oponente)
    {
        if(t[2][1] == oponente && t[2][2] == oponente) {
            return -100;
        }
    }

    /*
      ===============================
                NÃO TERMINAL
      ===============================
      acho q é aqui que entraria o
      Q-learning, pra poder retornar
      um valor
    */

    return 0;
}


int picariaEvaluation(State state, State state_ini, char jogador, char oponente, int *rep)
{

  vector<vector<char>> t = state.getBoard();
  vector<vector<char>> t_ini = state_ini.getBoard();

    int cont = 0;

    //testa empate
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {

            if(t[i][j] == t_ini[i][j])
            {
                cont++;
            }
        }
    }

    // Tabuleiro igual ao do comeco -> empate
    // Retorna 0 e incrementa repeticoes do tab inicial
    if (cont == 9)
    {
      (*rep)++;
      if (*rep >= 3) {
          return 0;
      }
    }


    //testa vitoria
    if (t[0][0] == jogador)
    {
      if (t[0][1] == jogador && t[0][2] == jogador ||
            t[1][0] == jogador && t[2][0] == jogador ||
            t[1][1] == jogador && t[2][2] == jogador)
        {
            return 100;
        }
    }
    else if (t[0][2] == jogador)
    {
        if (t[1][1] == jogador && t[2][0] == jogador ||
            t[1][2] == jogador && t[2][2] == jogador)
        {
            return 100;
        }
    }
    else if (t[1][1] == jogador)
    {
        if(t[0][1] == jogador && t[2][1] == jogador ||
            t[1][0] == jogador && t[1][2] == jogador) {
            return 100;
        }
    }
    else if (t[2][0] == jogador)
    {
        if(t[2][1] == jogador && t[2][2] == jogador) {
            return 100;
        }
    }

	//testa derrota
	if (t[0][0] == oponente)
    {
      if (t[0][1] == oponente && t[0][2] == oponente ||
            t[1][0] == oponente && t[2][0] == oponente ||
            t[1][1] == oponente && t[2][2] == oponente)
        {
            return -100;
        }
    }
    else if (t[0][2] == oponente)
    {
        if (t[1][1] == oponente && t[2][0] == oponente ||
            t[1][2] == oponente && t[2][2] == oponente)
        {
            return -100;
        }
    }
    else if (t[1][1] == oponente)
    {
        if(t[0][1] == oponente && t[2][1] == oponente ||
            t[1][0] == oponente && t[1][2] == oponente) {
            return -100;
        }
    }
    else if (t[2][0] == oponente)
    {
        if(t[2][1] == oponente && t[2][2] == oponente) {
            return -100;
        }
    }

    return 0;
}


int threeMensMorrisEvaluation(State state, State state_ini, char jogador, char oponente, int *rep)
{

  vector<vector<char>> t = state.getBoard();
  vector<vector<char>> t_ini = state_ini.getBoard();

    int cont = 0;

    //testa empate
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {

            if(t[i][j] == t_ini[i][j])
            {
                cont++;
            }
        }
    }

    // Tabuleiro igual ao do comeco -> empate
    // Retorna 0 e incrementa repeticoes do tab inicial
    if (cont == 9)
    {
      (*rep)++;
      if (*rep >= 3) {
          return 0;
      }
    }


    //testa vitoria
    if (t[0][0] == jogador)
    {
      if (t[0][1] == jogador && t[0][2] == jogador ||
            t[1][0] == jogador && t[2][0] == jogador ||
            t[1][1] == jogador && t[2][2] == jogador)
        {
            return 100;
        }
    }
    else if (t[0][2] == jogador)
    {
        if (t[1][1] == jogador && t[2][0] == jogador ||
            t[1][2] == jogador && t[2][2] == jogador)
        {
            return 100;
        }
    }
    else if (t[1][1] == jogador)
    {
        if(t[0][1] == jogador && t[2][1] == jogador ||
            t[1][0] == jogador && t[1][2] == jogador) {
            return 100;
        }
    }
    else if (t[2][0] == jogador)
    {
        if(t[2][1] == jogador && t[2][2] == jogador) {
            return 100;
        }
    }

	//testa derrota
	if (t[0][0] == oponente)
    {
      if (t[0][1] == oponente && t[0][2] == oponente ||
            t[1][0] == oponente && t[2][0] == oponente ||
            t[1][1] == oponente && t[2][2] == oponente)
        {
            return -100;
        }
    }
    else if (t[0][2] == oponente)
    {
        if (t[1][1] == oponente && t[2][0] == oponente ||
            t[1][2] == oponente && t[2][2] == oponente)
        {
            return -100;
        }
    }
    else if (t[1][1] == oponente)
    {
        if(t[0][1] == oponente && t[2][1] == oponente ||
            t[1][0] == oponente && t[1][2] == oponente) {
            return -100;
        }
    }
    else if (t[2][0] == oponente)
    {
        if(t[2][1] == oponente && t[2][2] == oponente) {
            return -100;
        }
    }

    return 0;
}


int altanXaraacajEvaluation(State state, State state_ini, char jogador, char oponente, int *rep)
{

  vector<vector<char>> t = state.getBoard();
  vector<vector<char>> t_ini = state_ini.getBoard();

    int cont = 0;

    //testa empate
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {

            if(t[i][j] == t_ini[i][j])
            {
                cont++;
            }
        }
    }

    // Tabuleiro igual ao do comeco -> empate
    // Retorna 0 e incrementa repeticoes do tab inicial
    if (cont == 9)
    {
      (*rep)++;
      if (*rep >= 3) {
          return 0;
      }
    }


    //testa vitoria
    if (t[0][0] == jogador)
    {
      if (t[0][1] == jogador && t[0][2] == jogador ||
            t[1][0] == jogador && t[2][0] == jogador)
        {
            return 100;
        }
    }
    else if (t[2][2] == jogador)
    {
        if(t[2][1] == jogador && t[2][0] == jogador ||
            t[1][2] == jogador && t[0][2] == jogador) {
            return 100;
        }
    }

	//testa derrota
  if (t[0][0] == oponente)
  {
    if (t[0][1] == oponente && t[0][2] == oponente ||
          t[1][0] == oponente && t[2][0] == oponente)
      {
          return -100;
      }
  }
  else if (t[2][2] == oponente)
  {
      if(t[2][1] == oponente && t[2][0] == oponente ||
          t[1][2] == oponente && t[0][2] == oponente) {
          return -100;
      }
  }

    return 0;
}
