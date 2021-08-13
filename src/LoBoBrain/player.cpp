export module LoboBrain.Player;

#include "player.hpp"
#include <string>

using namespace std;

Player::Player(char symbol, string name)
{
    this.symbol = symbol;
    this.name = name;
    this.score = 0;
}

Player::Player()
{
    this.symbol = this.defaultSymbol;
    this.name = this.defaultName;
    this.score = 0;
}