#ifndef BOARD_H
#define BOARD_H

#include <vector>

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
    Board();

    // Initialization with
    // board specification
    Board(BoardCoordinates boardSetup);

    // Setter for updating board
    std::__cxx11::basic_string<char> updateSetup(BoardCoordinates newBoardSetup);

    // Getter for board positions
    BoardCoordinates getSetup();

private:

    // the 'map' of the board is here
    // represented by char array
    BoardCoordinates setup;

    BoardCoordinates initialSetup = NULL;
};

#endif
