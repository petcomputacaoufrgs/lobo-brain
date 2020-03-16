#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "State.hpp"
#include "Agent.hpp"
#include "Global.hpp"

// Class constructor
Global::Global(Agent* p1, Agent* p2, State* state){
    this->p1 = p1;
    this->p2 = p2;
    this->state = state;
}

// Train the algorithm
void Global::train(int rounds){
    int win = 0;
    int count_win = 0;
    int num_rounds = 0;
    this->p1->cumulative_reward = 0;
    for(int i=1;i<=rounds;i++){
        this->state->reset();
        if(i % 1000 == 0){
            cout << "Rounds: " << i << endl;
            cout << "\t" << "Epsilon p1: " << this->p1->epsilon << endl;
            cout << "\t" << "Epsilon p2: " << this->p2->epsilon << endl;
            
        }
        if(i % 100 == 0){
            num_rounds = 100;
            float winrate_variable = (float)count_win/num_rounds;
            this->p1->winrate.insert({i, winrate_variable});
            this->p1->rewards.insert({i, this->p1->cumulative_reward});

            if(i%1000 == 0){
                cout << "\t" << "WinRate: " << winrate_variable << endl;
                cout << "\t" << "Cumulative Reward: " << this->p1->cumulative_reward << endl;
            }

            if(this->p1->epsilon < .95){
             this->p1->epsilon += .002;
            }
            count_win = 0;
            this->p1->cumulative_reward = 0;
        }
        while(this->state->is_end == false){
            // Player 1 plays
            // p1 action is a [from, to] vector based on the action taken

            //choose a action to take based in exploration or exploitation
            vector<vector<int>> p1_action = this->p1->choose_action();
            
            // take action and update board statgdb e
            this->state->update_state(p1_action.at(0), p1_action.at(1)); 

            // add the transition state to the states vector
            this->p1->add_state(this->state->getTransitionHash());

            // check if the game's over
            win = this->state->winner();
            if (this->state->is_end == true){
                //ended with p1 either win or draw
                count_win++;
                if(win == 0){
                    // Give reward to p1 (0 represents a tie)
                    this->p1->give_reward(0);
                    // Give reward to p2 (0 represents a tie)
                    this->p2->give_reward(0);
                }else{
                    // Give reward to p1 (1 represents that won)
                    this->p1->give_reward(1);
                    // Give reward to p2 (2 represents that lose)
                    this->p2->give_reward(2);
                }
                this->p1->reset('1', 0.2, 0.7, this->p1->epsilon);
                this->p2->reset('2', 0.2, 0.7, this->p2->epsilon);
                break;
            }else{
                // If the game is not over
                // Player 2 plays
                // p2 action is a [from, to] vector based on the action taken
                vector<vector<int>> p2_action = this->p2->choose_action();//choose a action to take based in exploration or exploitation

                // take action and update board state
                this->state->update_state(p2_action.at(0), p2_action.at(1));

                // add the transition state to the states vector
                this->p2->add_state(this->state->getTransitionHash());

                // check if the game's over
                win = this->state->winner();
                if (this->state->is_end == true){
                    //ended with p2 either win or draw

                    if(win == 0){
                        // Give reward to p1 (0 represents a tie)
                        this->p1->give_reward(0);
                        // gGve reward to p2 (0 represents a tie)
                        this->p2->give_reward(0);
                     }else{
                        // Give reward to p1 (1 represents that won)
                        this->p1->give_reward(2);
                        // Give reward to p2 (2 represents that lose)
                        this->p2->give_reward(1);
                    }
                    
                    this->p1->reset('1', 0.2, 0.7, this->p1->epsilon);
                    this->p2->reset('2', 0.2, 0.7, this->p2->epsilon);
                    break;
                }
            }
        }
        // if(this->p1->epsilon < 0.95){
        //      this->p1->epsilon += 0.002;
        // }
    }
}

