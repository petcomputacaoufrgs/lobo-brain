#ifndef TREE_H
#define TREE_H

#include "minimaxNode.hpp"
#include "../LoBoBrain.hpp"

class MiniMaxTree
{
    public:
        // The root at the first layer of the tree
        MiniMaxNode* root;

        // Class constructor
        MiniMaxTree(Board startingBoard);

        // Setter method for the tree root
        void setRoot(MiniMaxNode* root);

        // Returns all the possible boards
        // that can be transitioned from
        // a input board
        vector<Board> nextLayerBoards(Board originalBoard, Player player);


private:
        // Reproduce all possible board setups
        void buildNextLayer(MiniMaxNode* currentNode, vector<Player> players, bool jump);

        // Clear memory
        void free();

};

#endif
