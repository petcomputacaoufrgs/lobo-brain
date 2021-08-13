#include <iostream>
#include "minimaxNode.hpp"
#include "board.hpp"

using namespace std;

Node::Node(Board nodeBoard)
{

    this->nodeBoard = nodeBoard;

    this->parent = NULL;
}

 void Node::buildNextLayer(Node* newSon)
{
    //Node newSon = Node(board);
    newSon->parent = this;
    this->children.push_back(newSon);
}

void Node::free() {

    if(this->children.size() == 0) {

        // RECURSION BASE

        // if this node has no children,
        // then we must delete it
        delete this;
    } else {

        // RECURSION STEP

        // if it has children, iterate over
        // them, AND THEN delete this node
        for(int i = 0; i < this->children.size(); i++) {
            this->children[i]->free();
        }
        delete this;
    }
}
