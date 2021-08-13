#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
#include "board.hpp"

using namespace std;

class Node
{
private:
    int value;
    Node *parent;
    vector<Node*> children;
    Board nodeBoard;

public:
    Node(Board nodeBoard);

    void buildNextLayer(Node* newChildren);
    void free();
};
#endif