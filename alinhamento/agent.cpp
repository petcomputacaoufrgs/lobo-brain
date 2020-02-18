#include <vector>
#include <string>
#include <map>
#include "siphasher.hpp"
#include "state.hpp"
#include "agent.hpp"

using namespace std;
typedef vector<vector<char>> Tabuleiro;

Agent::Agent{
    
}

Agent::Agent(float alpha, float gamma, char player){

    this->alpha = alpha;
    this->gamma = gamma;
    this->player = player;
}

vector<int> win_rate(){

}

Tabuleiro chooseAction(Tabuleiro current_board){

}

void addState(vector<int> state){

}

void feedReward(float reward){

}

void reset(){

}

int savePolicy(){

}

void loadPolicy(){

}