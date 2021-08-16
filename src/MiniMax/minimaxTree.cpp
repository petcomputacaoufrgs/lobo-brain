#include <iostream>
#include <utility>
#include <vector>
#include "minimaxTree.hpp"
#include "minimaxNode.hpp"
#include "../LoBoBrain.hpp"

using namespace std;


MiniMaxTree::MiniMaxTree(Board nodeBoard, Board startingBoard) : MiniMaxNode(move(nodeBoard)) {

    // Dynamic alloc
    auto* rootNode = new MiniMaxNode(move(startingBoard));

    this->setRoot(rootNode);
}


void MiniMaxTree::setRoot(MiniMaxNode* root)
{
    this->root = root;
}


void MiniMaxTree::buildNextGeneration(MiniMaxNode* currentNode, const vector<Player>& players)
{
    MiniMaxNode* newChild;
    Board board;

    // Insert new nodes and set parent
    for (auto & possibleBoard : possibleBoards)
    {
        newChild = new MiniMaxNode(possibleBoard);
        this->root->buildNextLayer(newChild);
    }
}

void MiniMaxTree::free() {
    this->root->free();
}

vector<Board> MiniMaxTree::nextGenerationBoards(Board originalBoard, Player player) {

    return vector<Board>();
}
