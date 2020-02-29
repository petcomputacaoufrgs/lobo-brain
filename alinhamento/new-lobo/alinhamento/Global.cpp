#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "State.hpp"
#include "Agent.hpp"
#include "Global.hpp"

Global::Global(Agent* p1, Agent* p2, State* state){
    this->p1 = p1;
    this->p2 = p2;
    this->state = state;
}

void Global::train(int rounds){
    for(int i=0;i<rounds;i++){
        this->state->reset();
        cout << "NOVO JOGO " << endl;
        cin.get();
        if(i % 1000 == 0){
            cout << "Rounds: " << i << endl;
        }
        while(this->state->is_end == false){
            // Player 1 plays
            // p1 action is a [from, to] vector based on the action taken

            cout << endl << "P1 IS PLAYING !!!" << endl << endl;

            vector<vector<int>> p1_action = this->p1->choose_action();//choose a action to take based in exploration or exploitation
            cout << "ESTOU NA TRAIN LOGO APOS A CHAMDA DA CHOOSE ACTION (P1)" << endl;
            // take action and update board statgdb e
            this->state->update_state(p1_action.at(0), p1_action.at(1));
            
            cout << "ESTADO DO JOGO ATUALIZADO PARA: " << endl;
            this->state->show_board();
            cout << "TRANSITION HASH: " << this->state->getTransitionHash() << endl; 

            // add the transition state to the states vector
            this->p1->add_state(this->state->getTransitionHash());

            // check if the game's over
            int win = this->state->winner();
            if (this->state->is_end == true){
                //ended with p1 either win or draw
                cout << "JOGO ACABOU COM P1 VECENDO OU EMPATANDO" << endl;
                this->state->show_board(); // to visualize the boards
                this->p1->give_reward();
                
                cout << "APOS GIVE REWARD P1" << endl;

                this->p1->reset('1', 0.2, 0.7, 0.3);
                this->p2->reset('2', 0.2, 0.7, 0.3);
                this->state->reset();
                break;
            }else{
                // If the game is not over
                // Player 2 plays
                // p2 action is a [from, to] vector based on the action taken
                cout << endl << "P2 IS PLAYING !!!" << endl << endl;
                vector<vector<int>> p2_action = this->p2->choose_action();//choose a action to take based in exploration or exploitation
                cout << "ESTOU NA TRAIN LOGO APOS A CHAMDA DA CHOOSE ACTION (P2)" << endl;

                // take action and update board state
                this->state->update_state(p2_action.at(0), p2_action.at(1));

                cout << "ESTADO DO JOGO ATUALIZADO PARA: " << endl;
                this->state->show_board();
                cout << "TRANSITION HASH: " << this->state->getTransitionHash() << endl;

                // add the transition state to the states vector
                this->p2->add_state(this->state->getTransitionHash());

                // check if the game's over
                int win = this->state->winner();
                if (this->state->is_end == true){
                    cout << "JOGO ACABOU COM P2 VECENDO OU EMPATANDO" << endl;
                    //ended with p1 either win or draw
                    this->p2->give_reward();

                    cout << "APOS GIVEREWARD P2" << endl;

                    this->p1->reset('1', 0.2, 0.7, 0.3);
                    this->p2->reset('2', 0.2, 0.7, 0.3);
                    this->state->is_end = true;
                    break;
                }
            }
        }
    }
}

float random_prob(){
    static random_device dev;
    static mt19937 rng(dev());
    static uniform_real_distribution<> dis(0, 1); // [0, 1]
    return dis(rng);
}

int random_int(int max){
	srand(time(0));
  	int randomNumber;
    randomNumber = (rand() % max);
    cout << "DENTRO DA FUNCAO: "<< randomNumber << endl;

    return randomNumber;
}

string getBoardHash(Board state){
    string board_hash;
    for(int i=0;i<state.size();i++){
        for(int j=0;j<state[i].size();j++){
            board_hash += state[i][j]; // append char to a string
        }
    }

    return board_hash;
}

string getTransitionHash(string last_board_hash, string next_board_hash){
    return last_board_hash + next_board_hash;
}

void show_board(Board state){
    vector<vector<char>> t = state;
	cout << "\t=============" << endl ;
	for(int i=0; i<3; i++){
		cout << '\t';
		for(int j=0; j<3; j++) {
			cout << "| " << t[i][j] << " ";
		}
                cout << "|" << endl;
    }
	cout << "\t=============" << endl ;
}

// checks if state_hash exists in a map
bool exists(map<string, float> Q, string state_hash){
    // find method returns a iterator, 
    // so if its equals Q.end state_hash doesnt exists
    if (Q.find(state_hash) == Q.end()){ 
        return false;
    }else{
        return true;
    }
}