#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>

#include "State.hpp"
#include "Agent.hpp"
#include "Global.hpp"

using namespace std;

string file_name = "q-table.csv";

vector<vector<int>> choose_action(){

}

int main(){

    State current_state = State('1', '2');
    Agent p1 = Agent(&current_state, '1', 0.2, 0, 1);
    Agent p2 = Agent(&current_state, '2', 0.2, 0, 1);
    Global setup = Global(&p1, &p2, &current_state);

    cout << endl << "LOADING POLICY..." << endl;
    setup.p1->load_policy(file_name);

    cout << endl << "Q-TABLE: " << endl << endl;
    print_map(setup.p1->Q);

    setup.play();

    return 0;
}