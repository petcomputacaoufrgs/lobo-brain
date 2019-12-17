#include <iostream>
#include <vector>
#include "tree.hpp"
#include "tabuleiro.hpp"
#include "move.hpp"
#include "node.hpp"

using namespace std;

int main()
{
    vector<Tabuleiro> possibleBoards;
    // Tabuleiros para testes da função VDE
    Tabuleiro t1 ({ {'1','0','2'},
                    {'2','1','0'},
                    {'2','0','1'}   });
    
    Tabuleiro t2 ({ {'1','0','2'},
                    {'0','1','1'},
                    {'2','0','2'}   });

    Node* NodeTest1 = new Node(t1);
    Node* NodeTest2 = new Node(t2);

    generateChildren(Node* NodeTest1, '1');

    cout << NodeTest->root << endl;

    // a ideia desse laco é printar todos os tabuleiros possiveis a partir do NodeTest que seria o 'current_state'
    /*for (vector<Tabuleiro>::iterator it = possibleBoards.begin(); it != possibleBoards.end(); it++)
    {
        for (int i=0; i<3; i++){
            cout << endl;
            for(int j=0; j<3; j++)
                cout << possibleBoards[i][j] << " ";
        }
    }*/

    return 0;
}