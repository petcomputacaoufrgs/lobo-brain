#ifndef PLAYER_H
#define PLAYER_H

#include "board.hpp"
#include "../LoBoBrain.hpp"
#include <string>

using namespace std;

class Player {

public:
    explicit Player(LoBoGamesEngine* gameEngine);
    Player(LoBoGamesEngine* gameEngine, char symbol, string name);

    char symbol;
    string name;
    LoBoGamesEngine* gameEngine;

    vector<PieceCoordinates> pieces;
    vector<BoardCoordinates> possibleMoves;

private:
    char defaultSymbol = '1';
    string defaultName = "Player 1";
};

#endif
