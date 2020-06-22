#include <iostream>
#include "node.hpp"
#include "tabuleiro.hpp"

using namespace std;

Node::Node(Tabuleiro board)
{

    this->board = board;

    this->parent = NULL;
}

 void Node::addChildren(Node* newSon)
{
    //Node newSon = Node(board);
    newSon->parent = this;
    this->children.push_back(newSon);
}

void Node::free() {

    if(this->children.size() == 0) {
        delete this;
    } else {
        for(int i = 0; i < this->children.size(); i++) {
            this->children[i]->free();
        }
    }
}
