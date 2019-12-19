#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "move.hpp"

using namespace std;

//ja sei q to fazendo doidera de ponteiros, vai ser mudado deixa rolar

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

// do jeito q ta funciona mas mudar


// Retorna um vetor com todas jogadas possiveis dada a posicao do jogador
vector<vector<int>> tapatanMoves(int player_pos)
{
      vector<vector<int>> possible_mov;
<<<<<<< HEAD
      vector<int> ij;

// os push_back's do ij no comeco de cada case existem pq
//    o vetor iniciar vazio, logo nao dá pra setar via indice

      switch(player_pos)
      {
      case 0://(0,0)
         //(0.1)
         ij.push_back(0); ij.push_back(1);
         possible_mov.push_back(ij);
         // (1,0)
         ij[0] = 1; ij[1] = 0;
         possible_mov.push_back(ij);
         // (1,1)
         ij[1] = 1;                          
         possible_mov.push_back(ij);
         return possible_mov;
      case 1://(0,1)
         // (0,0)
         ij.push_back(0); ij.push_back(0);
         possible_mov.push_back(ij);
         // (0,2)
         ij[1] = 2;
         possible_mov.push_back(ij);
         // (1, 1)
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         return possible_mov;
      case 2://(0,2)
         // (0,1)
         ij.push_back(0); ij.push_back(1);
         possible_mov.push_back(ij);
         // (1,1)
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         // (1,2)
         ij[0] = 1; ij[1] = 2;
         possible_mov.push_back(ij);
         return possible_mov;
      case 3://(1,0)
         // (0,0)
         ij.push_back(0); ij.push_back(0);
         possible_mov.push_back(ij);
         // (0,2)
         ij[1] = 2;
         possible_mov.push_back(ij);
         // (1,1)
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         return possible_mov;
      case 4://(1,1)
         // (0,0)
         ij.push_back(0); ij.push_back(0);
         possible_mov.push_back(ij);
         // (0,1)
         ij[1] = 1;
         possible_mov.push_back(ij);
         // (0,2)
         ij[1] = 2;
         possible_mov.push_back(ij);
         // (1,0)
         ij[0] = 1; ij[1] = 0;
         possible_mov.push_back(ij);
         // (1,2)
         ij[1] = 2;
         possible_mov.push_back(ij);
         // (2,0)
         ij[0] = 2; ij[1] = 0;
         possible_mov.push_back(ij);
         // (2,1)
         ij[1] = 1;
         possible_mov.push_back(ij);
         // (2,2)
         ij[1] = 2;
         possible_mov.push_back(ij);
         return possible_mov;
      case 5://(1,2)
         // (0,2)
         ij.push_back(0); ij.push_back(2);
         possible_mov.push_back(ij);
         // (2,2)
         ij[0] = 2;
         possible_mov.push_back(ij);
         // (1,1)
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         return possible_mov;
      case 6://(2,0)
         // (2,1)
         ij.push_back(2); ij.push_back(1);
         possible_mov.push_back(ij);
         // (1,0)
         ij[0] = 1; ij[1] = 0;
         possible_mov.push_back(ij);
         // (1,1)
         ij[1] = 1;
         possible_mov.push_back(ij);
         return possible_mov;
      case 7://(2,1)
         // (2,0)
         ij.push_back(2); ij.push_back(0);
         possible_mov.push_back(ij);
         // (2,2)
         ij[1] = 2;
         possible_mov.push_back(ij);
         // (1,1)
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         return possible_mov;
      case 8://(2,2)
         // (2,1)
         ij.push_back(2); ij.push_back(1);
         possible_mov.push_back(ij);
         // (1,1)
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         // (1,2)
         ij[1] = 2;
         possible_mov.push_back(ij);
=======
      //mais uma gambiarra fodida pra consertar uma gamiarra fodida
      vector<int> ija;
      vector<int> ijb;
      vector<int> ijc;
      vector<int> ijd;
      vector<int> ije;
      vector<int> ijf;
      vector<int> ijg;
      vector<int> ijh;
      switch(player_pos)
      {
      case 0://(0,0)
         ija.push_back(0); ija.push_back(1);
         possible_mov.push_back(ija);

         ijb.push_back(1); ijb.push_back(0);
         possible_mov.push_back(ijb);

         ijc.push_back(1); ijc.push_back(1);
         possible_mov.push_back(ijc);

         return possible_mov;
      case 1://(0,1)
         ija.push_back(0); ija.push_back(0);
         possible_mov.push_back(ija);

         ijb.push_back(1); ijb.push_back(1);
         possible_mov.push_back(ijb);
         
         ijc.push_back(0); ijc.push_back(2);
         possible_mov.push_back(ijc);
         
         return possible_mov;
      case 2://(0,2)
         ija.push_back(0); ija.push_back(1);
         possible_mov.push_back(ija);
         
         ijb.push_back(1); ijb.push_back(1);
         possible_mov.push_back(ijb);
         
         ijc.push_back(1); ijc.push_back(2);
         possible_mov.push_back(ijc);
         
         return possible_mov;
      case 3://(1,0)
         ija.push_back(0); ija.push_back(0);
         possible_mov.push_back(ija);

         ijb.push_back(1); ijb.push_back(1);
         possible_mov.push_back(ijb);
         
         ija.push_back(2); ija.push_back(0);
         possible_mov.push_back(ijc);
         
         return possible_mov;
      case 4://(1,1)
         ija.push_back(0); ija.push_back(0);
         possible_mov.push_back(ija);
         
         ijb.push_back(0); ijb.push_back(1);
         possible_mov.push_back(ijb);

         ijc.push_back(0); ijc.push_back(2);
         possible_mov.push_back(ijc);
         
         ijd.push_back(1); ijd.push_back(0);
         possible_mov.push_back(ijd);

         ije.push_back(1); ije.push_back(2);
         possible_mov.push_back(ije);
         
         ijf.push_back(2); ijf.push_back(0);
         possible_mov.push_back(ijf);
         
         ijg.push_back(2); ijg.push_back(1);
         possible_mov.push_back(ijg);

         ijh.push_back(2); ijh.push_back(2);
         possible_mov.push_back(ijh);
         return possible_mov;
      case 5://(1,2)
         ija.push_back(0); ija.push_back(2);
         possible_mov.push_back(ija);

         ija.push_back(1); ijb.push_back(1);
         possible_mov.push_back(ijb);

         ijc.push_back(2); ijc.push_back(2);
         possible_mov.push_back(ijc);
         
         return possible_mov;
      case 6://(2,0)
         ija.push_back(2); ija.push_back(1);
         possible_mov.push_back(ija);
         
         ijb.push_back(1); ijb.push_back(0);
         possible_mov.push_back(ijb);
         
         ijc.push_back(1); ijc.push_back(1);
         possible_mov.push_back(ijc);
         
         return possible_mov;
      case 7://(2,1)
         ija.push_back(2); ija.push_back(0);
         possible_mov.push_back(ija);
         
         ijb.push_back(1); ijb.push_back(1);
         possible_mov.push_back(ijb);
         
         ijc.push_back(2); ijc.push_back(2);
         possible_mov.push_back(ijc);
         
         return possible_mov;
      case 8://(2,2)
         ija.push_back(2); ija.push_back(1);
         possible_mov.push_back(ija);

         ijb.push_back(1); ijb.push_back(1);
         possible_mov.push_back(ijb);
         
         ijc.push_back(1); ijc.push_back(2);
         possible_mov.push_back(ijc);
         
>>>>>>> 6ffa2e32b8c50dc01c1905b5927904d6771bae58
         return possible_mov;
   }

   // nunca deve acontecer, daria erro
   // mas retornamos o vetor pq nao é void
   return possible_mov;
}


