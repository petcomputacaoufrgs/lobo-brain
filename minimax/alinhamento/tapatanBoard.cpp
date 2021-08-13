//
// Created by phi on 13/08/2021.
//

#include "tapatanBoard.h"

class tapatanBoard : public Board
{
public:
    // Print function for showing
    // the board in the terminal
    void representation();

    // Read board positions and check
    // whether game is over or not
    // and if it is, returns the winner
    int evaluate();

private:
    // Here we define the default initial condition
    // of the game, that will be used in
    // Initialization without
    // board specification
    initialPositions = {{'2', '1', '2'},
                        {'0', '0', '0'},
                        {'1', '2', '1'}};
};