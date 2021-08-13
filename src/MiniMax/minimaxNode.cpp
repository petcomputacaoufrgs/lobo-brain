#include <iostream>
#include "minimaxNode.hpp"

using namespace std;

MiniMaxNode::MiniMaxNode(Board nodeBoard)
{
    this->nodeBoard = nodeBoard;

    this->parent = NULL;
}

 void MiniMaxNode::buildNextLayer(MiniMaxNode* newSon)
{
    newSon->parent = this;
    this->nextLayer.push_back(newSon);
}

void MiniMaxNode::free() {

    if(this->nextLayer.size() == 0) {

        // RECURSION BASE

        // if this node has no children,
        // then we must delete it
        delete this;
    } else {

        // RECURSION STEP

        // if it has children, iterate over
        // them, AND THEN delete this node
        for(int i = 0; i < this->nextLayer.size(); i++) {
            this->nextLayer[i]->free();
        }
        delete this;
    }
}
