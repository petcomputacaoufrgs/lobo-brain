#include <iostream>
#include <vector>
#include "./minimaxNode.hpp"
#include "../LoBoBrain.hpp"

using namespace std;


MiniMaxTree::MiniMaxTree(Board startingBoard)
{

    // Dynamic alloc
    MiniMaxNode* rootNode = new MiniMaxNode(startingBoard);

    this->setRoot(rootNode);
}


void MiniMaxTree::setRoot(MiniMaxNode* root)
{
    this.root = root;
}


void MiniMaxTree::buildNextLayer(vector<Board> possibleBoards)
{
    MiniMaxNode* newChild;
    Board board;

    // Insert new nodes and set parent
    for (vector<Board>::iterator it = possibleBoards.begin(); it != possibleBoards.end(); it++)
    {
        newChild = new MiniMaxNode(*it);
        this.addChildren(newChild);
    }
}

void MiniMaxTree::free() {
    this.root->free();
}