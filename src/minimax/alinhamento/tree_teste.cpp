#include <iostream>
#include <vector>
#include "minimaxTree.hpp"
#include "board.hpp"
#include "move.hpp"
#include "minimaxNode.hpp"


// aparentemente as funcoes relacionadas a tree.cpp estao funcionando corretamente
using namespace std;


void printChildren(Node* root)
{
    if(root != NULL){
        for (int i=0; i<3; i++){
            cout << endl;
            for(int j=0; j<3; j++)
                cout << root->board.posicoes[i][j] << " ";
        }
        cout << endl;
        for (vector<Node>::iterator it = root->children.begin(); it != root->children.end(); it++)
        {
            printChildren(&*it);
        }
    }
}

int main()
{
    Tabuleiro tini ({ {'2', '1', '0'},
                      {'0', '2', '0'},
                      {'2', '1', '1'}});

    Tree* treeTest = new Tree(tini);
    Tree* treeTest1 = new Tree(tini);
    treeTest->generateChildren(treeTest->root, '1');

    // a ideia desse laco é printar todos os tabuleiros possiveis a partir do NodeTest que seria o 'current_state'
    printChildren(treeTest->root);

    treeTest1->generateChildren(treeTest1->root, '2');
    // a ideia desse laco é printar todos os tabuleiros possiveis a partir do NodeTest que seria o 'current_state'
    printChildren(treeTest1->root);

    return 0;
}
