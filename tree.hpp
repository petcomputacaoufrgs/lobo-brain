#ifndef tree
#define tree

#include "node.hpp"

class Tree
{
    public:
        Node* root;

        Tree(std::vector<std::string> startingBoard);
        void setRoot(Node* root);
};

#endif
