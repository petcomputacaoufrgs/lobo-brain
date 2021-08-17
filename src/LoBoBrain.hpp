#ifndef LOBO_BRAIN_H
#define LOBO_BRAIN_H

#include <vector>

#include "./LoBoBrain/board.hpp"
#include "./LoBoBrain/player.hpp"
#include "./MiniMax/minimaxTree.hpp"

class LoBoGamesEngine {

public:

    // Class constructor without board specified
    LoBoGamesEngine(vector<Player> players);
    // Class constructor with board specified
    LoBoGamesEngine(vector<Player> players, Board board);

    MiniMaxTree* gameTree;
    Board board;
    vector<Player> players;
    Player currentPlayer;


};


#endif //LOBO_BRAIN_H
