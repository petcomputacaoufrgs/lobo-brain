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


// int main() {
//
//         // tab.posicoes na posicao inicial
//         // 0 = vazio
//         // 1/2 = jogador
//
//         Tabuleiro start ({{'2', '1', '2'},
//                           {'0', '0', '0'},
//                           {'1', '2', '1'}});
//
//         Node* choice;
//
//         // gera arvore do inicio
//         Tree* test_tree = new Tree(start);
//
//         // repeticoes inicias
//         int rep = 0;
//
//         // profundidade maxima
//         int max_depth = 3;
//
//         // Printa input
//         cout << "\n\n >> IN\n=============" << endl;
//         printa_tab(start);
//
//         // escolha de jogada
//         choice = decision(test_tree, test_tree->root, &rep, max_depth);
//
//         // Printa output
//         cout << "\n\n >> OUT (" << choice->value << ")\n=============" << endl;
//         printa_tab(choice->board);
//
//
//         return 0;
//
// }


  /* TESTE INTERATIVO */


// from = false, to = true
vector<int> receive_coord(bool to, int min, int max) {

          vector<int> coord = {-1, -1};

          // laço feio pq sem tempo
          while(coord[0] < min || coord[0] > max || coord[1] < min || coord[1] > max) {

            if(to)
                cout << "Enter the DESTINATION coord of the piece. (i.e. '0 0').\nmin = " << min << ", max = " << max << endl;
            else
                cout << "Enter the SOURCE coord of the piece. (i.e. '0 0').\nmin = " << min << ", max = " << max << endl;

            // Receber coordenadas
            cin >> coord[0];
            cin >> coord[1];

          }
          return coord;
}

int main() {

          // tab.posicoes na posicao inicial
          // 0 = vazio
          // 1/2 = jogador

          Tabuleiro start ({{'2', '1', '2'},
                            {'0', '0', '0'},
                            {'1', '2', '1'}});

          vector<int> from = {-1, -1};
          vector<int> to = {-1, -1};

          bool jogada_valida = false;

          // Inicializando tabuleiro
          Tabuleiro tab_atual = start;

          Node* choice;

          vector<vector<int>> possible_mov;

          // gera arvore do inicio
          Tree* game = new Tree(start);

          // repeticoes inicias
          int rep = 0;

          // profundidade maxima
          // NOTE: Quanto maior for esse valor, mais difícil será o jogo
          int max_depth = 6;

          system("clear");
          cout << "\n\nWelcome comrade! You're player 2, now go on and beat this piece of software!\n\n" << endl;

          printa_tab(tab_atual);

          while(evaluateTapatan(tab_atual, game->root->board, '1', '2', &rep) == 0){


            /* JOGADA PLAYER */


            cout << "\n\tYOUR TURN, MY LORD" << endl;

            // fica nesse loop até as entradas representarem uma jogada valida
            while(!jogada_valida) {

              // aguarda entradas e verifica se são válidas
              from = receive_coord(false, 0, 2);
              if(tab_atual.posicoes[from[0]] [from[1]] == '2') {
                  while(!jogada_valida) {
                      to = receive_coord(true, 0, 2);
                      if(tab_atual.posicoes[to[0]] [to[1]] == '0') {

                        int player_pos = 3*from[0] + from[1];
                        possible_mov = tapatanMoves(player_pos);

                        // Se a casa está no vetor possible_mov, então a jogada é válida
                        if(find(begin(possible_mov), end(possible_mov), to) != end(possible_mov)) {
                            tab_atual.posicoes[from[0]] [from[1]] = '0';
                            tab_atual.posicoes[to[0]] [to[1]] = '2';
                            jogada_valida = true;
                        }else{
                            cout << "\tTHAT PIECE CANT GO THERE MY CONFEDERATE\n\t  TRY A DIFFERENT ONE!" << endl;
                        }
                      }else{
                        cout << "\tTHERE's ALREADY A PIECE IN THERE!\n\t  TRY A DIFFERENT ONE!" << endl;
                      }
                  }
              }else{
                  cout << "\tYOU DONT HAVE A PIECE IN THERE!\n\t   TRY ANOTHER ONE!" << endl;
              }

            }

            // Preparação para próximas jogadas
            jogada_valida = false;
            game = new Tree(tab_atual);

            cout << "\n\tYou moved this:" << endl;
            printa_tab(tab_atual);


            /* JOGADA COMPUTADOR */

            // Chama decision
            choice = decision(game, game->root, &rep, max_depth);
            tab_atual = choice->board;

            cout << "\n\tYour binary opponent made this move:" << endl;
            printa_tab(tab_atual);

          }

          // Se saiu do loop, acabou o jogo

          cout << "GAME OVER\n" << endl;

          // Descobre quem ganhou
          if(evaluateTapatan(choice->board, game->root->board, '2', '1', &rep) > 0)
                cout << ":)" << endl;
          else
                cout << ":(" << endl;

          return 0;

  }
