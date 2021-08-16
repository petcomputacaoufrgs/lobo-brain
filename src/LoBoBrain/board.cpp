#include "board.hpp"

#include <utility>

using namespace std;

Board::Board(LoBoGamesEngine* gameEngine, BoardCoordinates boardSetup)
{
    this->gameEngine = gameEngine;
    this->updateSetup(move(boardSetup));
}

Board::Board(LoBoGamesEngine* gameEngine)
{
    this->gameEngine = gameEngine;
};

void Board::updateSetup(BoardCoordinates newBoardSetup){
    this->setup = move(newBoardSetup);
}

BoardCoordinates Board::getSetup(){
    return this->setup;
}