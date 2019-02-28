#ifndef node
#define node

#include <vector>
#include <string>

class Node
{
    public:
        int value;
        Node *parent;
        std::vector<Node> children;
        std:: vector<std::string> board;

        Node(std::vector<std::string> board);

        void addChildren(Node* newChildren);
};

#endif
