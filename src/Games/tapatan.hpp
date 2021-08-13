#ifndef LOBO_BRAIN_TAPATAN_H
#define LOBO_BRAIN_TAPATAN_H

#include "../LoBoBrain.hpp"
#include "../LoBoBrain/player.hpp"

using namespace std;

/*
 * Class with heritage from Player
 * that adds a custom 'position'
 * function that will be used to
 * evaluate the boards.
 * In the case of Tapatan,
 * the current code was defined:
 *
 * playerPosition = 3*i+j, where
 * 'i' and 'j' are the coordinates
 * of the pieces in the board
 */

class TapatanPlayer : public Player
{

public:
    void update();


private:
    vector<BoardCoordinates> possibleMoves;

    void updatePossibleMoves();
    void updatePieces();
};

class TapatanGame : public LoBoGamesEngine
{
public:
    int repetitions;
    bool jumpEnabled;
    bool finished;

    // Overwrite class constructors for
    // using default initial setup and/or Jump setting
    TapatanGame(vector<TapatanPlayer*> players, TapatanBoard board, bool jumpEnabled);
    TapatanGame(vector<TapatanPlayer*> players, bool jumpEnabled);
    TapatanGame(vector<TapatanPlayer*> players, TapatanBoard board);
    TapatanGame(vector<TapatanPlayer*> players);

    void registerMovement(TapatanBoard newSetup);

private:
    int maxRepetitions = 3;

};

class TapatanBoard : public Board
{
public:

    // Overwrite class constructor for
    // using default initial setup
    TapatanBoard();
    TapatanBoard(BoardCoordinates boardSetup);

    // Print function for showing
    // the board in the terminal
    void representation();

    // Read board positions and check
    // whether game is over or not
    // and if it is, returns the winner
    string evaluate();

private:

    // Here we define the default initial condition
    // of the game, that will be used in
    // Initialization without
    // board specification
    BoardCoordinates initialPositions = {
            {'2', '1', '2'},
            {'0', '0', '0'},
            {'1', '2', '1'}
    };

};

#endif //LOBO_BRAIN_TAPATAN_H
