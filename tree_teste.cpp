#include <iostream>
#include <vector>
#include "tree.hpp"
#include "tabuleiro.hpp"
#include "move.hpp"
#include "node.hpp"

using namespace std;

int main()
{
    Tabuleiro tini ({   {'2', '1', '2'},
                        {'0', '0', '0'},
                        {'1', '2', '1'}     });

    Tree* treeTest = new Tree(tini);

    treeTest->generateChildren(treeTest->root, '1');


    // a ideia desse laco é printar todos os tabuleiros possiveis a partir do NodeTest que seria o 'current_state'
    for (vector<Node>::iterator it = treeTest->root->children.begin(); it != treeTest->root->children.end(); it++)
    {
        for (int i=0; i<3; i++){
            cout << endl;
            for(int j=0; j<3; j++)
                cout << it->board.posicoes[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}