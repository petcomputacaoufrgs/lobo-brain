#include <iostream>
#include <utility>
#include "minimaxNode.hpp"

using namespace std;

MiniMaxNode::MiniMaxNode(Board nodeBoard)
{
    this->nodeBoard = move(nodeBoard);
    this->parent = NULL;
    this->score = NULL;
}

 void MiniMaxNode::buildNextGeneration(MiniMaxNode* newSon)
{
    newSon->parent = this;
    this->nextGeneration.push_back(newSon);
}

void MiniMaxNode::free() {

    if(this->nextGeneration.empty()) {

        // RECURSION BASE

        // if this node has no children,
        // then we must delete it
        delete this;
    } else {

        // RECURSION STEP

        // if it has children, iterate over
        // them, AND THEN delete this node
        for(auto & i : this->nextGeneration) {
            i->free();
        }
        delete this;
    }
}
