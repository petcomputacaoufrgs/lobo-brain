#include "player.hpp"
#include <string>
#include <utility>

using namespace std;

Player::Player(LoBoGamesEngine* gameEngine, char symbol, string name)
{
    this->gameEngine = gameEngine;
    this->symbol = symbol;
    this->name = move(name);
}

Player::Player(LoBoGamesEngine* gameEngine)
{
    this->gameEngine = gameEngine;
    this->symbol = this->defaultSymbol;
    this->name = this->defaultName;
}
