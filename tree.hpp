#ifndef tree
#define tree

#include "node.hpp"
#include "tabuleiro.hpp"

class Tree
{
    public:
        Node* root;

        Tree(Tabuleiro startingBoard);
        void setRoot(Node* root);
        void generateChildren(Node* node, char player);
};

#endif

//OK?