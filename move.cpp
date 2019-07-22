#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

//ja sei q to fazendo doidera de ponteiros, vai ser mudado deixa rolar
std::vector<std::vector<int>> tapatanMoves(int player_pos)
{

   std::vector<std::vector<int>> possible_mov;
   switch(player_pos)
   {
      case 0://(0,0)
         std::vector<int> ija;
         ija[0] = 0; ija[1] = 1;
         possible_mov.push_back(ija);
         std::vector<int> ijb;
         ijb[0] = 1; ijb[1] = 0;
         possible_mov.push_back(ijb);
         std::vector<int> ijc;
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

using namespace std;
int main()
{
      std::string x[3] = {"haha","hah","hah"};

      std::cout << x[0];

   return 0;
}
