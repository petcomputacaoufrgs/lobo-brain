#include <iostream>
#include "tree.hpp"

using namespace std;

Tree::Tree(vector<string> startingBoard)
{
    Node* rootNode = new Node(startingBoard);
    this->setRoot(rootNode);
}

void Tree::setRoot(Node* root)
{
    this->root = root;
}

void Tree::generateChildren(Node* node, char player)
{
    vector<vector<string>> possibleBoards;
    possibleBoards = generateBoards(node.board, player);

    for (vector<string>::iterator it = possibleBoards.begin(); it != possibleBoards.end(); it++)
    {
        Node* newChildren = new Node(it);
        node.addChildren(newChildren);
    }
}

int main()
{
    vector<string> start = {"101", "010", "101"};

    Tree* testree = new Tree(start);

    cout << testree->root << endl;

    return 0;
}
