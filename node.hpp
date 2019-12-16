#ifndef node
#define node

#include <vector>
#include <string>

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