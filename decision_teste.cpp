#include <vector>
#include <string>
#include <iostream>
#include "tabuleiro.hpp"
#include "tree.hpp"
#include "VDE.hpp"
#include "decision.hpp"

using namespace std;

int main() {
    
        // tab.posicoes na posicao inicial
        // 0 = vazio
        // 1/2 = jogador
    
        Tabuleiro start ({	{'1', '2', '1'},
                                {'0', '0', '0'},
                                {'2', '1', '2'}		});

        Node* choice;
    
        // gera arvore do inicio
        Tree* test_tree = new Tree(start);
        // repeticoes inicias
        int rep = 0;
        // escolha de jogada
        choice = decision(test_tree, test_tree->root, &rep);

        //printa o tabuleiro que retorna a melhor jogada
        for (int i=0; i<3; i++){
            //cout << endl;
            for(int j=0; j<3; j++)
                cout << choice->board.posicoes[i][j] << " ";
        }

        return 0;
    
}
