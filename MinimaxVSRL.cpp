


/*
g++ MinimaxVSRL.cpp reinforcement-learning/alinhamento/Agent.cpp 
reinforcement-learning/alinhamento/State.cpp 
reinforcement-learning/alinhamento/Global.cpp minimax/alinhamento/tabuleiro.cpp 
minimax/alinhamento/tree.cpp 
minimax/alinhamento/evaluations.cpp 
minimax/alinhamento/move.cpp minimax/alinhamento/decision.cpp 
minimax/alinhamento/node.cpp -o test

*/
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>

// Reinforcement Learning
#include "../lobo-brain/reinforcement-learning/alinhamento/State.hpp"
#include "../lobo-brain/reinforcement-learning/alinhamento/Agent.hpp"
#include "../lobo-brain/reinforcement-learning/alinhamento/Global.hpp"
// Minimax
#include "../lobo-brain/minimax/alinhamento/tabuleiro.hpp"
#include "../lobo-brain/minimax/alinhamento/tree.hpp"
#include "../lobo-brain/minimax/alinhamento/evaluations.hpp"
#include "../lobo-brain/minimax/alinhamento/decision.hpp"
#include "../lobo-brain/minimax/alinhamento/move.hpp"
#include "../lobo-brain/minimax/alinhamento/node.hpp"

typedef vector<vector<char>> Board;

string file_name = "../lobo-brain/reinforcement-learning/alinhamento/q-table_p2.csv";
string winrate_file_name = "../lobo-brain/winrate_vs_minimax.csv";

// Saves the winrate based on the game agains a random player
void save_winrate(ofstream *winrate_file, Agent* p2){
    *winrate_file << "Episode"  << ","  << "Winrate" << "\n";
    for(map<int, float >::const_iterator it = p2->winrate.begin(); it != p2->winrate.end(); ++it){
    	*winrate_file << it->first  << ","  << it->second << "\n";
	}  
}


void play(Agent* p2, int rounds){

    int num_rounds;
    int count_win;
    for(int i=1;i<=rounds;i++){
        int win = 0;
        p2->current_state->is_end = false;
        //cin.get();
        if(i % 100 == 0){
            num_rounds = 100;
            float winrate_variable = (float)count_win/num_rounds;
            p2->winrate.insert({i, winrate_variable});

            if(i%100 == 0){
                cout << "\t" << "WinRate: " << winrate_variable << endl;
            }
            count_win = 0;
        }
        if(i%100 == 0){
            cout << "Round: " << i << endl;
        }
        //tab.posicoes na posicao inicial
        // 0 = vazio
        // 1/2 = jogador
        Tabuleiro start ({{'2', '1', '2'},
                        {'0', '0', '0'},
                        {'1', '2', '1'}});

        // Inicializando tabuleiro
        Tabuleiro tab_atual = start;

        Node* choice;

        vector<vector<int>> possible_mov;

        // gera arvore do inicio
        Tree* game = new Tree(start);

        // repeticoes inicias
        int rep = 0;

        // profundidade maxima
        // Quanto maior for esse valor, mais difícil será o jogo
        int max_depth = 10;

        //system("clear");

        printa_tab(tab_atual);

        while(tapatanEvaluation(tab_atual, game->root->board, '1', '2', &rep) == 0 && p2->current_state->is_end == false){


            /* JOGADA RL */
            p2->current_state->setBoard(tab_atual.getBoard());
            p2->current_state->player_symbol = '2';
            // Player 1 plays
            // p1 action is a [from, to] vector based on the action taken
            cout << endl << "P2 IS PLAYING..." << endl << endl;

            //choose a action to take based in exploration or exploitation
            vector<vector<int>> p2_action = p2->choose_action();
            // take action and update board statgdb e
            p2->current_state->update_state(p2_action.at(0), p2_action.at(1));
                
            cout << "\n\tRL PLAY: " << endl;
            p2->current_state->show_board();
            tab_atual = p2->current_state->getBoard();

            game = new Tree(tab_atual);

            // check if the game's over
            win = p2->current_state->winner();
            //cout << win << endl;
            if (p2->current_state->is_end == true){
                count_win++;
                //cout << "cabo1"<< endl;
                if(win == 2)
                    cout << "PLAYER 1 WINS!!" << endl;
                else if(win == 0)
                    cout << "TIE!!" << endl;
                else
                    cout << "PLAYER 2 WINS!!" << endl;
                

                //p1.reset('1', 0.2, 0.7, 1);
                p2->reset('2', 0.2, 0.7, p2->epsilon);
                break;
            }else{
                cout << endl << "P1 IS PLAYING..." << endl << endl;
                printa_tab(tab_atual);


                /* JOGADA MINIMAX */

                // Chama decision
                choice = decision(game, game->root, false, &rep, max_depth);
                tab_atual = choice->board;
                p2->current_state->setBoard(tab_atual.getBoard());

                cout << "\n\tMINIMAX PLAY: " << endl;
                printa_tab(tab_atual);

                p2->reset('2', 0.2, 0.7, p2->epsilon);

                if(tapatanEvaluation(tab_atual, game->root->board, '1', '2', &rep) > 0){
                    cout << "cabo" << endl;
                    win = 1;
                    p2->current_state->is_end = true;
                    tab_atual = start;
                    p2->current_state->setBoard(tab_atual.getBoard());
                }
            }
        }
    }
    cout << count_win;
}

int main(){
    State current_state = State('1', '2');
    Agent p1 = Agent(&current_state, '1', 0.2, 0, 1);
    Agent p2 = Agent(&current_state, '2', 0.2, 0, 1);
    Global setup = Global(&p1, &p2, &current_state);

    ofstream winrate_file;

    cout << endl << "LOADING POLICY..." << endl;
    setup.p2->load_policy(file_name);

    play(&p2, 1000);

    cout << endl << "SAVING WINRATE..." << endl;
    winrate_file.open(winrate_file_name);
    save_winrate(&winrate_file, &p2);
    winrate_file.close();

    return 0;
}