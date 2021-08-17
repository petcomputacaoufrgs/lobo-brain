#ifndef LOBO_BRAIN_MINIMAX_HPP
#define LOBO_BRAIN_MINIMAX_HPP

#include "../MiniMax/minimaxNode.hpp"
#include "../MiniMax/minimaxTree.hpp"
#include "../LoBoBrain.hpp"

class MiniMaxAgent{

public:
    /*
     * Initializations
     */
    MiniMaxAgent(LoBoGamesEngine* game, MiniMaxTree* gameTree);
    MiniMaxAgent(LoBoGamesEngine* game, MiniMaxTree* gameTree, int maxDepth);



protected:
    // Initializations
    LoBoGamesEngine* game;
    MiniMaxTree* gameTree;
    Board currentSetup;
    int maxDepth = 3;
    int alpha = -10000;
    int beta = 10000;
};


#endif //LOBO_BRAIN_MINIMAX_HPP
