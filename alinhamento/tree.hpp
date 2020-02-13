#ifndef TREE_H
#define TREE_H

#include "node.hpp"
#include "state.hpp"

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

        Tree(); // construtor vazio
        Tree(State startingState);//construtor
        void setRoot(Node* root);//metodo setter para a raiz
        vector<State> generateStates(State state, char player, bool jump);
        void generateChildren(Node* node, char player, bool jump);//gera filhos da raiz

};

#endif
