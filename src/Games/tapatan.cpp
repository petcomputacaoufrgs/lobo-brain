#include "tapatan.hpp"

using namespace std;

/*
 * =========================
 *     TAPATAN BOARD
 * =========================
 */
TapatanBoard::TapatanBoard() {
    this.updateSetup(this.initialSetup);
}

TapatanBoard::TapatanBoard(BoardCoordinates boardSetup)
{
    this.updateSetup(boardSetup);
}

void TapatanBoard::representation()
{
    for(int i=0; i<3; i++) {
        cout << '\t';
        for(int j=0; j<3; j++) {
            cout << "| " << tab.posicoes[i][j] << " ";
        }
        cout << "|" << endl;
    }

    cout << "\t=============\n\n" << endl ;
}

string TapatanBoard::evaluate()
{

    TapatanGame game = Parent::this;

    BoardCoordinates bc = this.getSetup();
    TapatanPlayer* player_1 = game.players.at(0);
    char p1 = player_1.symbol;
    TapatanPlayer* player_2 = game.players.at(1);
    char p2 = player_2.symbol;

    if (this.setup == this.initialSetup)
    {
            game.repetitions += 1;

            if (game.repetitions >= game.maxRepetitions) {

                player_2.score = -1;
                player_1.score = -1;

                game.finished = true;
                return "Tie"
            }
    }

    // Checking for player 1 victory
    if (bc[0][0] == p1)
    {
        if (bc[0][1] == p1 && bc[0][2] == p1 ||
            bc[1][0] == p1 && bc[2][0] == p1 ||
            bc[1][1] == p1 && bc[2][2] == p1)
        {
            player_1.score = 100;
            player_2.score = -100;

            game.finished = true;
            return player_1.name
        }
    }
    else if (bc[0][2] == p1)
    {
        if (bc[1][1] == p1 && bc[2][0] == p1 ||
            bc[1][2] == p1 && bc[2][2] == p1)
        {
            player_1.score = 100;
            player_2.score = -100;

            game.finished = true;
            return player_1.name
        }
    }
    else if (bc[1][1] == p1)
    {
        if (bc[0][1] == p1 && bc[2][1] == p1 ||
            bc[1][0] == p1 && bc[1][2] == p1)
        {
            player_1.score = 100;
            player_2.score = -100;

            game.finished = true;
            return player_1.name
        }
    }
    else if (bc[2][0] == p1)
    {
        if (bc[2][1] == p1 && bc[2][2] == p1) {
            player_1.score = 100;
            player_2.score = -100;

            game.finished = true;
            return player_1.name
        }
    }

    // Checking for player 2 victory
    if (bc[0][0] == p2)
    {
        if (bc[0][1] == p2 && bc[0][2] == p2 ||
            bc[1][0] == p2 && bc[2][0] == p2 ||
            bc[1][1] == p2 && bc[2][2] == p2)
        {
            player_2.score = 100;
            player_1.score = -100;

            game.finished = true;
            return player_2.name
        }
    }
    else if (bc[0][2] == p2)
    {
        if (bc[1][1] == p2 && bc[2][0] == p2 ||
            bc[1][2] == p2 && bc[2][2] == p2)
        {
            player_2.score = 100;
            player_1.score = -100;

            game.finished = true;
            return player_2.name
        }
    }
    else if (bc[1][1] == p2)
    {
        if (bc[0][1] == p2 && bc[2][1] == p2 ||
            bc[1][0] == p2 && bc[1][2] == p2)
        {
            player_2.score = 100;
            player_1.score = -100;

            game.finished = true;
            return player_2.name
        }
    }
    else if (bc[2][0] == p2)
    {
        if(bc[2][1] == p2 && bc[2][2] == p2) {
            player_2.score = 100;
            player_1.score = -100;

            game.finished = true;
            return player_2.name
        }
    }

    // Game is not finished
    player_1.score = 0;
    player_2.score = 0;

    game.finished = false;
    return NULL;

}

/*
 * =========================
 *     TAPATAN PLAYER
 * =========================
 */
TapatanPlayer::TapatanPlayer()
{

}

void TapatanPlayer::updatePieces()
{
    int i, j;
    vector<PieceCoordinates> playerPieces;

    // Here we iterate over all the
    // board positions to find the
    // pieces of the player
    for(i=0;i<3;i++) {
        for (j = 0; j < 3; j++) {
            if (this.board.getPositions()[i][j] == this.symbol) {
                // found a piece from the player
                playerPieces.push_back(make_pair(i, j));
            }
        }
    }

    this.pieces = playerPieces;
}

