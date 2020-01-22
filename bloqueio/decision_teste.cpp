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
//         Tabuleiro start = pongHauKiBoard();
//         start.pongHauKiInitialPositions();
//         start.firstPos->player = '2';
//         start.firstPos->next->player = '2';
//         start.firstPos->next->next->player = '1';
//         start.firstPos->next->next->next->player = '0';
//         start.firstPos->next->next->next->next->player = '1';
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
//         start.print();
//
//         // escolha de jogada
//         choice = decision(test_tree, test_tree->root, &rep, max_depth);
//
//         // Printa output
//         cout << "\n\n >> OUT (" << choice->value << ")\n=============" << endl;
//         choice->board.print();
//
//         cout << endl << endl;
//
//         return 0;
//
// }


  /* TESTE INTERATIVO */


// from = false, to = true
int receive_coord(bool to, int min, int max) {

          int coord = -1;

          // laço feio pq sem tempo
          while(coord < min || coord > max) {

            if(to)
                cout << "Enter the DESTINATION coord of the piece. (i.e. '0').\nmin = " << min << ", max = " << max << endl;
            else
                cout << "Enter the SOURCE coord of the piece. (i.e. '0').\nmin = " << min << ", max = " << max << endl;

            // Receber coordenadas
            cin >> coord;

          }
          return coord;
}

int main() {

          // tab.posicoes na posicao inicial
          // 0 = vazio
          // 1/2 = jogador

          Tabuleiro start = pongHauKiBoard();
          start.pongHauKiInitialPositions();

          int from = -1;
          int to = -1;

          bool jogada_valida = false;

          // Inicializando tabuleiro
          Tabuleiro tab_atual = start;

          Vertex* aux = tab_atual.firstPos;

          Node* choice;

          vector<int> possible_mov;
          vector<int> possible_mov_aux;

          // gera arvore do inicio
          Tree* game = new Tree(start);

          // repeticoes inicias
          int rep = 0;

          // profundidade maxima
          // Quanto maior for esse valor, mais difícil será o jogo
          int max_depth = 1;

          system("clear");
          cout << "\n\nBem vindo, você é o jogador 2.\n\n" << endl;

          tab_atual.print();

          while(pongHauKiEvaluation(tab_atual, '1', '2', &rep) == 0){


            /* JOGADA PLAYER */


            cout << "\n\tSUA RODADA" << endl;

            // fica nesse loop até as entradas representarem uma jogada valida
            while(!jogada_valida) {

              // aguarda entradas e verifica se são válidas
              from = receive_coord(false, 0, 4);
              if(tab_atual.search(from)->player == '2') {
                  while(!jogada_valida) {
                      to = receive_coord(true, 0, 4);
                      if(tab_atual.search(to)->player == '0') {

                        possible_mov = {};
                        possible_mov_aux = {};
                        aux = tab_atual.firstPos;

                        while(aux != NULL) {
                          if(aux->player == '2') {
                              possible_mov_aux = searchFreeNeighbours(aux);
                          }
                          possible_mov.insert(  possible_mov.end(),
                                                possible_mov_aux.begin(),
                                                possible_mov_aux.end()  );
                          aux = aux->next;
                        }

                        // Se a casa está no vetor possible_mov, então a jogada é válida
                        if(find(begin(possible_mov), end(possible_mov), to) != end(possible_mov)) {
                            tab_atual.search(from)->player = '0';
                            tab_atual.search(to)->player = '2';
                            jogada_valida = true;
                        }else{
                            cout << "\tMOVIMENTO INVÁLIDO\n\t\tTENTE OUTRO!" << endl;
                        }
                      }else{
                        cout << "\tJÁ HÁ UMA PEÇA NESTA POSIÇÃO\n\t\tTENTE OUTRA!" << endl;
                      }
                  }
              }else{
                  cout << "\tESTA POSIÇÃO NÃO CONTÉM UMA PEÇA SUA\n\t\tTENTE OUTRA!" << endl;
              }

            }

            // Preparação para próximas jogadas
            jogada_valida = false;
            game = new Tree(tab_atual);

            cout << "\n\tSua jogada:" << endl;
            tab_atual.print();


            /* JOGADA COMPUTADOR */

            // Chama decision
            choice = decision(game, game->root, &rep, max_depth);
            tab_atual = choice->board;

            cout << "\n\tJogada da máquina:" << endl;
            tab_atual.print();

          }

          // Se saiu do loop, acabou o jogo

          cout << "GAME OVER\n" << endl;

          // Descobre quem ganhou
          if(pongHauKiEvaluation(choice->board, '2', '1', &rep) > 0)
                cout << "" << endl;
          else
                cout << ":(" << endl;

          return 0;

  }
