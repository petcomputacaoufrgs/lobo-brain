#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include <string>
#include <map>
#include "State.hpp"

using namespace std;

// Useful definitions
typedef vector<vector<char>> Board;

class Agent{
    public:
        Agent(State* current_state, char player, float alpha, float gamma, float epsilon); // constructor

        string getHash();

        float find_best_action(string transition_hash); // find the best action based in Q-table

        vector<vector<int>> choose_action(); // choose a action based in the current state

        void give_reward(); // according monte carlo method, the reward is given at the end of the game

        void add_state(string state);

        void feed_reward(float reward); // backpropagation (Q-learnign brain XD)

        void reset(char player, float alpha, float gamma, float epsilon);

        State* current_state;

        // states_value table (Q-table) that 
        // maps a state transition to a value
        map<string, float> Q; 
    private:
        float alpha;
        float gamma;
        float epsilon;
        char player_symbol;

        vector<string> states; // keep all positions (board hashes) taken
        

};

#endif
