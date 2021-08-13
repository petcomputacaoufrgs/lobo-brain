#ifndef MOVE_H
#define MOVE_H

#include <vector>
#include <string>
#include "board.hpp"

using namespace std;

vector<vector<int>> tapatanMoves(int player_pos);
vector<vector<int>> tapatanJumpMoves(int player_pos, Tabuleiro board);

#endif
