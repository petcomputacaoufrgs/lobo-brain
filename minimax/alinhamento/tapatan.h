//
// Created by phi on 13/08/2021.
//

#ifndef LOBO_BRAIN_TAPATAN_H
#define LOBO_BRAIN_TAPATAN_H

#include "LoBoBrain.hpp"
#include <vector>

typedef vector<vector<char>> BoardCoordinates;
typedef pair<int, int> PieceCoordinates;
typedef pair<PieceCoordinates, PieceCoordinates> Movement;
typedef pair<BoardCoordinates, BoardCoordinates> BoardMovement;

using namespace std;

class TapatanBoard : public Board
{
public:

    // Overwrite class constructor for
    // using default inital setup
    TapatanBoard();
    TapatanBoard(Board board);

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
    void updatePossibleMoves(BoardCoordinates currentBoard, bool jumpEnabled);
    void updatePieces();

private:
    vector<BoardCoordinates> possibleMoves;
    vector<PieceCoordinates> pieces;
};

class TapatanGame : public LoBoGamesEngine
{
public:
    int repetitions;
    bool finished;

    // Overwrite class constructors for
    // using default initial setup and/or Jump setting
    TapatanGame(vector<TapatanPlayer*> players, Board board, bool jumpEnabled);
    TapatanGame(vector<TapatanPlayer*> players, bool jumpEnabled);
    TapatanGame(vector<TapatanPlayer*> players, Board board);
    TapatanGame(vector<TapatanPlayer*> players);

private:
    bool jumpEnabled;
    int maxRepetitions = 3;

};

#endif //LOBO_BRAIN_TAPATAN_H
