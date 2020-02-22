#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include <tuple>
#include <string>
#include <map>
#include "siphasher.hpp"
#include "state.hpp"

using namespace std;

/*
  Useful definitions
*/
typedef vector<vector<char>> Tabuleiro;
typedef tuple<Tabuleiro, Tabuleiro, float> Qtuple;

class Agent{

    public:

        Agent();

		    Agent(float alpha, float gamma, char player, bool jump);

        float winRate(); // record the win rate of all games played

        void takeAction();

        void feedReward(float reward);

        void reset();

        int savePolicy(string policyName);//salva a politica atraves de MDP

        int loadPolicy(string policyName);// carrega a politica

    private:

        float alpha; // represents the learning rate
        float gamma; // discout rate
        float epsilon; // greedy action possibility

        char symbol; // represents the player symbol
        bool jump;  // whether jump engine is on or off

        State *current_state; // pointer to the current state;

        // maps a board (current state board) to another board
        // (action) and then maps it to a float value
        vector<Qtuple> Q;
        vector<Tabuleiro> states; // record all actions taken

        vector<float> rewards;


};
#endif
