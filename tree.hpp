#ifndef tree
#define tree

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
        void generateChildren(Node* node, char player);//gera filhos da raiz
};

#endif
