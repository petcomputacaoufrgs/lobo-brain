#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "move.hpp"
#include "tabuleiro.hpp"
#include "vertex.hpp"

using namespace std;


// aparentemente as funcoes relacionadas a move.cpp estao funcionando corretamente
// AQUI TA NO GRAU TUDO FUNCIONANDO O FINO DO FINO
int main()
{

    Tabuleiro board  = pongHauKiBoard();

    board.pongHauKiInitialPositions();

    vector<int> possible_mov = searchFreeNeighbours(board.firstPos->next->next->next);

    for(vector<int>::iterator it = possible_mov.begin(); it != possible_mov.end(); it++)
    {
        cout << (*it) << endl;

    }
    return 0;
}