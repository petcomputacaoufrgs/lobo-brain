#include <vector>
#include <string>
#include <map>
#include "siphasher.hpp"
#include "state.hpp"
#include "agent.hpp"

using namespace std;
typedef vector<vector<char>> Tabuleiro;

Agent::Agent(){
    
}

Agent::Agent(float alpha, float gamma, char player){

    this->alpha = alpha;
    this->gamma = gamma;
    this->player = player;
    this->states = {};
}

vector<int> win_rate(){

}

Tabuleiro Agent::chooseAction(Tabuleiro current_board){

    // generating random float between 0 and 1
    float p = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    

    if(p < this->alpha) {
        // exploit



    }else{
        //explore
        int x = rand() % ;
        Tabuleiro action = 
    }

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