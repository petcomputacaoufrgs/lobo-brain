#ifndef tree
#define tree

#include "node.hpp"

class Tree
{
    public:
        Node* root;

        Tree(std::vector<std::string> startingBoard);
        void setRoot(Node* root);
		std::vector<std::vector<std::string>> generateBoards(std::vector<std::string> board, char player); 
        void generateChildren(Node* node, char player);
};

#endif
