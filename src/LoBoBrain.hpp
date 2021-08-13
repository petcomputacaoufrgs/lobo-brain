#ifndef LOBO_BRAIN_H
#define LOBO_BRAIN_H

#include <vector>

#include "./LoBoBrain/board.hpp"
#include "./LoBoBrain/player.hpp"
#include "./MiniMax/minimaxTree.hpp"

class LoBoGamesEngine {

public:
    // Class constructor with board specified
    LoBoGamesEngine(vector<Player> players, Board board);
    // Class constructor without board specified
    LoBoGamesEngine(vector<Player> players);

//    LoBoGamesEngine(vector<TapatanPlayer> players, bool jumpEnable);

    MiniMaxTree game;
    Board board;
    vector<Player> players;
    Player currentPlayer;

    MiniMaxNode* execute();


};


#endif //LOBO_BRAIN_H
