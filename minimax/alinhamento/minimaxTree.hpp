#ifndef TREE_H
#define TREE_H

#include "minimaxNode.hpp"
#include "board.hpp"
#include "player.hpp"


class minimaxTree
{
    public:
        // The root at the first layer of the tree
        Node* root;

        // Class constructor
        minimaxTree(Board startingBoard);

        // Setter method for the tree root
        void setRoot(Node* root);

        // Returns all the possible boards
        // that can be transitioned from
        // a input board
        vector<Board> nextLayerBoards(Board originalBoard, Player player, bool jumpEnabled);


private:
        // Reproduce all possible board setups
        void generateChildren(Node* node, char player, bool jump);

        // Clear memory
        void free();

};

#endif
