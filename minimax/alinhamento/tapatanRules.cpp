//
// Created by phi on 12/08/2021.
//

#include "tapatanRules.hpp"

using namespace std;







/*
 * ==========================
 *          GAME
 *         CLASS
 * ==========================
 */

Game::Game(vector<Player> players, bool jumpEnable) {
    this->players = players;
    this->jumpEnabled = jumpEnable;

    this->finished = False;
    this->playing = players[0];
    this->repetitions = 0;
}

/*
 * ===========================
 *        GAME BOARD
 *        POSSIBLE MOVES
 * ===========================
 */

BoardCoordinates possibleJumpMoves(Player p) {

}

BoardCoordinates possibleMoves(int player_pos){
    vector<vector<int>> possible_mov;
    vector<int> ij;

    switch(player_pos)
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

        default: return possible_mov;
    }
}