void TapatanPlayer::updatePossibleMoves(BoardCoordinates currentBoard, bool jumpEnabled) {

    vector<pair<PieceCoordinates, PieceCoordinates>> possibleMoves;
    vector<PieceCoordinates> playerPieces = this.pieces;


    /*
     *
     * First we will build a vector with
     * all the possible movements can be
     * done with the player's pieces.
     * Then, we will check if the destination
     * position of that movement is free.
     *
     */
    for(int i=0; i<playerPieces.size(); i++) {
        PieceCoordinates piece = playerPieces[i];

        // This variable will hold the position
        // from the piece we're going to move
        PieceCoordinates selectedPiece = make_pair(piece.first, piece.second);


        switch (3*piece.first + piece.second) {
            case 0:

                // Move right .
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(0, 1)));

                // Move down \/
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 0)));

                // Move right and down
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 1)));

                if (jumpEnabled) {
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(2, 2)));
                }

                break;

                //(0,1)
            case 1:
                // Move left <-
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 0)));

                // Move down\/
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 1)));

                // Move right .
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(0, 2)));

                if (jumpEnabled) {
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(2, 1)));
                }

                break;

                //(0,2)
            case 2:
                // Move left <-
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(0, 1)));

                // Move down and left
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 1)));

                // Move down \/
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 2)));

                if (jumpEnabled) {
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(0,0)));
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(2,0)));
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(2,2)));
                }

                break;

                //(1,0)
            case 3:
                // Move up /\ /
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(0, 0)));

                // Move right .
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 1)));

                // Move down \/
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(2, 0)));

                if (jumpEnabled) {
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 2)));
                }

                break;

                //(1,1)
            case 4:
                // Move up and right
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(0, 0)));

                // Move up /\ /
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(0, 1)));

                // Move up and right
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(0, 2)));

                // Move up
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 0)));

                // Move right
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 2)));

                // Move down and left
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(2, 0)));

                // Move down
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(2, 1)));

                // Move down and right
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(2, 2)));

                break;

                //(1,2)
            case 5:
                // Move up
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(0, 2)));

                // Move left
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 1)));

                // Move down
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(2, 2)));

                if (jumpEnabled) {
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 0)));
                }

                break;

                //(2,0)
            case 6:
                // Move right
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(2, 1)));

                // Move up
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 0)));

                // Move up and left
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 1)));

                if (jumpEnabled) {
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(0,0)));
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(2,0)));
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(2,2)));
                }

                break;

                //(2,1)
            case 7:
                // Move left
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(2, 0)));

                // Move up
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 1)));

                // Move right
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(2, 2)));

                if (jumpEnabled) {
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(0, 1)));
                }

                break;

                //(2,2)
            case 8:
                // Move left
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(2, 1)));

                // Move left and up
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 1)));

                // Move up
                possibleMoves.push_back(make_pair(selectedPiece, make_pair(1, 2)));

                if (jumpEnabled) {
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(0,0)));
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(2,0)));
                    possibleMoves.push_back(make_pair(selectedPiece, make_pair(2,2)));
                }

                break;

            default: break;
        }

        // Verify if the target position of the movement is free
        // and then set the possibles
        for (BoardCoordinates::iterator it = possibleMoves.begin();
             it != possibleMoves.end(); it++) {

            PieceCoordinates from = it.first;
            PieceCoordinates to = it.second;

            if (currentBoard[to.first][to.second] == '0') {

                // The movement is valid, lets build the
                // board with this action
                BoardCoordinates possibleBoard = currentBoard;

                // Free the previous position
                possibleBoard[from.first][from.second] = '0';

                // Set the new piece position
                possibleBoard[to.first][to.second] = this.symbol;

                this.possibleMoves.push_back(possibleBoard);
            }

        }
    }
}


/*
 * =========================
 *     TAPATAN GAME
 * =========================
 */
TapatanGame::TapatanGame(vector<TapatanPlayer*> players, Board board)
{
    this.board = TapatanBoard(board);
    this.players = players;


    this.jumpEnabled = false;
}

TapatanGame::TapatanGame(vector<TapatanPlayer> *players, int jumpEnabled)
{
    this.board = TapatanBoard();
    this.players = players;


     this.jumpEnabled = jumpEnabled;
}

TapatanGame::TapatanGame(vector<TapatanPlayer> *players)
{
    this.board = TapatanBoard();
    this.players = players;


    this.jumpEnabled = false;
}

void TapatanGame::registerMovement(Board newSetup)
{
    this.board = newSetup;
    string evalResult = this.board.evaluate(this);

    if (evalResult == "Tie")
    {
        return;
    }

    for(int i=0; i<this.players.size(); i++)
    {
        TapatanPlayer* player = this.players.at(0);

        player.updatePieces();
        player.updatePossibleMoves();
    }

}