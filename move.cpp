#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tapatanMoves(int player_pos)
{
/* Considerando um tabuleiro de tapatan com posicoes numeradas de 0 até 8
 * recebe a posicao do jogador e retorna um vetor com todas as posicoes 
 * que o jogador pode alcancar a partir da atual. 
 * neste ultimo cada posicao eh uma dupla de int i,j (linha, coluna)
 */

   vector<vector<int>> possible_mov;
   vector<int> ij;

   switch(player_pos)
   {
      case 0://(0,0)
         ij.push_back(0); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear(); //provavelmente formas melhores de fazer isso mas sei la ponteiros 
         ij.push_back(1); ij.push_back(0);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(1);
         possible_mov.push_back(ij);
         break;
      case 1://(0,1)
         ij.push_back(0); ij.push_back(0);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(0); ij.push_back(2);
         possible_mov.push_back(ij);
         break;
      case 2://(0,2)
         ij.push_back(0); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(2);
         possible_mov.push_back(ij);
         break;
      case 3://(1,0)
         ij.push_back(0); ij.push_back(0);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(2); ij.push_back(0);
         possible_mov.push_back(ij);
         break;
      case 4://(1,1)
         ij.push_back(0); ij.push_back(0);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(0); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(0); ij.push_back(2);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(0);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(2);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(2); ij.push_back(0);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(2); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(2); ij.push_back(2);
         possible_mov.push_back(ij);
         break;
      case 5://(1,2)
         ij.push_back(0); ij.push_back(2);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(2); ij.push_back(2);
         possible_mov.push_back(ij);
         break;
      case 6://(2,0)
         ij.push_back(2); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(0);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(1);
         possible_mov.push_back(ij);
         break;
      case 7://(2,1)
         ij.push_back(2); ij.push_back(0);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(2); ij.push_back(2);
         possible_mov.push_back(ij);
         break;
      case 8://(2,2)
         ij.push_back(2); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(1);
         possible_mov.push_back(ij);
		 ij.clear();
         ij.push_back(1); ij.push_back(2);
         possible_mov.push_back(ij);
         break;
   }
   return possible_mov;
   
}


/*int main()
{
      vector<std::vector<int>> movs;
	  cout << "indo ";
	  movs = tapatanMoves(1);
	  cout << "foi" << endl;  
	
	 for (vector<vector<int>>::iterator it = movs.begin(); it != movs.end(); it++)
		 for(vector<int>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			 cout <<  *it2;
   return 0;
}*/
