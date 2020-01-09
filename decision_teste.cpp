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

        Tabuleiro start ({{'2', '1', '0'},
                          {'0', '2', '0'},
                          {'2', '1', '1'}});

        Node* choice;

        // gera arvore do inicio
        Tree* test_tree = new Tree(start);

        // repeticoes inicias
        int rep = 0;

        // profundidade maxima
        int max_depth = 2;

        // Printa input
        cout << "\n\n >> IN\n=============" << endl;
        printa_tab(start);

        // escolha de jogada
        choice = decision(test_tree, test_tree->root, &rep, max_depth);

        // Printa output
        cout << "\n\n >> OUT (" << choice->value << ")\n=============" << endl;
        printa_tab(choice->board);

        return 0;

}
