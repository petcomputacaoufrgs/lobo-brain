#ifndef TREE_H
#define TREE_H

#include "node.hpp"
#include "tabuleiro.hpp"

/*********************************************************
*   Classe da arvore de tabuleiros:                      *
*        - Armazena todos os possiveis tabuleiros        *
*       de jogadas.                                      *
*                                                        *
*       - Uso:                                           *
*            - Tabuleiro exemplo (vector<vector<char>>)  *
**********************************************************/
class Tree
{
    public:
        Node* root;

        Tree(Tabuleiro startingBoard);//construtor
        void setRoot(Node* root);//metodo setter para a raiz
        vector<Tabuleiro> generateBoards(Tabuleiro board, char player);
        void generateChildren(Node* node, char player);//gera filhos da raiz
        Tabuleiro setCurrentBoard(char player, char enemy, int from, int to, vector<int> playerPos, vector<int> enemyPos);

};

#endif
