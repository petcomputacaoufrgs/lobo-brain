#ifndef LOBO_BRAIN_H
#define LOBO_BRAIN_H

#include <vector>

#include "board.hpp"
#include "player.hpp"
#include "rules.hpp"

#include "minimaxNode.hpp"
#include "minimaxTree.hpp"

class LoBoGamesEngine {

public:
    // Class constructor with board specified
    LoBoGamesEngine(vector<Player> *players, Board board);
    // Class constructor without board specified
    LoBoGamesEngine(vector<Player> *players);

//    LoBoGamesEngine(vector<TapatanPlayer> players, bool jumpEnable);

    Board board;
    vector<Player*> players;
    Player *currentPlayer;


};


#endif //LOBO_BRAIN_H
