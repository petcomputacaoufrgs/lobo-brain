#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
#include "state.hpp"

using namespace std;

class Node
{
    public:
        int value;
        Node *parent;
        vector<Node*> children;
        State state;

        Node(State state);

        void addChildren(Node* newChildren);
};
#endif

// OK?
