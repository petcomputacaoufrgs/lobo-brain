#ifndef tabuleiro_H
#define tabuleiro_H

#include <vector>

using namespace std;

class Tabuleiro 
{
	public:
		vector<vector<char>> posicoes;
		
		Tabuleiro(vector<vector<char>> posicoes);
};

#endif
