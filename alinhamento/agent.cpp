#include <vector>
#include <string>
#include <tuple>
#include <random>
#include <numeric>
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

Agent::Agent(float alpha, float gamma, char player, bool jump){

    this->alpha = alpha;
    this->gamma = gamma;
    this->symbol = player;
    this->states = {};

}

float Agent::winRate(){
  return (accumulate(this->rewards.begin(), this->rewards.end(), .0) / this->rewards.size()) * 100;
}

/*
  Here we will take an action based on the Ɛ-greedy strategy
*/
void Agent::takeAction(){

    /*
      First, we'll choose what's the next action to take.
      It sets the 'target_board' variable that will be used later.
    */

    Tabuleiro current_board = this->current_state.getBoard(); //erro aqui
    Tabuleiro target_board;

    // Ɛ-greedy strategy
    if(randomProb() >= this->epsilon) {

        /*
            | exploitation, greedy action |
        */

        vector<Qtuple> Q = this->Q;

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

        target_board = get<1>(Q[highestQindex]);


    }else{

      /*
          | exploration, random action |
      */

      vector<Tabuleiro> possible_boards = this->current_state.possibleBoards(this.symbol, this.jump);
      target_board = possible_boards[randomInt(0, possible_boards.size() - 1)];
    }

    /*
      Now that we decided to what board we're going, we should update
      the state and push the chosen board to the 'states vector'
    */
    this->current_state.setBoard(target_board);
    this->states.push_back(target_board);

    return;

}

void feedReward(float reward){

}

void Agent::reset(){
  this->states = {};
}

int savePolicy(){

}

int loadPolicy(){

}
