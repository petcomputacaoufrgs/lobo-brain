#include <iostream>
#include "node.hpp"
#include "tabuleiro.hpp"

using namespace std;

// era vector<string>, agora eh char

// aparentemente aqui esta com algum erro 
// logico que nao esta  inicializando corretamente a classe Node
Node::Node(Tabuleiro board)
{
    /*cout << board.posicoes[2][2] << "criou Node" << endl;

    int nCol = sizeof(board) / sizeof(board.posicoes[0]);

    int nLin = sizeof(board.posicoes[0]) / sizeof(char);

    for (int i=0; i<nCol; i++)
    {
        for (int j=0; j<nLin; j++)
        {
            this->board.posicoes[i][j] = board.posicoes[i][j];
        }
    }*/

    this->board = board;

    this->parent = NULL;
}

 void Node::addChildren(Node* newSon)
{
    //Node newSon = Node(board);
    newSon->parent = this;
    this->children.push_back(*newSon);
}

