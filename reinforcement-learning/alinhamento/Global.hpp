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

        Global(Agent* p1, Agent* p2, State* state); // Constructor
        void train(int rounds, char analyze); // Train the algorithm
        void play();// Plays against an human

        Agent* p1; // Pointer to the p1' class
        Agent* p2; // Pointer to the p2' class
        State* state; // Pointer to states' class
};

/**********************
    GLOBAL VARIABLES
***********************/

/**********************
    GLOBAL FUNCTIONS
***********************/
float random_prob();// Generates a random number between [0, 1]

int random_int(int max); // Generates a random integer between [0, max)

int randomInt(int from, int to);

string getBoardHash(Board state); // Get the board's hash

string getTransitionHash(string last_board_hash, string next_board_hash); // Get the transition hash

void show_board(Board state); // Prints the board

void print_map(map<string, float> myMap); // Prints the Q-Table

bool exists(map<string, float> Q, string state_hash); // Check if 'state_hash' exists in Q-Table

Board getLastBoardFromHash(string transition_hash);

Board getNextBoardFromHash(string transition_hash);

#endif