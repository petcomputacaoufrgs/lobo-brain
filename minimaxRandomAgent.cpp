//
// Created by phi on 13/08/2020.
//

/*
 *
 * g++ minimaxRandomAgent.cpp minimax/alinhamento/tabuleiro.cpp minimax/alinhamento/tree.cpp minimax/alinhamento/evaluations.cpp minimax/alinhamento/decision.cpp minimax/alinhamento/move.cpp minimax/alinhamento/node.cpp -o testMin
 *
 *
 * */

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>

#include "../lobo-brain/minimax/alinhamento/tabuleiro.hpp"
#include "../lobo-brain/minimax/alinhamento/tree.hpp"
#include "../lobo-brain/minimax/alinhamento/evaluations.hpp"
#include "../lobo-brain/minimax/alinhamento/decision.hpp"
#include "../lobo-brain/minimax/alinhamento/move.hpp"
#include "../lobo-brain/minimax/alinhamento/node.hpp"

string winrate_file = "../lobo-brain/randomOpResults.csv";

const int minimaxAgentWin = 100;
const int randomAgentWin = -100;
const int gameTie = -1;

int randomInt(int from, int to) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(from, to);
    return distrib(gen);
}



/*int saveWinRate(offstream *winrate_file) {

}*/

/*
 *  --------------
 *  Play function
 *  --------------
 *
 *  It makes minimax play one game against
 *  a random player.
 *
 *  Possible returns:
 *      > -1: minimax lost
 *      > 0: game tied
 *      > any other int: minimax won, and the return is the
 *        number of moves it took from the alg to win
 * */
int play(int depth) {


    /*========================*/
    /* ENVIRONMENT/GAME SETUP */
    /*========================*/


    Tabuleiro init ({{'2', '1', '2'},
                     {'0', '0', '0'},
                     {'1', '2', '1'}});

    Tabuleiro current_board = init;

    vector<Tabuleiro> possible_moves;

    // stating game tree
    Tree* game = new Tree(init);

    // number of board setup repetitions in game
    int rep = 0;

    // setting chars
    char minimaxAgentChar = '1'; // this is hard coded
    char randomAgentChar = '2';

    // if jumps are allowed
    bool jump = false;

    // number of moves of the minimax alg
    int moves = 0;

/*  GAME STATE VARIABLES:

        0: not ended
        100: minimax agent win
        -100: random agent win
        -1: tie

        (these values are defined in the 'evaluations' file
            and are defined as constants in this file)
*/
    int gamestate = 0; // current gamestate

    /*================*/
    /* GAME RECURSION */
    /*================*/

    // printing first board
    printa_tab(current_board);

    // while game is not over
    gamestate = tapatanEvaluation(current_board, game->root->board, '1', '2', &rep);
    while(!gamestate){

        /*===================*/
        /* RANDOM AGENT TURN */
        /*===================*/

        // receiving possible next board setups
        possible_moves = game->generateBoards(current_board, randomAgentChar, jump);

        // last index of possible_moves
        int last = possible_moves.size() - 1;

        // randomly select move
        int choosed_move = randomInt(0, last);

        // set the move
        current_board = possible_moves[choosed_move];
        game->free();
        game = new Tree(current_board);

        // print move
        printa_tab(current_board);

        // check if the game is finished
        gamestate = tapatanEvaluation(current_board, game->root->board, '1', '2', &rep);
        if(gamestate)
            // it did finish, exit while loop
            break;

        // it did not finish, continue game

        /*================*/
        /* MINIMAX's TURN */
        /*================*/

        // minimax decision process
        Node* choice = decision(game, game->root, jump, &rep, depth);

        // set the move
        current_board = choice->board;
        game->free();
        game = new Tree(current_board);

        // increase moves counter
        moves++;

        // print move
        printa_tab(current_board);

        // check if game is finished
        gamestate = tapatanEvaluation(current_board, game->root->board, '1', '2', &rep);
    }

    /*============*/
    /* GAME ENDED */
    /*============*/

    // act according to the winner
    if(gamestate == minimaxAgentWin) {
        return moves;
    } else if (gamestate == randomAgentWin) {
        return -1;
    } else {
        //tie
        return 0;
    }
}

int episodicPlay(int eps, int eps_interval, int max_depth) {

    /*==================*/
    /* RECORD VARIABLES */
    /*==================*/

    int episodes_played = 0;
    int minimax_wins = 0;

    // minimax depth, will be increased over time
    int current_depth = 1;

}

int main() {

    vector<int> moves;
    int sum;
    float avg;

    for(int i=0; i<17; i++) {
        moves.push_back(play(9));
    }
    sum = accumulate(moves.begin(), moves.end(), 0.0);
    avg = (float) sum / moves.size();
    cout << sum << "|";printf("%.15f\n", avg);

//    cout << play(10) << endl;

}