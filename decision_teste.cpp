#include <vector>
#include <string>
#include <iostream>
#include "tabuleiro.hpp"
#include "tree.hpp"
#include "VDE.hpp"
#include "decision.hpp"

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

          // gera arvore do inicio
          Tree* game = new Tree(start);

          // repeticoes inicias
          int rep = 0;

          // profundidade maxima
          // NOTE: Quanto maior for esse valor, mais difícil será o jogo
          int max_depth = 5;

          system("clear");
          cout << "\n\nWelcome comrade! You're player 2, now go on and beat this mafka!\n\n" << endl;

          printa_tab(tab_atual);

          do {


            /* JOGADA PLAYER */


            cout << "\n\tYOUR TURN, MY LORD" << endl;

            // fica nesse loop até as entradas representarem uma jogada valida
            while(!jogada_valida) {

              // aguarda Entradas e verifica se são válidas
              from = receive_coord(false, 0, 2);
              if(tab_atual.posicoes[from[0]] [from[1]] == '2') {
                  while(!jogada_valida) {
                      to = receive_coord(true, 0, 2);
                      if(tab_atual.posicoes[to[0]] [to[1]] == '0') {
                        tab_atual.posicoes[from[0]] [from[1]] = '0';
                        tab_atual.posicoes[to[0]] [to[1]] = '2';
                        jogada_valida = true;
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

            cout << "\n\tIS THAT UR MOVE, SON?" << endl;
            printa_tab(tab_atual);


            /* JOGADA COMPUTADOR */

            // Chama decision
            choice = decision(game, game->root, &rep, max_depth);
            tab_atual = choice->board;

            cout << "\n\tMAFKA MOVE THAT SHIT UP" << endl;
            printa_tab(tab_atual);

          }while(funcaoVDE(choice->board, game->root->board, '1', '2', &rep) == 0);

          // Se saiu do loop, acabou o jogo

          cout << "END GAME\n" << endl;

          // Descobre quem ganhou
          if(funcaoVDE(choice->board, game->root->board, '2', '1', &rep) > 0)
                cout << "MY MAN! YOU WON! CONGRATS!" << endl;
          else
                cout << "NOT ALWAYS U HAVE WHAT U WANT, b0y" << endl;

          return 0;

  }
