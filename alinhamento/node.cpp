#include <iostream>
#include "node.hpp"
#include "state.hpp"

using namespace std;

Node::Node(State state)
{

    this->state = state;

    this->parent = NULL;
}

 void Node::addChildren(Node* newSon)
{
    //Node newSon = Node(board);
    newSon->parent = this;
    this->children.push_back(newSon);
}
