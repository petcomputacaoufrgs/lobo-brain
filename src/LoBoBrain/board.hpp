#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
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
    Board(const LoBoGamesEngine& gameEngine);

    // Initialization with
    // board specification
    explicit Board(const LoBoGamesEngine& game, BoardCoordinates boardSetup);

    LoBoGamesEngine gameEngine;

    virtual // Setter for updating board
    string updateSetup(BoardCoordinates newBoardSetup) override;

    virtual // Getter for board positions
    BoardCoordinates getSetup();

private:

    BoardCoordinates initialSetup = vector<vector<int>>;
protected:
// the 'map' of the board is here
// represented by char array
BoardCoordinates setup;
};

#endif
