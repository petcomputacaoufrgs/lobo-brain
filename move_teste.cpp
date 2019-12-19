#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "move.hpp"

using namespace std;


void printvet(vector <int> const &vet, int j) {
   cout << "--> elementos do vetor [" << j << "]: ";
   
   for(int j=0; j < vet.size(); j++)
      cout << vet.at(j) << ' ';

    cout << endl;
}

int main()
{
    int i = 1;
    int j = 1;
    int player_pos = 3*i + j;

    vector<vector<int>> possible_mov = tapatanMoves(player_pos);

   // funciona
   // move = OK

    for(int i = 0; i < possible_mov.size(); i++)
        printvet(possible_mov.at(i), i);

    return 0;
}