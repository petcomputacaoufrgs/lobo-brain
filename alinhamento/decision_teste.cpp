#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "state.hpp"
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

        State start ({    {'2', '0', '2'},
                          {'0', '1', '0'},
                          {'1', '2', '1'}});

        Node* choice;

        // gera arvore do inicio
        Tree* test_tree = new Tree(start);

        // profundidade maxima
        int max_depth = 2;

        // se pode pular peças
        bool jump = false;

        int rep = 0;

        start.getPossibleMovesHashes('1', jump);

        cin;

        // Printa input
        cout << "\n\n\t >> IN <<\n\n\t#"
             << start.getHash() << ":" << endl;
        start.print();

        // escolha de jogada
        choice = decision(test_tree, test_tree->root, jump, &rep, max_depth);

        // Printa output
        cout << "\n\n\t >> OUT (" << choice->value << ") <<\n\n\t#"
             << choice->state.getHash() << ":" << endl;
        choice->state.print();

}


  /* TESTE INTERATIVO */


// bool from = false, to = true;
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
//           State start ({    {'2', '1', '2'},
//                             {'0', '2', '0'},
//                             {'1', '0', '1'}   });
//
//           vector<int> from = {-1, -1};
//           vector<int> to = {-1, -1};
//
//           bool jogada_valida = false;
//
//           bool jump = false;
//
//           int rep = 0;
//
//           // Inicializando tabuleiro
//           State state_atual = start;
//
//           vector<vector<char>> t_a = state_atual.getBoard();
//
//           Node* choice;
//
//           vector<vector<int>> possible_mov;
//
//           vector<vector<int>> aux_vet;
//
//           // gera arvore do inicio
//           Tree* game = new Tree(start);
//
//           // profundidade maxima
//           // Quanto maior for esse valor, mais difícil será o jogo
//           int max_depth = 10;
//
//           system("clear");
//           cout << "\n\nBem vindo, você é o jogador 2.\n\n" << endl;
//
//           // TESTES PARA ESCOLHA DE REPRESENTACAO Q-Tabuleiro
//           cout << "\n\tsize hash = " << sizeof(choice->state.getHash()) << endl;
//           cout << "\n\tsize pos = " << sizeof(choice->state.getBoard()[0][0]) * 2 << endl;
//
//           cout << "\t#" << state_atual.getHash() << endl;
//           state_atual.print();
//
//           while(tapatanEvaluation(state_atual, '1', '2', &rep) == 0) {
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
//                       t_a = state_atual.getBoard();
//                       if(t_a[to[0]] [to[1]] == '0') {
//
//                         int player_pos = 3*from[0] + from[1];
//                         possible_mov = tapatanMoves(player_pos);
//
//                         if(jump) {
//                           aux_vet = tapatanJumpMoves(player_pos, state_atual);
//                           possible_mov.insert(possible_mov.end(), aux_vet.begin(), aux_vet.end());
//                         }
//
//                         // Se a casa está no vetor possible_mov, então a jogada é válida
//                         if(find(begin(possible_mov), end(possible_mov), to) != end(possible_mov)) {
//                             state_atual.setPosition(from[0], from[1], '0');
//                             state_atual.setPosition(to[0], to[1], '2');
//                             jogada_valida = true;
//                         }else{
//                             cout << "\tMOVIMENTO INVÁLIDO\n\t\tTENTE OUTRO!" << endl;
//                             }
//                         }else{
//                           cout << "\tJÁ HÁ UMA PEÇA NESTA POSIÇÃO\n\t\tTENTE OUTRA!" << endl;
//                       }
//                   }
//               }else{
//                   cout << "\tESTA POSIÇÃO NÃO CONTÉM UMA PEÇA SUA\n\t\tTENTE OUTRA!" << endl;
//               }
//             }
//
//             // Preparação para próximas jogadas
//             jogada_valida = false;
//             game = new Tree(state_atual);
//
//             cout << "\n\tSua jogada:" << endl;
//             cout << "\t#" << state_atual.getHash() << endl;
//             state_atual.print();
//
//
//             /* JOGADA COMPUTADOR */
//
//
//             // Chama decision
//             choice = decision(game, game->root, jump, &rep, max_depth);
//             state_atual = choice->state;
//
//             cout << "\n\tJogada da máquina:" << endl;
//             cout << "\t#" << state_atual.getHash() << endl;
//             state_atual.print();
//
//       }
//
//       // Se saiu do loop, acabou o jogo
//
//       cout << "GAME OVER\n" << endl;
//
//       // Descobre quem ganhou
//
//       int r = tapatanEvaluation(choice->state, '2', '1', &rep);
//
//       if(r > 0)
//           cout << "Você ganhou" << endl;
//       else if(r < 0)
//           cout << "Você perdeu" << endl;
//       else
//           cout << "Empate" << endl;
//
//       return 0;
//
//  }
