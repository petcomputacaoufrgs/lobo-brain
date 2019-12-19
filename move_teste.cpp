#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "move.hpp"

using namespace std;


// aparentemente as funcoes relacionadas a move.cpp estao funcionando corretamente
int main()
{
    int player_pos = 4;

    vector<vector<int>> possible_mov = tapatanMoves(player_pos);

    for (int i = 0; i < possible_mov.size(); i++)
    {
        for (int j = 0; j < possible_mov[i].size(); j++)
        {
            cout << possible_mov[i][j];
        }
        cout << endl;
    }
    return 0;
}