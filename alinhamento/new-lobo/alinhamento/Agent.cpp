#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Global.hpp"
#include "Agent.hpp"
#include "State.hpp"


using namespace std;

// Useful definitions
typedef vector<vector<char>> Board;


/*******************************
    CONTRUCTORS & DESTRUCTORS
********************************/
Agent::Agent(State* current_state, char player, float alpha, float gamma, float epsilon){
    this->current_state = current_state;
    this->player_symbol = player;
    this->alpha = alpha;
    this->gamma = gamma;
    this->epsilon = epsilon;
    this->states = {};
}

/**************
    METHODS
***************/
float Agent::find_best_action(string transition_hash){
    float highest_q = -999.0;
    string highest_q_state = "";

    //finding best action
    map<string, float>::iterator it = this->Q.begin();
    while(it != this->Q.end()){
        if(it->first == transition_hash){
            if(it->second > highest_q){
                highest_q = it->second; // update the highrst Q
                highest_q_state = it->first; // update the best action
            }
        }
        it++;
    }
    if(highest_q == -999.0){
        highest_q = 0;
        highest_q_state = transition_hash;

    }

    //cout << "CURRENT BEST ACTION HASH: " << highest_q_state << endl;
    return highest_q;
}

vector<vector<int>> Agent::choose_action(){
    Board current_board = this->current_state->getBoard();

    Board target_board;
    int player_pos_idx;
    vector<vector<int>> positions;
    vector<vector<int>> possible_positions;
    vector<int> current_position;
    vector<int> from (2);
    vector<int> action (2);
    vector<vector<int>> pair_from_to = {{0, 0}, {0, 0}};
    
    vector<vector<int>> player_positions = this->current_state->player_search();

    //cout << player_positions.size() << endl;
    // ε-greedy strategy
    if(random_prob() < this->epsilon){
        //exploitation, greedy action

        // AQUI PODE SER QUE DE PROBLEMA 
        // COM OS VALORES DOS HASHES DE TRANSIÇAO

        //cout << endl << "EXPLOIT..." << endl;
        float best_action_value = -999;

        for(vector<vector<int>>::iterator ita = player_positions.begin(); ita != player_positions.end(); ita++){
            current_position = (*ita);

            //cout << "CURRENT POSITION: " << current_position.at(0) << ";" << current_position.at(1) << endl;
            
            int arith = 3*current_position.at(0)+current_position.at(1); 

            possible_positions = this->current_state->possible_moves(arith);
            
            positions = this->current_state->if_available(possible_positions);

            if(!positions.empty()){
                for (vector<vector<int>>::iterator it = positions.begin();it != positions.end(); it++){
                    //cout << "POSSIVEL JOGADA: " << it->at(0) << ";" << it->at(1) << endl;
                    
                    // get the current board
                    Board next_board = this->current_state->getBoard();

                    // make the move
                    next_board[current_position.at(0)][current_position.at(1)] = '0';
                    next_board[it->at(0)][it->at(1)] = this->player_symbol;
                    
                    //cout << "POSSIVEL TABULEIRO COM ESSA JOGADA" << endl;
                    //show_board(next_board);

                    string next_board_hash = getBoardHash(next_board);
                    //cout << "NEXT BOARD HASH: " << next_board_hash << endl;

                    // Updates the transition hash
                    string transition_hash = getTransitionHash(this->current_state->getCurrentHash(), next_board_hash);
                    //cout << "TRANSITION HASH: " << transition_hash << endl;

                    float action_value = this->find_best_action(transition_hash);

                    //cout << "CURRENT BEST ACTION VALUE: " << action_value << endl;
                    //cout << endl;

                    // choose the best action and update the data
                    if(action_value > best_action_value){
                        best_action_value = action_value;
                        from = current_position;
                        action = (*it);
                        pair_from_to.at(0) = from;
                        pair_from_to.at(1) = action;
                    }
                }
            }
        }
        //cout << "DECISAO DE JOGADA EXPLOIT: " << endl << "FROM: " << pair_from_to.at(0).at(0) << ";"<< pair_from_to.at(0).at(1) << endl << 
        //"TO: "<< pair_from_to.at(1).at(0) << ";" << pair_from_to.at(1).at(1) <<  endl << endl;
        

    }else{
        //exploration, random action
        //cout << endl << "EXPLORE..." << endl;

        // Search for positions that the player can try a move
        // If the positions vector is empty, thus the position tanken
        // doesnt have possible moves
        do{
            // Generates a random choose of the piece
            player_pos_idx = randomInt(0, player_positions.size() - 1);

            //cout << "INDICE: " << player_pos_idx << endl;
            // Takes a random position to try a move
            from = player_positions.at(player_pos_idx);
            //cout << from.at(0) << ";" << from.at(1) << endl;
            int arith = 3*from.at(0)+from.at(1); 

            // Generates possible moves from this position
            possible_positions = this->current_state->possible_moves(arith);

            // Search for available positions
            positions = this->current_state->if_available(possible_positions);
            
            //cout << "INDICE: " << player_pos_idx << endl;
        }while(positions.empty());
        //cout << "saiu do while" << positions.size() << endl;
        int action_idx = 0;

        //cout << "FROM: " << from.at(0) << ";" << from.at(1) << endl;
        
        // Generates an index to take a random action
        do{
            action_idx = randomInt(0, positions.size() -1);
        }while(action_idx > positions.size() -1);
        
        //cout << "ACTION IDX: " << action_idx << endl;
        
        // Takes an random action
        action =  positions.at(action_idx);

        // Generates a tuple <from, to> that represents a move
        pair_from_to.at(0) = from;
        pair_from_to.at(1) = action;

        //cout << "DECISAO DE JOGADA EXPLORE: " << endl << "FROM: " << pair_from_to.at(0).at(0) << ";"<< pair_from_to.at(0).at(1) << endl <<
        //"TO: "<< pair_from_to.at(1).at(0) << ";" << pair_from_to.at(1).at(1) <<  endl << endl;

    }

    return pair_from_to;

}

