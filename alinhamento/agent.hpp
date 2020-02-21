#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include <tuple>
#include <string>
#include <map>
#include "siphasher.hpp"
#include "state.hpp"

using namespace std;
typedef vector<vector<char>> Tabuleiro;


class Agent{

    public:

        Agent();

		Agent(float alpha, float gamma, char player);

        vector<int> win_rate(); // record the win rate of all games played

        Tabuleiro chooseAction(Tabuleiro current_board); // generates all actions through the curret state

        void addState(vector<int> state); // add new state to the state array

        void feedReward(float reward);

        void reset();

        int savePolicy();//salva a politica atraves de MDP

        void loadPolicy();// carrega a politica

    private:

        float alpha; // represents the learning rate
        float gamma; // represents the exploration\ rate
        float epsilon; // 1 - alpha
        char player; // represents the player

        // maps a board (current state board) to another board
        // (action) and then maps it to a float value
        vector<tuple<Tabuleiro, Tabuleiro, float>> Q;
        vector<Tabuleiro> states; // record all positions taken


};
#endif
