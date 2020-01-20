#include <iostream>
#include <vector>
#include "tree.hpp"
#include "tabuleiro.hpp"
#include "move.hpp"
#include "node.hpp"


// aparentemente as funcoes relacionadas a tree.cpp estao funcionando corretamente
using namespace std;


void printChildren(Node* root)
{
    if(root != NULL){

        cout << "\n\n~~~~ ROOT ~~~~\n\n" << endl;

        Vertex* aux = root->board.firstPos;

        root->board.print();

        cout << "\n\n~~~~ CHILDREN ~~~~\n\n" << endl;
        
        for (vector<Node*>::iterator it = root->children.begin(); it != root->children.end(); it++)
        {
            printChildren(*it);
        }
    }
}

int main()
{
    Tabuleiro tini = pongHauKiBoard();
    tini.pongHauKiInitialPositions();

    Tree* treeTest = new Tree(tini);
    Tree* treeTest1 = new Tree(tini);

    treeTest->generateChildren(treeTest->root, '1', '2');

    // a ideia desse laco é printar todos os tabuleiros possiveis a partir do NodeTest que seria o 'current_state'
    printChildren(treeTest->root);

    treeTest1->generateChildren(treeTest1->root, '2', '1');
    // a ideia desse laco é printar todos os tabuleiros possiveis a partir do NodeTest que seria o 'current_state'
    printChildren(treeTest1->root);

    return 0;
}