// Plays against an human
void Global::play(){
    int win;
    while(this->state->is_end ==  false){
        // Player 1 plays
        // p1 action is a [from, to] vector based on the action taken
        cout << endl << "P1 IS PLAYING..." << endl << endl;

        //choose a action to take based in exploration or exploitation
        vector<vector<int>> p1_action = this->p1->choose_action();
        // take action and update board statgdb e
        this->state->update_state(p1_action.at(0), p1_action.at(1));
            
        cout << "ESTADO DO JOGO ATUALIZADO PARA: " << endl;
        this->state->show_board();

        // check if the game's over
        win = this->state->winner();
        if (this->state->is_end == true){
            if(win == 1)
                cout << "PLAYER 1 WINS!!" << endl;
            else if(win == 0)
                cout << "TIE!!" << endl;
            else
                cout << "PLAYER 2 WINS!!" << endl;
            

            this->p1->reset('1', 0.2, 0.7, 1);
            this->p2->reset('2', 0.2, 0.7, 1);
            break;
        }else{
            // If the game is not over
            // Player 2 plays
            // p2 action is a [from, to] vector based on the action taken
            cout << endl << "P2 IS PLAYING !!!" << endl << endl;
            
            vector<vector<int>> p2_action = this->p2->choose_human_action();//choose a action to take based in exploration or exploitation

            // take action and update board state
            this->state->update_state(p2_action.at(0), p2_action.at(1));

            cout << "ESTADO DO JOGO ATUALIZADO PARA: " << endl;
            this->state->show_board();

            // check if the game's over
            win = this->state->winner();
            if (this->state->is_end == true){
                if(win == 2)
                    cout << "PLAYER 2 WINS!!" << endl;
                else if(win == 0)
                    cout << "TIE!!" << endl;
                else
                    cout << "PLAYER 2 WINS!!" << endl;

                this->p1->reset('1', 0.2, 0.7, 1);
                this->p2->reset('2', 0.2, 0.7, 1);
                break;
            }
        }
    }
}

// Generates a random number between 0 and 1 (including)
float random_prob(){
    static random_device dev;
    static mt19937 rng(dev());
    static uniform_real_distribution<> dis(0, 1); // [0, 1]
    return dis(rng);
}

// Generates a random int between 0 and max (excluding max)
int random_int(int max){
    if (max == 0 || max == 1)
        return 0;
	srand(time(0));
  	int randomNumber;
    randomNumber = (rand() % max);

    return randomNumber;
}

// returns a random int between "from" and "to"
int randomInt(int from, int to) {
    static random_device dev;
    static mt19937 rng(dev());
    static uniform_int_distribution<mt19937::result_type> dist6(from, to); // [from, to]
    return dist6(rng);
}

// Get the board hash
string getBoardHash(Board state){
    string board_hash;
    for(int i=0;i<state.size();i++){
        for(int j=0;j<state[i].size();j++){
            board_hash += state[i][j]; // append char to a string
        }
    }
    return board_hash;
}

// Get the transition hash
string getTransitionHash(string last_board_hash, string next_board_hash){
    return last_board_hash + next_board_hash;
}

// Prints the board
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

// Prints the Q-Table
void print_map(map<string, float> myMap){
	for(map<string, float >::const_iterator it = myMap.begin();
    it != myMap.end(); ++it)
	{
    	cout << "<"<<it->first << ";"  << it->second << ">"<<"\n";
	}
}

// Checks if 'state_hash' exists in the Q-Table
bool exists(map<string, float> Q, string state_hash){
    // find method returns a iterator, 
    // so if its equals Q.end state_hash doesnt exists
    map <string, float>::iterator it = Q.find(state_hash);
    if (it == Q.end()){ 
        return false;
    }else{
        return true;
    }
}

// Converts a hash to a Board
Board getLastBoardFromHash(string transition_hash){
    string last_hash = transition_hash.substr(0, 9);
    Board last_state;
    int k = 0;
    for(int i=0;i<3;i++){ 
        for(int j=0;j<3;j++){
            last_state[i][j] = last_hash[k];
            k++;
        }
        k++;
    }
    return last_state;
}

// Converts a hash to a Board
Board getNextBoardFromHash(string transition_hash){
    string next_hash = transition_hash.substr(9, 9);
    Board next_state;
    int k = 0;
    for(int i=0;i<3;i++){ 
        for(int j=0;j<3;j++){
            next_state[i][j] = next_hash[k];
            k++;
        }
        k++;
    }
    return next_state;
}