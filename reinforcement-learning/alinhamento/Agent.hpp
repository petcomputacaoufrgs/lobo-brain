#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include <string>
#include <map>
#include <fstream>
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

        vector<vector<int>> choose_human_action(); // choose the action based on the human player

        void give_reward(int who_win); // according monte carlo method, the reward is given at the end of the game

        void add_state(string state); // Add a transition state to the states' vector

        void feed_reward(float reward); // backpropagation (Q-learnign brain XD)

        void reset(char player, float alpha, float gamma, float epsilon); // resets all the agent attributes

        void save_policy(ofstream *q_table); // save the agent policy in a file

        void load_policy(string file_name); // load the agent policy from a file

        float win_rate(); // returns the winrate

        void save_winrate(ofstream *winrate); // save the agent winrate in a file
        
        void save_cumulative_reward(ofstream *reward_file); // save the cumulative reward in a file

        State* current_state; // current state of the board

        // states_value table (Q-table) that 
        // maps a state transition to a value
        map<string, float> Q; 

        map<int, float> winrate; // maps <round, winrate>

        map<int, float> rewards; // maps <round, reward>

        float cumulative_reward;
        
        float epsilon;

    private:
        float alpha;
        float gamma;
        char player_symbol;

        vector<string> states; // keep all positions (board hashes) taken
        

};

#endif
