#include <iostream>
#include <vector>
#include <string>
#include "State.hpp"

using namespace std;

// Useful definitions
typedef vector<vector<char>> Board;

// Global variables
Board initial_state({{'2', '1', '2'},
                     {'0', '0', '0'},
                     {'1', '2', '1'}
                    }
                   );


/*******************************
    CONTRUCTORS & DESTRUCTORS
********************************/
State::State(char p1, char p2){
    this->state = initial_state;
    this->p1 = p1;
    this->p2 = p2;
    this->is_end = false; // the game is not over
    this->player_symbol = '1'; // the player 1 plays first
    this->rep = 0; // the number of repetitions is 0 cause the game just started
    this->setCurrentHash(initial_state); // sets the board hash
    this->setLastHash(initial_state); // sets the last board hash
    this->setTransitionHash(current_board_hash, current_board_hash); // set the transition board hash

}

State::~State(){
    this->state.clear();
}

/*************************
    GETTERS & SETTERS
**************************/

// Get the current board of the game
Board State::getBoard(){
    return this->state;
}

// Set the current board to a new board
// so that represents a transition
void State::setBoard(Board new_board){
    this->setLastHash(this->state);
    this->state = new_board;
    this->setCurrentHash(this->state);
    this->setTransitionHash(last_board_hash, current_board_hash);
}

// Get the current board hash
string State::getCurrentHash(){
    return this->current_board_hash;
}

// Set the current board hash
void State::setCurrentHash(Board state){
	this->current_board_hash = "";
    for(int i=0;i<state.size();i++){
        for(int j=0;j<state[i].size();j++){
            this->current_board_hash += state[i][j]; // append char to a string
        }
    }
}

// Get the last board hash
string State::getLastHash(){
    return this->last_board_hash;
}

// Set the last board hash
void State::setLastHash(Board last_state){
    this->last_board_hash = "";
	for(int i=0;i<state.size();i++){
        for(int j=0;j<state[i].size();j++){
            this->last_board_hash += state[i][j]; // append char to a string
        }
    }
}

// Get the transition hash
string State::getTransitionHash(){
    return this->transition_hash;
}

// Set the transition hash
void State::setTransitionHash(string last_state_hash, string next_state_hash){
    this->transition_hash = last_state_hash + next_state_hash;
}



/**************
    METHODS
***************/
// Checks who won the game
int State::winner(){
	Board t = this->getBoard();
	Board t_ini(initial_state);

	int cont = 0;
	char jogador = this->player_symbol;
	char oponente;

	if(player_symbol == '1'){
		oponente = '2';
	}else{
		oponente = '1';
	}
	/***************************
				TIE
	****************************/
	for (int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{

			if(t[i][j] == t_ini[i][j])
			{
				cont++;
				// cout << "cont = " << cont << endl;
			}
		}
	}

	// Tabuleiro igual ao do comeco -> empate
	// Retorna 0 e incrementa repeticoes do tab inicial
	if (cont == 9)
	{
		(this->rep)++;
		if (this->rep >= 3) {
			this->is_end = true;
			return 0;
		}
	}

	/***************************
				WIN
	****************************/
	if (t[0][0] == jogador)
	{
		if (t[0][1] == jogador && t[0][2] == jogador ||
			t[1][0] == jogador && t[2][0] == jogador ||
			t[1][1] == jogador && t[2][2] == jogador)
		{
			this->is_end = true;
			return 1;
		}
	}
	else if (t[0][2] == jogador)
	{
		if (t[1][1] == jogador && t[2][0] == jogador ||
			t[1][2] == jogador && t[2][2] == jogador)
		{
			this->is_end = true;
			return 1;
		}
	}
	else if (t[1][1] == jogador)
	{
	    if(t[0][1] == jogador && t[2][1] == jogador ||
		   t[1][0] == jogador && t[1][2] == jogador) 
        {
			this->is_end = true;
			return 1;
		}
	}
	else if (t[2][0] == jogador)
	{
		if(t[2][1] == jogador && t[2][2] == jogador) 
        {
			this->is_end = true;
			return 1;
		}
	}

	/***************************
				LOSE
	****************************/

    if (t[0][0] == oponente){
		if (t[0][1] == oponente && t[0][2] == oponente ||
			t[1][0] == oponente && t[2][0] == oponente ||
			t[1][1] == oponente && t[2][2] == oponente)
        {
			this->is_end = true;
			return 2;
		}
	}
	else if (t[0][2] == oponente)
	{
		if (t[1][1] == oponente && t[2][0] == oponente ||
			t[1][2] == oponente && t[2][2] == oponente)
		{
		    this->is_end = true;
			return 2;
		}
	}
	else if (t[1][1] == oponente)
	{
		if(t[0][1] == oponente && t[2][1] == oponente ||
		   t[1][0] == oponente && t[1][2] == oponente) 
        {
			this->is_end = true;
            return 2;
	    }
	}
	else if (t[2][0] == oponente)
	{
		if(t[2][1] == oponente && t[2][2] == oponente) 
        {
			this->is_end = true;
			return 2;
		}
	}

	/***************************
				LOSE
	****************************/

	this->is_end = false;
	return 0;
}