vector<vector<int>> Agent::choose_human_action(){
    int row;
    int col;
    vector<vector<int>> action;
    Board current_board = this->current_state->getBoard();
    while(true){
        cout << "Input your piece position row: ";
        cin >> row;
        cin.clear();
        cout << "Input your piece position col: ";
        cin >> col;
        cin.clear();

        if(current_board.at(row).at(col) == '2'){
            vector<int> from = {row, col};

            cout << "Input your move position row: ";
            cin >> row;
            cin.clear();
            cout << "Input your move position col: ";
            cin >> col;
            cin.clear();

            if(current_board.at(row).at(col) == '0'){
                vector<int> to = {row, col};
                action = {from, to};
                return action;
            }   
        }
    }
}

// Give the reward based on the winner of the game
void Agent::give_reward(int who_win){
    int result = who_win;

    // backpropagate reward
    // checks if player won
    if(result == 1){
        this->feed_reward(1);
    // checks if player lost
    }else if(result == 2){
        this->feed_reward(0);
    // if tie
    }else{
        this->feed_reward(0.1);
    }

}

// Add a transition state to the states' vector
void Agent::add_state(string state){
    this->states.push_back(state);
}

// Make the backpropagation based on transition states
void Agent::feed_reward(float reward){
    for(vector<string>::iterator it = this->states.end() - 1;it != this->states.begin() - 1; it = it-1){
        //it the state of the current iteration exists int the map
        if(exists(this->Q, (*it)) == false){
            this->Q.insert({(*it), 0});
        }
        //cout << "REWARD: " << reward << endl;
        // finding the best action
        float best_next_q_value = find_best_action((*it));

        // calculating delta
        float delta = this->alpha * (reward + (this->gamma * best_next_q_value) - this->Q.at((*it)));

        //cout << "DELTA: " << delta << endl;
        // updating the Q-value
        map <string, float>::iterator key = this->Q.find((*it));
        if(key != Q.end())
            key->second += delta;

        //cout << "CHAVE VALOR: " << (*it) << ";" << this->Q[(*it)] << endl;
    }
}

// Resets the data
void Agent::reset(char player, float alpha, float gamma, float epsilon){
    this->player_symbol = player;
    this->alpha = alpha;
    this->gamma = gamma;
    this->epsilon = epsilon;
    this->states = {};
}

// Saves the policy based on Q-Table
void Agent::save_policy(ofstream *q_table){
    for(map<string, float >::const_iterator it = this->Q.begin(); it != this->Q.end(); ++it){
    	*q_table << it->first << "\t"<<","  << it->second << "," << "\n";
	}  
}

// Loads the policy based on a .csv file
void Agent::load_policy(string file_name){
    ifstream q_table;

    q_table.open(file_name);

    string line1;
    string line2;

    while(!q_table.eof()){
        q_table >> line1;
        q_table >> line2;
        cout << line1 << endl;
        cout << line2 << endl;
        this->Q[line1.substr(0, 18)] = (float)stod(line2.substr(1, line1.size() - 2));
        cout << this->Q[line1.substr(0, 18)] << endl;
    }
}


