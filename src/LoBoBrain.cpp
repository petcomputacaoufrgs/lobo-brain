#include "LoBoBrain.hpp"

#include <vector>

LoBoGamesEngine::LoBoGamesEngine(vector<Player*> players, Board board)
{
    this.players = players;
    this.currentPlayer = players[0];

    this.board = board;

    this.game = new MiniMaxNode(board);
}

LoBoGamesEngine::LoBoGamesEngine(vector<Player*> players)
{
    this.players = players;
    this.currentPlayer = players[0];

    this.board = NULL;

    this.game = NULL;
}