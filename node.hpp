#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
#include "tabuleiro.hpp"

using namespace std;

class Node
{
    public:
        int value;
        Node *parent;
        vector<Node> children;
        Tabuleiro board;

        Node(Tabuleiro board);

        void addChildren(Node* newChildren);
};
#endif

// OK?