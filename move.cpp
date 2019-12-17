#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

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
std::vector<std::vector<int>> tapatanMoves(int player_pos)
{

   vector<vector<int>> possible_mov;
   switch(player_pos)
   {
      case 0://(0,0)
         vector<int> ija;
         ija[0] = 0; ija[1] = 1;
         possible_mov.push_back(ija);
         vector<int> ijb;
         ijb[0] = 1; ijb[1] = 0;
         possible_mov.push_back(ijb);
         vector<int> ijc;
         ijc[0] = 1; ijc[1] = 1;
         possible_mov.push_back(ijc);
         return possible_mov;
      case 1://(0,1)
         std::vector<int> ija;
         ija[0] = 0; ija[1] = 0;
         possible_mov.push_back(ija);
         std::vector<int> ijb;
         ijb[0] = 1; ijb[1] = 1;
         possible_mov.push_back(ijb);
         std::vector<int> ijc;
         ijc[0] = 0; ijc[1] = 2;
         possible_mov.push_back(ijc);
         return possible_mov;
      case 2://(0,2)
         ij[0] = 0; ij[1] = 1;
         possible_mov.push_back(ij);
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         ij[0] = 1; ij[1] = 2;
         possible_mov.push_back(ij);
         return possible_mov;
      case 3://(1,0)
         ij[0] = 0; ij[1] = 0;
         possible_mov.push_back(ij);
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         ij[0] = 2; ij[1] = 0;
         possible_mov.push_back(ij);
         return possible_mov;
      case 4://(1,1)
         ij[0] = 0; ij[1] = 0;
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
         ij[0] = 0; ij[1] = 2;
         possible_mov.push_back(ij);
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         ij[0] = 2; ij[1] = 2;
         possible_mov.push_back(ij);
         return possible_mov;
      case 6://(2,0)
         ij[0] = 2; ij[1] = 1;
         possible_mov.push_back(ij);
         ij[0] = 1; ij[1] = 0;
         possible_mov.push_back(ij);
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         return possible_mov;
      case 7://(2,1)
         ij[0] = 2; ij[1] = 0;
         possible_mov.push_back(ij);
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         ij[0] = 2; ij[1] = 2;
         possible_mov.push_back(ij);
         return possible_mov;
      case 8://(2,2)
         ij[0] = 2; ij[1] = 1;
         possible_mov.push_back(ij);
         ij[0] = 1; ij[1] = 1;
         possible_mov.push_back(ij);
         ij[0] = 1; ij[1] = 2;
         possible_mov.push_back(ij);
         return possible_mov;
   }
}

// int main()
// {
//       std::string x[3] = {"haha","hah","hah"};

//       std::cout << x[0];

//    return 0;
// }
