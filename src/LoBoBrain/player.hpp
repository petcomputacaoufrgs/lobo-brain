#ifndef PLAYER_H
#define PLAYER_H

#include "board.hpp"
#include <string>

using namespace std;

class Player {

public:
    Player(char symbol, string name);
    Player();

    char symbol;
    string name;
    int score;

    vector<PieceCoordinates> pieces;

private:
    char defaultSymbol = '1';
    string defaultName = "Player 1";
}

#endif
