#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>

using namespace std;

// Useful definitions
typedef vector<vector<char>> Board;

class State{
    public:
        State(char p1, char p2); // constructor
        ~State(); //destroyer

        Board getBoard(); // get the board
        void setBoard(Board new_board); // set the board

        string getCurrentHash(); // get the current board hash
        void setCurrentHash(Board state); // set the current board hash

        string getLastHash(); // get the last board hash
        void setLastHash(Board last_state); // set the last board hash

        string getTransitionHash(); // get the board's transition hash
        void setTransitionHash(string last_state_hash, string next_state_hash); // set the board's transition hash

        int winner(); // checks if the game's over and returns the winner

        vector<vector<int>> possible_moves(int player_position); // search for possible moves from player_position

        vector<Board> possible_boards(char player); // generates possible boards according the current game state

        vector<vector<int>> player_search(); // search for the player positions

        vector<vector<int>> if_available(vector<vector<int>> possible_positions);

        void update_state(vector<int> current_position, vector<int> move_position); // updates the state of the game (new board and the new player_symbol)

        void reset();// resets the data of the class


        void show_board(); // print the board

        // save the number of repetitions of the 
        //initial board state (to check a possible tie)
        int rep;

        char player_symbol; // the player whos currently playing
        bool is_end; // determines if the game's over


    private:
        Board state; // current state of the game
        char p1; // the player's 1 symbol
        char p2; // the player's 2 symbol
        string current_board_hash; // the hash of the board state
        string last_board_hash; // the hash of the last state of the board
        string transition_hash; // the hash of the state transition (last_board -> next_board) - represents a move

};


#endif