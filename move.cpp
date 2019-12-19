#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "move.hpp"

using namespace std;

// Seria legal entender isso aqui

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
vector<vector<int>> tapatanMoves(int player_pos)
{
      vector<vector<int>> possible_mov;
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
         
         return possible_mov;
   }
}