#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>

#include "State.hpp"
#include "Agent.hpp"
#include "Global.hpp"

using namespace std;

string q_file_name = "q-table.csv";
string winrate_file_name = "winrate.csv";
string reward_file_name = "reward.csv";

int main(int argc, char* argv[]){

    ofstream q_table;
    ofstream winrate_file;
    ofstream reward_file;
    State current_state = State('1', '2');
    Agent p1 = Agent(&current_state, '1', 0.2, 0.7, 0.3);
    Agent p2 = Agent(&current_state, '2', 0.2, 0.7, 0);
    Global setup = Global(&p1, &p2, &current_state);
    

    //cout << "First player: " << setup.state->player_symbol << endl;
    //cout << "Initial current board hash: " << "\"" << setup.p1->current_state->getCurrentHash() << "\"" << endl;
    //cout << "Initial last board hash: " << "\"" << setup.p1->current_state->getLastHash() << "\"" << endl;
    //cout << "Initial transition hash: " << "\"" << setup.p1->current_state->getTransitionHash() << "\"" << endl;
    //setup.state->show_board();

    //cin.get();

    cout << "Training..." << endl;
    setup.train(150000);
    cout << "Finished!" << endl;

    cout << endl << "Q-TABLE: " << endl << endl;
    //print_map(setup.p1->Q);

    cout << endl << "SAVING POLICY..." << endl;
    q_table.open(q_file_name);
    setup.p1->save_policy(&q_table);
    q_table.close();

    cout << endl << "SAVING WINRATE..." << endl;
    winrate_file.open(winrate_file_name);
    setup.p1->save_winrate(&winrate_file);
    winrate_file.close();

    cout << endl << "SAVING CUMULATIVE REWARD..." << endl;
    reward_file.open(reward_file_name);
    setup.p1->save_cumulative_reward(&reward_file);
    reward_file.close();

    return 0;
}