#include "MiniMaxAgent.hpp"

using namespace std;

MiniMaxAgent::MiniMaxAgent(LoBoGamesEngine* game, MiniMaxTree* gameTree)
{
    this->game = game;
    this->gameTree = game->gameTree;
}

MiniMaxAgent::MiniMaxAgent(LoBoGamesEngine* game, MiniMaxTree* gameTree, int maxDepth)
{
    this->game = game;
    this->gameTree = game->gameTree;
    this.maxDepth = maxDepth;
}