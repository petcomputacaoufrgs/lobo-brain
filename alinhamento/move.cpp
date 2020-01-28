#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "move.hpp"

using namespace std;

/****************************************************************************
*     tapatanMoves:                                                         *
*           - Especificacao:                                                *
*                 - A partir da posicao atual do jogador, gera uma          *
*                 lista de tuplas (i,j) [(linha, coluna)] dos               *
*                 possiveis movimentos do jogador.                          *
*                                                                           *
*           - Entrada:                                                      *
*                 - Recebe como parametro a posicao atual do jogador,       *
*                 ou seja, como o tapatan possui 9 posicoes, a entrada      *
*                 sera um inteiro [0, 8]                                    *
*                                                                           *
*           - Saida:                                                        *
*                 - Retorna uma lista de tuplas das possiveis posicoes      *
*                 que o jogador pode ir                                     *
*                                                                           *
*           - Observacoes:                                                  *
*                 - Isso aqui é extremamente ineficiente                    *
*                 deve-se implementar algo melhor para tabuleiros maiores   *
*                 i.e. grafo                                                *
*****************************************************************************/
vector<vector<int>> tapatanMoves(int player_pos)
{
      vector<vector<int>> possible_mov;
      vector<int> ij;

      switch(player_pos)
      {
      case 0://(0,0)
         ij.push_back(0); ij.push_back(1);
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 0;
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);

         return possible_mov;
      case 1://(0,1)
         ij.push_back(0); ij.push_back(0);
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);

         ij[0] = 0; ij[1] = 2;
         possible_mov.push_back(ij);

         return possible_mov;
      case 2://(0,2)
         ij.push_back(0); ij.push_back(1);
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 2;
         possible_mov.push_back(ij);

         return possible_mov;
      case 3://(1,0)
         ij.push_back(0); ij.push_back(0);
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);

         ij[0] = 2; ij[1] = 0;
         possible_mov.push_back(ij);

         return possible_mov;
      case 4://(1,1)
         ij.push_back(0); ij.push_back(0);
         possible_mov.push_back(ij);

         ij[0] = 0; ij[1] = 1;
         possible_mov.push_back(ij);

         ij[0] = 0; ij[1] = 2;
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 0;
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 2;
         possible_mov.push_back(ij);

         ij[0] = 2; ij[1] = 0;
         possible_mov.push_back(ij);

         ij[0] = 2; ij[1] = 1;
         possible_mov.push_back(ij);

         ij[0] = 2; ij[1] = 2;
         possible_mov.push_back(ij);
         return possible_mov;
      case 5://(1,2)
         ij.push_back(0); ij.push_back(2);
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);

         ij[0] = 2; ij[1] = 2;
         possible_mov.push_back(ij);

         return possible_mov;
      case 6://(2,0)
         ij.push_back(2); ij.push_back(1);
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 0;
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);

         return possible_mov;
      case 7://(2,1)
         ij.push_back(2); ij.push_back(0);
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);

         ij[0] = 2; ij[1] = 2;
         possible_mov.push_back(ij);

         return possible_mov;
      case 8://(2,2)
         ij.push_back(2); ij.push_back(1);
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);

         ij[0] = 1; ij[1] = 2;
         possible_mov.push_back(ij);

         return possible_mov;

      default: return possible_mov;
   }
}


vector<vector<int>> tapatanJumpMoves(int player_pos, Tabuleiro board)
{
      vector<vector<int>> possible_mov;
      vector<int> ij;

      switch (player_pos) {
          case 0:
            if(board.posicoes[0][1] != '0') {
              ij.push_back(0); ij.push_back(2);
              possible_mov.push_back(ij);
            }else if(board.posicoes[1][0] != '0') {
              ij.push_back(2); ij.push_back(0);
              possible_mov.push_back(ij);
            }else if(board.posicoes[1][1] != '0') {
              ij.push_back(2); ij.push_back(2);
              possible_mov.push_back(ij);
            }
            return possible_mov;

          case 1:
              if(board.posicoes[1][1] != '0') {
                ij.push_back(2); ij.push_back(1);
                possible_mov.push_back(ij);
              }
              return possible_mov;

          case 2:
            if(board.posicoes[0][1] != '0') {
              ij.push_back(0); ij.push_back(0);
              possible_mov.push_back(ij);
            }else if(board.posicoes[1][2] != '0') {
              ij.push_back(2); ij.push_back(2);
              possible_mov.push_back(ij);
            }else if(board.posicoes[1][1] != '0') {
              ij.push_back(2); ij.push_back(0);
              possible_mov.push_back(ij);
            }
            return possible_mov;

          case 3:
            if(board.posicoes[1][1] != '0') {
              ij.push_back(1); ij.push_back(2);
              possible_mov.push_back(ij);
            }
            return possible_mov;

          case 5:
            if(board.posicoes[1][1] != '0') {
              ij.push_back(1); ij.push_back(0);
              possible_mov.push_back(ij);
            }
            return possible_mov;

          case 6:
            if(board.posicoes[1][0] != '0') {
              ij.push_back(0); ij.push_back(0);
              possible_mov.push_back(ij);
            }else if(board.posicoes[2][1] != '0') {
              ij.push_back(2); ij.push_back(2);
              possible_mov.push_back(ij);
            }else if(board.posicoes[1][1] != '0') {
              ij.push_back(0); ij.push_back(2);
              possible_mov.push_back(ij);
            }
            return possible_mov;

          case 7:
            if(board.posicoes[1][1] != '0') {
              ij.push_back(0); ij.push_back(1);
              possible_mov.push_back(ij);
            }
            return possible_mov;

          case 8:
            if(board.posicoes[2][1] != '0') {
              ij.push_back(2); ij.push_back(0);
              possible_mov.push_back(ij);
            }else if(board.posicoes[1][2] != '0') {
              ij.push_back(0); ij.push_back(2);
              possible_mov.push_back(ij);
            }else if(board.posicoes[1][1] != '0') {
              ij.push_back(0); ij.push_back(0);
              possible_mov.push_back(ij);
            }
            return possible_mov;

          default: return possible_mov;

      }
}


