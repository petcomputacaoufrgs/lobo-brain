#ifndef TAPATAN_H
#define TAPATAN_H

#include "../LoBoBrain.hpp"
#include "../LoBoBrain/player.hpp"
#include "../LoBoBrain/board.hpp"
#include "../Agents/MiniMaxAgent.hpp"

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
    explicit TapatanPlayer(LoBoGamesEngine* gameEngine);
    TapatanPlayer(LoBoGamesEngine* gameEngine, char symbol, string name);

    int score;
    void update();

protected:
    void updatePossibleMoves();
    void updatePieces();
};

class TapatanBoard : public Board
{
public:

    // Overwrite class constructor for
    // using default initial setup
    TapatanBoard();

    explicit TapatanBoard(const BoardCoordinates& boardSetup);

    string updateSetup(BoardCoordinates newBoardSetup) override;

    // Getter for board positions
    BoardCoordinates getSetup() override;

    // Print function for showing
    // the board in terminal
    static void representation();

    // Read board positions and check
    // whether game is over or not
    // and if it is, returns the winner
    string evaluate();

private:



    // Here we define the default initial condition
    // of the game, that will be used in
    // Initialization without
    // board specification
    BoardCoordinates initialSetup = {
            {'2', '1', '2'},
            {'0', '0', '0'},
            {'1', '2', '1'}
    };

};

class TapatanGame : public LoBoGamesEngine
{
public:
    int repetitions;
    bool jumpEnabled;
    bool finished;

    // Overwrite class constructors for
    // using default initial setup and/or Jump setting
    TapatanGame(vector<Player> players1, Board board, initializer_list<Player> players);
    TapatanGame(vector<TapatanPlayer*> players, bool jumpEnabled);
    TapatanGame(vector<TapatanPlayer*> players, TapatanBoard* board);
    TapatanGame(vector<Player> players1, Board board1, const vector<TapatanPlayer *>& players,
                TapatanBoard *board, bool jumpEnabled);

    void registerMovement(TapatanBoard newSetup);

protected:
    int maxRepetitions = 3;

};

class MiniMaxTapatanAgent : public MiniMaxAgent
{
public:

        /*
         * Build a new layer of the MiniMax tree
         */
        int executeNewLayer(bool isMax, int currentDepth);

        /*
         * Use the current tree to make a decision
         * by the point of view of the current player
         */
        Board play();
};

#endif //TAPATAN_H
