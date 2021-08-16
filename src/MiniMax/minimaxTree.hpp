#ifndef MINIMAX_TREE_H
#define MINIMAX_TREE_H

#include "./minimaxNode.hpp"
#include "../LoBoBrain.hpp"

class MiniMaxTree : MiniMaxNode
{
public:
    // The root at the first layer of the tree
    MiniMaxNode* root;

    // Class constructor
    MiniMaxTree(Board nodeBoard, Board startingBoard);

    // Setter method for the tree root
    void setRoot(MiniMaxNode* root);

    // Returns all the possible boards
    // that can be transitioned from
    // a input board
    vector<Board> nextGenerationBoards(Board originalBoard, Player player);


    // Reproduce all possible board setups
    static void buildNextGeneration(MiniMaxNode* currentNode, const vector<Player>& players);

private:

    // Clear memory
    void free();

    void buildNextLayer(const vector<Board>& possibleBoards);
};

#endif