vector<vector<int>> picariaMoves(int player_pos) {

  vector<vector<int>> possible_mov;
  vector<int> ij;

  switch(player_pos)
  {
  case 0://(0,0)
     ij.push_back(0); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 0;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     return possible_mov;
  case 1://(0,1)
     ij.push_back(0); ij.push_back(0);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 0; ij[1] = 2;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;
  case 2://(0,2)
     ij.push_back(0); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;
  case 3://(1,0)
     ij.push_back(0); ij.push_back(0);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 0;
     possible_mov.push_back(ij);

     ij[0] = 0; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 1;
     possible_mov.push_back(ij);

     return possible_mov;
  case 4://(1,1)
     ij.push_back(0); ij.push_back(0);
     possible_mov.push_back(ij);

     ij[0] = 0; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 0; ij[1] = 2;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 0;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 0;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 2;
     possible_mov.push_back(ij);
     return possible_mov;
  case 5://(1,2)
     ij.push_back(0); ij.push_back(2);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 2;
     possible_mov.push_back(ij);

     ij[0] = 0; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 1;
     possible_mov.push_back(ij);

     return possible_mov;
  case 6://(2,0)
     ij.push_back(2); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 0;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     return possible_mov;
  case 7://(2,1)
     ij.push_back(2); ij.push_back(0);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 2;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 0;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;
  case 8://(2,2)
     ij.push_back(2); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;

     default: return possible_mov;
  }

}



vector<vector<int>> threeMensMorrisMoves(int player_pos) {

  vector<vector<int>> possible_mov;
  vector<int> ij;

  switch(player_pos)
  {
  case 0://(0,0)
     ij.push_back(0); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 0;
     possible_mov.push_back(ij);

     return possible_mov;
  case 1://(0,1)
     ij.push_back(0); ij.push_back(0);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 0; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;
  case 2://(0,2)
     ij.push_back(0); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;
  case 3://(1,0)
     ij.push_back(0); ij.push_back(0);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 0;
     possible_mov.push_back(ij);

     return possible_mov;
  case 4://(1,1)
     ij.push_back(0); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 0;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 1;
     possible_mov.push_back(ij);

     return possible_mov;
  case 5://(1,2)
     ij.push_back(0); ij.push_back(2);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;
  case 6://(2,0)
     ij.push_back(2); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 0;
     possible_mov.push_back(ij);

     return possible_mov;
  case 7://(2,1)
     ij.push_back(2); ij.push_back(0);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;
  case 8://(2,2)
     ij.push_back(2); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;

     default: return possible_mov;
  }

}



vector<vector<int>> altanXaraacajMoves(int player_pos) {

  vector<vector<int>> possible_mov;
  vector<int> ij;

  switch(player_pos)
  {
  case 0://(0,0)
     ij.push_back(0); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 0;
     possible_mov.push_back(ij);

     return possible_mov;
  case 1://(0,1)
     ij.push_back(0); ij.push_back(0);
     possible_mov.push_back(ij);

     ij[0] = 0; ij[1] = 2;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 0;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;
  case 2://(0,2)
     ij.push_back(0); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;
  case 3://(1,0)
     ij.push_back(0); ij.push_back(0);
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 0;
     possible_mov.push_back(ij);

     ij[0] = 0; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 1;
     possible_mov.push_back(ij);

     return possible_mov;
  case 5://(1,2)
     ij.push_back(0); ij.push_back(2);
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 2;
     possible_mov.push_back(ij);

     ij[0] = 0; ij[1] = 1;
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 1;
     possible_mov.push_back(ij);

     return possible_mov;
  case 6://(2,0)
     ij.push_back(2); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 0;
     possible_mov.push_back(ij);

     return possible_mov;
  case 7://(2,1)
     ij.push_back(2); ij.push_back(0);
     possible_mov.push_back(ij);

     ij[0] = 2; ij[1] = 2;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 0;
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;
  case 8://(2,2)
     ij.push_back(2); ij.push_back(1);
     possible_mov.push_back(ij);

     ij[0] = 1; ij[1] = 2;
     possible_mov.push_back(ij);

     return possible_mov;

     default: return possible_mov;
  }

}
