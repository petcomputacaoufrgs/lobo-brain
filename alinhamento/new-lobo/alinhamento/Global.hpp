#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>
#include <string>
#include <random>

#include "State.hpp"
#include "Agent.hpp"

using namespace std;

class Global{
    public:
        Global(Agent* p1, Agent* p2, State* state);
        void train(int rounds);

        Agent* p1;
        Agent* p2;
        State* state;
};

float random_prob();// generates a random number between [0, 1]

int random_int(int min, int max); // generates a random integer between [min, max]

string getBoardHash(Board state);

string getTransitionHash(string last_board_hash, string next_board_hash);

void show_board(Board state);

bool exists(map<string, float> Q, string state_hash);

#endif