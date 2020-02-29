#include <iostream>
#include <vector>
#include <string>

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
    if(highest_q = -999.0)
        highest_q = 0;

    cout << "MAIOR Q: " << highest_q << endl;
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
    vector<vector<int>> pair_from_to (2);

    vector<vector<int>> player_positions = this->current_state->player_search();

    // ε-greedy strategy
    if(random_prob() < this->epsilon){
        //exploitation, greedy action

        float best_action_value = -999;

        for(vector<vector<int>>::iterator ita = player_positions.begin(); ita != player_positions.end(); ita++){
            current_position = (*ita);

            cout << "CURRENT POSITION: " << current_position.at(0) << ";" << current_position.at(1) << endl;
            
            int arith = 3*current_position.at(0)+current_position.at(1); 
            
            cout <<"ARITMETICA: "<< arith << endl;

            possible_positions = this->current_state->possible_moves(arith);
            
            positions = this->current_state->if_available(possible_positions);


            for (vector<vector<int>>::iterator it = positions.begin();it != positions.end(); it++){
                cout << "POSSIVEL JOGADA: " << it->at(0) << ";" << it->at(1) << endl;
                
                // get the current board
                Board next_board = this->current_state->getBoard();

                // make the move
                next_board[current_position.at(0)][current_position.at(1)] = '0';
                next_board[it->at(0)][it->at(1)] = this->player_symbol;
                
                cout << "POSSIVEL TABULEIRO COM ESSA JOGADA" << endl;
                show_board(next_board);

                string next_board_hash = getBoardHash(next_board);
                cout << "NEXT BOARD HASH: " << next_board_hash << endl;

                //update the transition hash
                string transition_hash = getTransitionHash(this->current_state->getCurrentHash(), next_board_hash);
                cout << "TRANSITION HASH: " << transition_hash << endl;

                float action_value = this->find_best_action(transition_hash);

                cout << "CURRENT BEST ACTION VALUE: " << action_value << endl;
                cout << endl;

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
        cout << "DECISAO DE JOGADA EXPLOIT: " << endl << "FROM: " << pair_from_to.at(0).at(0) << ";"<< pair_from_to.at(0).at(1) << endl << 
        "TO: "<< pair_from_to.at(1).at(0) << ";" << pair_from_to.at(1).at(1) <<  endl << endl;
        

    }else{
        //exploration, random action

        // TA DANDO UM LOOP AQUI AS VEZES E NAO SEI COMO ARRUMAR
        do{
            // generates a random choose of the piece
            player_pos_idx = random_int(player_positions.size());

            from = player_positions.at(player_pos_idx);
            int arith = 3*from.at(0)+from.at(1); 
            possible_positions = this->current_state->possible_moves(arith);//generates possible moves from this position
            positions = this->current_state->if_available(possible_positions);
            
            cout << "VAZIO?? " << positions.empty() << endl;
            
        }while(positions.empty());

        int action_idx = 0;

        cout << positions.at(0).at(0) << ";" << positions.at(0).at(1) << endl;
        //cout << positions.at(1).at(0) << ";" << positions.at(1).at(1) << endl;

        cout << "PLAYER POS IDX: " << player_pos_idx << endl;
        

        cout << "FROM: " << from.at(0) << ";" << from.at(1) << endl;
        
        // generates an index to take a random action
        cout << "TAMANHO POSITIONS : " << positions.size() << endl;
        action_idx = random_int(positions.size());
        
        cout << "ACTION IDX: " << action_idx << endl;
        
        action =  positions.at(action_idx);

        cout << "POSSIVEL JOGADA " << action.at(0) << ";" << action.at(1) << endl;

        pair_from_to.at(0) = from;
        pair_from_to.at(1) = action;

        cout << "DECISAO DE JOGADA EXPLORE: " << endl << "FROM: " << pair_from_to.at(0).at(0) << ";"<< pair_from_to.at(0).at(1) << endl <<
        "TO: "<< pair_from_to.at(1).at(0) << ";" << pair_from_to.at(1).at(1) <<  endl << endl;

    }

    return pair_from_to;

}

void Agent::give_reward(){
    int result = this->current_state->winner();

    //backpropagate reward
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

void Agent::add_state(string state){
    this->states.push_back(state);
}

void Agent::feed_reward(float reward){
    for(vector<string>::iterator it = this->states.end() - 1;it != this->states.begin(); it = it-1){
        //it the state of the current iteration exists int the map
        if(exists(this->Q, (*it)) == false){
            this->Q.insert({(*it), 0});
        }
        cout << "HASH ATUAL DO LOOP: " << (*it) << endl;
        // finding the best action
        float best_next_q_value = find_best_action((*it));

        // calculating delta
        float delta = this->alpha * (reward + (this->gamma * best_next_q_value) - this->Q.at((*it)));

        // updating the Q-value
        map <string, float>::iterator key = this->Q.find((*it));
        if(key != Q.end())
            key->second += delta;

        cout << (*it) << ";" << this->Q[(*it)] << endl;
        cin.get();
    }
}

// resets the data
void Agent::reset(char player, float alpha, float gamma, float epsilon){
    this->player_symbol = player;
    this->alpha = alpha;
    this->gamma = gamma;
    this->epsilon = epsilon;
    this->states = {};
}



