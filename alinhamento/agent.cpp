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
  Auxiliary funcions
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

// nao sei se vai funcionar direito mas vamo dale mas n confio mto nao hein porém stackoverflow é meu pastor e nada me faltará
// minha ideia é retornar o índice dela no vetor
int findTuple(Tabuleiro from, Tabueleiro to) {

  auto it = find_if(this.Q.begin(), this.Q.end(), [](const Qtuple& e) {return (get<0>(e) == from) && (get<1>(e) = to);});

  if (it != this.Q.end())
    // existe e retorna o index
    return it - this.Q.begin();
  else
    // nao existe
    return -1;
}

/*
  auxiliary func to find the best action given the current state
  it (is supposed to?) return the index of the tuple in the vector
*/
int findBestAction(Tabuleiro current_board) {

  float highestQ = -1.;
  int highestQindex = -1;

  // finding best action
  for(vector<Qtuple>::iterator it = this.Q.begin(); it != this.Q.end(); ++it) {

    if(get<0>(*it) == current_board) {
      if(get<2>(*it) > highestQ) {
        highestQ = get<2>(*it);
        highestQindex = it - this.Q.begin();
      }
    }

  }

  return highestQindex;

}

/*
  Class functions
*/

Agent::Agent(){

}

Agent::Agent(State* initial_state, float alpha, float gamma, char player, bool jump){

    this->current_state = initial_state;
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

        int bestActionIndex = findBestAction(current_board);

        Qtuple bestAction = this.Q[bestActionIndex];

        target_board = get<1>(bestAction);


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
    this.states.push_back(target_board);

    return;

}

void Agent::feedReward(float reward){

  // finding the value that will be subtracted of the rew at each iteration
  float reduct_index = this.epsilon / this->current_state.episodes;

  // here we'll save the board for next iteration
  Tabuleiro next_board;

  // reversing the vector
  reverse(this.states.begin(), this.states.end());

  // iterating on every board
  for(vector<Tabuleiro>::iterator it = this.states.begin(); it != this.states.end(); ++it) {

    if(next_board == NULL) {
      // first iteration, not much to do
      // just save the sequent board for future math's
      next_board == *it;
    }else{

      // check if tuple already exists
      int current_action_index = findTuple(*it, next_board);

      if(current_action_index == -1) {
        /*
          it doesn't
          so we'll just add a new tupple to our Q vector
        */
        this.Q.push_back(make_tuple(*it, next_board, reward));
      }else{

        /*
          it does, so here comes the math
          we'll use this formula https://miro.medium.com/max/1214/1*b2sPeJxXRqo9hBz9nnWE6w.png
          it is better explained here https://miro.medium.com/max/1638/1*jmcVWHHbzCxDc-irBy9JTw.png
        */

        // make a local copy of the tuple and getting the q-value
        Qtuple current_action = this.Q[current_action_index];
        float current_actionQvalue = get<2>(current_action);

        // best expected future action and separate the q-value to use in Δ calc
        // note: 'exp' stands for expected
        int best_exp_action_index = findBestAction(next_board);

        // this will be the value if the command above returns -1
        // which means it doesn't exist
        float best_nextQvalue = 0.;

        // if it does exist we'll update it
        if(best_exp_action_index != -1) {
          Qtuple best_exp_action = this.Q[best_exp_action_index];
          best_nextQvalue = get<2>(best_exp_action);
        }

        // calculating Δ
        float delta = alpha * (reward + (gamma * best_nextQvalue) - current_actionQvalue);

        // updating the q-value
        get<2>(this.Q[current_action_index]) += delta;

      }
    }

    reward -= reduct_index;

  }

  return;

}

void Agent::reset(){
  this->states = {};
}

int savePolicy(){

}

int loadPolicy(){

}
