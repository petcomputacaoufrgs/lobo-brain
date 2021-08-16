#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "../LoBoBrain.hpp"

using namespace std;

typedef vector<vector<char>> BoardCoordinates;
typedef pair<BoardCoordinates, BoardCoordinates> BoardMovement;

typedef pair<int, int> PieceCoordinates;
typedef pair<PieceCoordinates, PieceCoordinates> PieceMovement;


class Board
{
public:

    // Initialization without
    // board specification
    Board(LoBoGamesEngine* gameEngine);

    // Initialization with
    // board specification
    explicit Board(LoBoGamesEngine* game, BoardCoordinates boardSetup);

    LoBoGamesEngine* gameEngine;

    // Setter for updating board
    void updateSetup(BoardCoordinates newBoardSetup);

    // Getter for board positions
    BoardCoordinates getSetup();

private:

    // the 'map' of the board is here
    // represented by char array
    BoardCoordinates setup;

    BoardCoordinates initialSetup = NULL;
};

#endif
