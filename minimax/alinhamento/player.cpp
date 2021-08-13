#include "player.hpp"
#include <string>

using namespace std;

Player::Player(char symbol, string name)
{
    this->symbol = symbol;
    this->name = name;
}

Player::Player()
{
    this->symbol = this->defaultSymbol;
    this->name = this->defaultName;
}