#ifndef MINIMAX_NODE_H
#define MINIMAX_NODE_H

#include <vector>
#include "../LoBoBrain.hpp"
#include "minimaxTree.hpp"

using namespace std;

class MiniMaxNode
{
private:
    MiniMaxNode *parent;
    vector<MiniMaxNode*> nextGeneration;
    Board nodeBoard;
    int score;

public:
    MiniMaxNode(Board nodeBoard);


    void buildNextGeneration(MiniMaxNode* newChildren);
    void free();
};
#endif