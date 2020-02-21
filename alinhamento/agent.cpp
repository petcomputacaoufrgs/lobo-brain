#include <vector>
#include <string>
#include <tuple>
#include <random>
#include "siphasher.hpp"
#include "state.hpp"
#include "agent.hpp"

using namespace std;

/*
  Useful definitions
*/
typedef vector<vector<char>> Tabuleiro;
typedef tuple<Tabuleiro, Tabuleiro, float> Qtuple;

/*
  Useful funcions
*/

// returns a random float between 0 an 1
float randomProb() {
  static random_device dev;
  static mt19937 rng(dev());
  static uniform_real_distribution<> dis(0, 1); // [0, 1]
  return dis(rng);
}

// returns a random int between "from" and "to"
int randomInt(int from, int to) {
    static random_device dev;
    static mt19937 rng(dev());
    static uniform_int_distribution<mt19937::result_type> dist6(from, to); // [from, to]
    return dist6(rng);
}

/*
  Class functions
*/

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

    // Ɛ-greedy strategy
    if(randomProb() >= this.epsilon) {

        /*
            | exploitation, greedy action |
        */

        vector<Qtuple> Q = this.Q;

        float highestQ = -1.;
        int highestQindex = -1;

        // finding best action
        for(vector<Qtuple>::iterator it = Q.begin(); it != Q.end(); ++it) {

          if(get<0>(*it) == current_board) {
            if(get<2>(*it) > highestQ) {
              highestQ = get<2>(*it);
              highestQindex = it - Q.begin();
            }
          }

        }

        return get<1>(Q[highestQindex]);

    }else{

      /*
          | exploration, random action |
      */

      vector<Tabuleiro> possibleBoards = this->currentState.possibleBoards(this.symbol, this.jump);
      return possibleBoards[randomInt(0, possibleBoards.size() - 1)];
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
