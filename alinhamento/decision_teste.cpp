#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "tabuleiro.hpp"
#include "tree.hpp"
#include "evaluations.hpp"
#include "decision.hpp"
#include "move.hpp"

using namespace std;


  /* TESTE INDIVIDUAL E NAO INTERATIVO */


int main() {

        // tab.posicoes na posicao inicial
        // 0 = vazio
        // 1/2 = jogador

        Tabuleiro start ({{'2', '0', '1'},
                          {'0', '2', '1'},
                          {'1', '2', '0'}});

        Node* choice;

        // gera arvore do inicio
        Tree* test_tree = new Tree(start);

        // repeticoes inicias
        int rep = 0;

        // profundidade maxima
        int max_depth = 3;

        // se pode pular peças
        bool jump = true;

        // Printa input
        cout << "\n\n\t >> IN <<\n\n\t#"
             << choice->board.getHash() << ":" << endl;
        printa_tab(start);

        // escolha de jogada
        choice = decision(test_tree, test_tree->root, jump, &rep, max_depth);

        // Printa output
        cout << "\n\n\t >> OUT (" << choice->value << ") <<\n\n\t#"
             << choice->board.getHash() << ":" << endl;
        printa_tab(choice->board);

}


  /* TESTE INTERATIVO */


// from = false, to = true
// vector<int> receive_coord(bool to, int min, int max) {
//
//           vector<int> coord = {-1, -1};
//
//           // laço feio pq sem tempo
//           while(coord[0] < min || coord[0] > max || coord[1] < min || coord[1] > max) {
//
//             if(to)
//                 cout << "Enter the DESTINATION coord of the piece. (i.e. '0 0').\nmin = " << min << ", max = " << max << endl;
//             else
//                 cout << "Enter the SOURCE coord of the piece. (i.e. '0 0').\nmin = " << min << ", max = " << max << endl;
//
//             // Receber coordenadas
//             cin >> coord[0];
//             cin >> coord[1];
//
//           }
//           return coord;
// }
//
// int main() {
//
//           // tab.posicoes na posicao inicial
//           // 0 = vazio
//           // 1/2 = jogador
//
//           Tabuleiro start ({{'2', '1', '2'},
//                             {'0', '0', '0'},
//                             {'1', '2', '1'}});
//
//           vector<int> from = {-1, -1};
//           vector<int> to = {-1, -1};
//
//           bool jogada_valida = false;
//
//           // Inicializando tabuleiro
//           Tabuleiro tab_atual = start;
//
//           vector<vector<char>> t_a = tab_atual.getPositions();
//
//           Node* choice;
//
//           vector<vector<int>> possible_mov;
//
//           // gera arvore do inicio
//           Tree* game = new Tree(start);
//
//           // repeticoes inicias
//           int rep = 0;
//
//           // profundidade maxima
//           // Quanto maior for esse valor, mais difícil será o jogo
//           int max_depth = 5;
//
//           system("clear");
//           cout << "\n\nBem vindo, você é o jogador 2.\n\n" << endl;
//
//           printa_tab(tab_atual);
//
//           while(tapatanEvaluation(tab_atual, game->root->board, '1', '2', &rep) == 0){
//
//
//             /* JOGADA PLAYER */
//
//
//             cout << "\n\tSUA RODADA" << endl;
//
//             // fica nesse loop até as entradas representarem uma jogada valida
//             while(!jogada_valida) {
//
//               // aguarda entradas e verifica se são válidas
//               from = receive_coord(false, 0, 2);
//               if(t_a[from[0]] [from[1]] == '2') {
//                   while(!jogada_valida) {
//                       to = receive_coord(true, 0, 2);
//                       if(t_a[to[0]] [to[1]] == '0') {
//
//                         int player_pos = 3*from[0] + from[1];
//                         possible_mov = tapatanMoves(player_pos);
//
//                         // Se a casa está no vetor possible_mov, então a jogada é válida
//                         if(find(begin(possible_mov), end(possible_mov), to) != end(possible_mov)) {
//                             t_a[from[0]] [from[1]] = '0';
//                             t_a[to[0]] [to[1]] = '2';
//                             jogada_valida = true;
//                         }else{
//                             cout << "\tMOVIMENTO INVÁLIDO\n\t\tTENTE OUTRO!" << endl;
//                         }
//                       }else{
//                         cout << "\tJÁ HÁ UMA PEÇA NESTA POSIÇÃO\n\t\tTENTE OUTRA!" << endl;
//                       }
//                   }
//               }else{
//                   cout << "\tESTA POSIÇÃO NÃO CONTÉM UMA PEÇA SUA\n\t\tTENTE OUTRA!" << endl;
//               }
//
//             }
//
//             // Preparação para próximas jogadas
//             jogada_valida = false;
//             game = new Tree(tab_atual);
//
//             cout << "\n\tSua jogada:" << endl;
//             printa_tab(tab_atual);
//
//
//             /* JOGADA COMPUTADOR */
//
//             // Chama decision
//             choice = decision(game, game->root, &rep, max_depth);
//             tab_atual = choice->board;
//
//             cout << "\n\tJogada da máquina:" << endl;
//             printa_tab(tab_atual);
//
//           }
//
//           // Se saiu do loop, acabou o jogo
//
//           cout << "GAME OVER\n" << endl;
//
//           // Descobre quem ganhou
//           if(tapatanEvaluation(choice->board, game->root->board, '2', '1', &rep) > 0)
//                 cout << "Você ganhou" << endl;
//           else
//                 cout << "Você perdeu" << endl;
//
//           return 0;
//
//   }
