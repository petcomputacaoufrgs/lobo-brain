#include "board.hpp"

#include <utility>

using namespace std;

Board::Board(const LoBoGamesEngine& gameEngine)
{
    this->gameEngine = gameEngine;
};

Board::Board(const LoBoGamesEngine& gameEngine, BoardCoordinates boardSetup)
{
    this->gameEngine = gameEngine;
    this->updateSetup(move(boardSetup));
}

string Board::updateSetup(BoardCoordinates newBoardSetup){
    this->setup = move(newBoardSetup);
}

BoardCoordinates Board::getSetup(){
    return this->setup;
}