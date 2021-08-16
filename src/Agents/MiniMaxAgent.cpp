#include "MiniMaxAgent.hpp"

using namespace std;

MiniMaxAgent::MiniMaxAgent(LoBoGamesEngine* game)
{
    this->gameTree = game->gameTree;
    this->game = game;
}

MiniMaxAgent::MiniMaxAgent(LoBoGamesEngine* game, int maxDepth)
{
    this->gameTree = game->gameTree;
    this->game = game;
    this.maxDepth = maxDepth;
}