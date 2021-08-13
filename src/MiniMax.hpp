#ifndef LOBO_BRAIN_MINIMAX_HPP
#define LOBO_BRAIN_MINIMAX_HPP

#include "./MiniMax/minimaxNode.hpp"
#include "./MiniMax/minimaxTree.hpp"
#include "./LoBoBrain.hpp"

class MiniMax : public LoBoGamesEngine{

public:
    MiniMax(Board startingBoard);
    MiniMax(Board startingBoard, int maxDepth);

    int executeNewLayer(bool isMax, int currentDepth);
    Board playAs(Player player);

private:
    // Initializations
    MiniMaxTree* tree;
    MiniMaxNode *currentSetup;
    int maxDepth = 3;
    int alpha = -10000;
    int beta = 10000;
};


#endif //LOBO_BRAIN_MINIMAX_HPP
