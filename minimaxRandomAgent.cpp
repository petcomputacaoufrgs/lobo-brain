//
// Created by phi on 13/08/2020.
//

/*
 *
 * g++ minimaxRandomAgent.cpp minimax/alinhamento/tabuleiro.cpp minimax/alinhamento/tree.cpp minimax/alinhamento/evaluations.cpp minimax/alinhamento/decision.cpp minimax/alinhamento/move.cpp minimax/alinhamento/node.cpp -o minimaxRA
 *
 *
 * */


// UNCOMMENT FOR WINDOWS
//#define WINDOWS

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <filesystem>

#include "../lobo-brain/minimax/alinhamento/tabuleiro.hpp"
#include "../lobo-brain/minimax/alinhamento/tree.hpp"
#include "../lobo-brain/minimax/alinhamento/evaluations.hpp"
#include "../lobo-brain/minimax/alinhamento/decision.hpp"
#include "../lobo-brain/minimax/alinhamento/move.hpp"
#include "../lobo-brain/minimax/alinhamento/node.hpp"

const int minimaxAgentWin = 100;
const int randomAgentWin = -100;
const int gameTie = -1;

string GetCurrentWorkingDir( void ) {
    char buff[FILENAME_MAX];
    GetCurrentDir( buff, FILENAME_MAX );
    string current_working_dir(buff);
    return current_working_dir;
}

int randomInt(int from, int to) {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(from, to);
    return distrib(gen);
}

void saveResults(vector<int> *losses, vector<float> *moves, string results_file) {

    int max_depth = losses->size();

    ofstream file(results_file);

    file << "Depth,Losses,AvgMoves" << endl;
    for(int i=0; i < max_depth; i++) {
        file << i+1 << "," << losses->at(i) << "," << moves->at(i) << endl;
    }

    file.close();
}

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
    char minimaxAgentChar = '1'; // this is hard coded...
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
    // printa_tab(current_board);

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
        // printa_tab(current_board);

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
        // printa_tab(current_board);

        // check if game is finished
        gamestate = tapatanEvaluation(current_board, game->root->board, '1', '2', &rep);
    }

    /*============*/
    /* GAME ENDED */
    /*============*/

//    printa_tab(current_board);

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

void episodicPlay(int eps, int depth, vector<float> *moves, vector<int> *losses) {

    /*==================*/
    /* RECORD VARIABLES */
    /*==================*/

    int losses_counter = 0;
    int moves_counter = 0;
    float losses_avg;
    float moves_avg;

    /*===================*/
    /* PLAY & RECORD LOOP*/
    /*===================*/

    const clock_t begin_time = clock();
    cout << "\nDepth " << depth << " started." << endl;

    for(int i=0; i<eps; i++) {
        int ret = play(depth);
        if(ret > 0) {
            moves_counter += ret;
        } else if(ret == -1) {
            losses_counter += 1;
        }
    }

    /*==============*/
    /* SAVE RESULTS */
    /*==============*/

    // get avg moves
    moves_avg = (float) moves_counter / eps;
//    loses_avg = (float) loss_counter / eps;

    moves->push_back(moves_avg);
    losses->push_back(losses_counter);

    float t = float( clock () - begin_time ) /  CLOCKS_PER_SEC;
    cout << "Depth " << depth << " finished. (" << t << "s)" << endl;

    /*=======*/
    /* DEBUG */
    /*=======*/

/*    cout << "> depth=" << depth << endl;
    cout << "\nmoves_counter=" << moves_counter << endl;
    cout << "\nmoves_avg=" << moves_avg << endl;
    cout << "\nloss_counter=" << loss_counter << endl;*/

}

int main(int argc, char** argv) {

    if(argc != 4) {
        cout << "Usage: " << argv[0] << " (eps | INT) (max_depth | INT) (output file name | STRING [.csv])" << endl;
        exit(0);
    }

    vector<float> moves;
    vector<int> losses;

    // number of episodes per depth
    int eps = atoi(argv[1]);

    // farthest depth it will go
    int max_depth = atoi(argv[2]);

    // where  to save results
    string results_file = GetCurrentWorkingDir() + "/" + argv[3];

    cout << results_file << endl;

    cout << "Running with the following parameters: \n"
         << "\tMax depth=" << max_depth << "\n"
         << "\tEps per depth=" << eps << endl;

    const clock_t begin = clock();

    for(int i=1; i<=max_depth; i++) {
        episodicPlay(eps, i, &moves, &losses);
    }

    float full_t = float( clock () - begin ) /  CLOCKS_PER_SEC;
    saveResults(&losses, &moves, results_file);
    cout << "Results file saved as " << results_file << ". (" << full_t << "s)" << endl;

}