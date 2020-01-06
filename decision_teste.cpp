#include <vector>
#include <string>
#include <iostream>
#include "tabuleiro.hpp"
#include "tree.hpp"
#include "VDE.hpp"
#include "decision.hpp"

using namespace std;

void printvet(vector <int> const &vet, int j) {
   cout << "--> elementos do vetor [" << j << "]: ";
   
   for(int j=0; j < vet.size(); j++)
      cout << vet.at(j) << ' ';

    cout << endl;
}

int main() {
    
        // tab.posicoes na posicao inicial
        // 0 = vazio
        // 1/2 = jogador
    
        Tabuleiro start ({	{'1', '2', '0'},
                            {'0', '1', '0'},
                            {'1', '2', '2'}		});

        Node* choice;
    
        // gera arvore do inicio
        Tree* test_tree = new Tree(start);
        // repeticoes inicias
        int rep = 0;

        // printa_tab(start);


        // escolha de jogada
        choice = decision(test_tree, test_tree->root, &rep);

        //printa o tabuleiro que retorna a melhor jogada
        for (int i=0; i<3; i++){
            //cout << endl;
            for(int j=0; j<3; j++)
                cout << choice->board.posicoes[i][j] << " ";
            
            cout << endl;
        }

        return 0;
    
}
