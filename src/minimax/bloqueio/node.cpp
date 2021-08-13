#include <iostream>
#include "node.hpp"
#include "tabuleiro.hpp"

using namespace std;

// era vector<string>, agora eh char

// aparentemente aqui esta com algum erro
// logico que nao esta  inicializando corretamente a classe Node
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
