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

        vector<int> win_rate(); // record the win rate of all games played

        Tabuleiro chooseAction(Tabuleiro current_board); // generates all actions through the curret state

        void addState(vector<int> state); // add new state to the state array

        void feedReward(float reward);

        void reset();

        int savePolicy();//salva a politica atraves de MDP

        void loadPolicy();// carrega a politica

    private:

        float alpha; // represents the learning rate
        float gamma; // discout rate
        float epsilon; // greedy action possibility
        char symbol; // represents the player symbol
        bool jump;  // whether jump engine is on or off

        State *currentState; // pointer to the current state;

        // maps a board (current state board) to another board
        // (action) and then maps it to a float value
        vector<Qtuple> Q;
        vector<Tabuleiro> states; // record all positions taken


};
#endif
