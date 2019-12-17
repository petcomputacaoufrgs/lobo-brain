#include <iostream>
#include "node.hpp"
#include "tabuleiro.hpp"

using namespace std;

// era vector<string>, agora eh char
Node::Node(Tabuleiro board)
{
    // cout << board[2][2] << "criou Node" << endl;

    /*int nCol = sizeof(board) / sizeof(board[0]);

    int nLin = sizeof(board[0]) / sizeof(char);

    for (int i=0; i<nCol; i++)
    {
        for (int j=0; j<nLin; j++)
        {
            this->board[i][j] = board[i][j];
        }
    }*/

    this->board = board;

    this->parent = NULL;
}

 void Node::addChildren(Node* newSon)
{
    cout << "adiciona filho" << endl;

    //Node newSon = Node(board);
    newSon->parent = this;
    this->children.push_back(*newSon);
}