// Checks for possible moves
// Returns a vector of tuples (possible moves) 
// ([i,j] represents the positions of the board)
// and that represents the actions
vector<vector<int>> State::possible_moves(int player_position){
    vector<vector<int>> possible_mov;
    vector<int> ij (2);

    switch(player_position)
    {
		case 0://(0,0)
			ij.push_back(0); ij.push_back(1);
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 0;
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 1;
			possible_mov.push_back(ij);
			
		    return possible_mov;

		case 1://(0,1)
			ij.push_back(0); ij.push_back(0);
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 1;
			possible_mov.push_back(ij);

			ij[0] = 0; ij[1] = 2;
			possible_mov.push_back(ij);
		    return possible_mov;

		case 2://(0,2)
			ij.push_back(0); ij.push_back(1);
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 1;
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 2;
			possible_mov.push_back(ij);
		    return possible_mov;

		case 3://(1,0)
			ij.push_back(0); ij.push_back(0);
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 1;
			possible_mov.push_back(ij);

			ij[0] = 2; ij[1] = 0;
			possible_mov.push_back(ij);
		    return possible_mov;

		case 4://(1,1)
			ij.push_back(0); ij.push_back(0);
			possible_mov.push_back(ij);

			ij[0] = 0; ij[1] = 1;
			possible_mov.push_back(ij);

			ij[0] = 0; ij[1] = 2;
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 0;
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 2;
			possible_mov.push_back(ij);

			ij[0] = 2; ij[1] = 0;
			possible_mov.push_back(ij);

			ij[0] = 2; ij[1] = 1;
			possible_mov.push_back(ij);

			ij[0] = 2; ij[1] = 2;
			possible_mov.push_back(ij);
		    return possible_mov;

		case 5://(1,2)
			ij.push_back(0); ij.push_back(2);
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 1;
			possible_mov.push_back(ij);

			ij[0] = 2; ij[1] = 2;
			possible_mov.push_back(ij);
		    return possible_mov;

		case 6://(2,0)
			ij.push_back(2); ij.push_back(1);
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 0;
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 1;
			possible_mov.push_back(ij);
		    return possible_mov;

		case 7://(2,1)
			ij.push_back(2); ij.push_back(0);
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 1;
			possible_mov.push_back(ij);

			ij[0] = 2; ij[1] = 2;
			possible_mov.push_back(ij);
		    return possible_mov;

		case 8://(2,2)
			ij.push_back(2); ij.push_back(1);
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 1;
			possible_mov.push_back(ij);

			ij[0] = 1; ij[1] = 2;
			possible_mov.push_back(ij);
		    return possible_mov;

		default: 
            return possible_mov;
   }
}

// Generates the possible board according the current state of the game
vector<Board> State::possible_boards(char player){
	int i,j, player_pos;
    vector<vector<int>> possible_mov;//matriz com as possiveis posicoes geradas a partir do tabuleiro passado como parametro
    vector<vector<int>> aux_vet;
    vector<Board> possibleBoards;//vetor com os possiveis tabuleiros gerados a partir da posicao atual

	Board t = this->getBoard();

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(t[i][j] == player)//verifica se a posicao do tabuleiro esta sendo ocupada pelo jogador
            {
                player_pos = 3*i+j;//realiza uma aritmetica para determinar a posicao do jogador no tabuleiro

                possible_mov = possible_moves(player_pos);

                for(vector<vector<int>>::iterator it = possible_mov.begin(); it != possible_mov.end(); it++)//varre todas as posicoes do tabuleiro
                {
                    if(t[it->at(0)][it->at(1)] == '0')//verifica se a posicao do tabuleiro esta vazia para poder realizar a possivel movimentacao
                    {

                        Board new_board = this->getBoard();
                        //gera um possivel tabuleiro com a possivel movimentacao a partir da posicao atual do jogo
                        new_board[it->at(0)] [it->at(1)] = player;
                        //quer dizer que o jogador se movimentou, ou seja, tem que zerar a posicao anterior dele
                        new_board[i][j] = '0';

                        possibleBoards.push_back(new_board);
                    }

                }
            }
        }
    }

    return possibleBoards;

}

vector<vector<int>> State::player_search(){
	vector<vector<int>> player_positions;
	vector<int> ij (2);
	//cout << this->player_symbol << endl;
	for(int i=0; i < this->state.size(); i++){
		for(int j=0;j < this->state[i].size(); j++){
			//cout << this->state[i][j] << endl;
			if(this->state[i][j] == this->player_symbol){
				ij.at(0) = i;
				ij.at(1) = j;
				player_positions.push_back(ij);
			}
			
		}
	}
	return player_positions;
}

// isso aqui é uma gambiarra pra arrumar um bagulho, mas tem forma facil de arrumar isso
vector<vector<int>> State::if_available(vector<vector<int>> possible_positions){
	Board state = this->getBoard();
	vector<vector<int>> positions;
	for(vector<vector<int>>::iterator it = possible_positions.begin(); it != possible_positions.end(); it++){	
		if (state[it->at(0)][it->at(1)] == '0'){
			positions.push_back((*it));
		}
	}
	return positions;
}
void State::update_state(vector<int> current_position, vector<int> move_position){

	this->setLastHash(this->state);
    this->state[current_position.at(0)][current_position.at(1)] = '0';
    this->state[move_position.at(0)][move_position.at(1)] = this->player_symbol;
	this->setCurrentHash(this->state);
	this->setTransitionHash(last_board_hash, current_board_hash);

    //switch to another player
    if(this->player_symbol == '1'){
        this->player_symbol = '2';
    }else{
        this->player_symbol = '1';
    }

}


void State::reset(){
    this->state = initial_state;
    this->p1 = '1';
    this->p2 = '2';
    this->is_end = false; // the game is not over
    this->player_symbol = '1'; // the player 1 plays first
    this->rep = 0; // the number of repetitions is 0 cause the game just started
    this->setCurrentHash(initial_state); // sets the board hash
    this->setLastHash(initial_state); // sets the last board hash
    this->setTransitionHash(current_board_hash, current_board_hash); // set the transition board hash
}


void State::show_board(){
    vector<vector<char>> t = this->getBoard();
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
