#include "board.hpp"

using namespace std;

Board::Board(BoardCoordinates boardSetup)
{
    this->updateSetup(boardSetup);
}

Board::Board()
{

}

void Board::updateSetup(BoardCoordinates newBoardSetup){
    this->setup = newBoardSetup
}

BoardCoordinates Board::getSetup(){
    return this->setup;
}