#include "LoBoBrain.hpp"

#include "player.hpp"
#include "board.hpp"
#include <vector>

LoBoGamesEngine::LoBoGamesEngine(vector<Player*> players, Board* board)
{
    this->players = players;
    this->currentPlayer = players[0];

    this->board = board;
}

LoBoGamesEngine::LoBoGamesEngine(vector<Player*> players)
{
    this->players = players;
    this->currentPlayer = players[0];

    this->board = NULL;
}
