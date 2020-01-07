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

        Tabuleiro start ({{'2', '0', '1'},
                          {'0', '1', '2'},
                          {'2', '1', '0'}});

        Node* choice;

        // gera arvore do inicio
        Tree* test_tree = new Tree(start);
        // repeticoes inicias
        int rep = 0;

        printa_tab(start);
        cout << "\tINICIO DO ALGORITMO" << endl;


        // escolha de jogada
        choice = decision(test_tree, test_tree->root, &rep);

        //printa o tabuleiro que retorna a melhor jogada
        printa_tab(choice->board);

        return 0;

}
