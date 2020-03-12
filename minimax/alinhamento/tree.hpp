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

<<<<<<< HEAD
        Tree();
=======
        Tree(); // construtor vazio
>>>>>>> 87a75b766080944872e976bca697e3f73e5f44ab
        Tree(State startingState);//construtor
        void setRoot(Node* root);//metodo setter para a raiz
        vector<State> generateStates(State state, char player, bool jump);
        void generateChildren(Node* node, char player, bool jump);//gera filhos da raiz

};

#endif
