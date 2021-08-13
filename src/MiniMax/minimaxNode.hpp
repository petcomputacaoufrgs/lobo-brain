#ifndef NODE_H
#define NODE_H

#include <vector>
#include "../LoBoBrain.hpp"

using namespace std;

class MiniMaxNode
{
private:
    int value;

    MiniMaxNode *parent;
    vector<MiniMaxNode*> nextLayer;
    Board nodeBoard;

public:
    MiniMaxNode(Board nodeBoard);

    void buildNextLayer(MiniMaxNode* newChildren);
    void free();
};
#endif