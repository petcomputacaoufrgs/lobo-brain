#ifndef TAPATAN_RULES_H
#define TAPATAN_RULES_H

#include <vector>
#include "player.hpp"
#include "board.hpp"

using namespace std;



class Game
{

private:
    bool finished;
    TapatanPlayer playing;
    int repetitions;
    bool jumpEnabled;

public:

    // Class constructor
    Game(vector<TapatanPlayer> players, bool jumpEnable);


    void move(BoardCoordinates toBoard);

    int winner(int *rep);//verifica se o jogo houve vencedor, empatou, ou nao terminou

    BoardCoordinates availablePositions();//verifica as possiveis posicoes para jogar. retorna um vetor de tuplas

    vector<Board> possibleBoards(bool jump);// gera os possiveis tabuleiros de movimentacao de determinada peca

    void reset();//reseta todos atributos da classe State

    bool isFinished();
};





#endif //TAPATAN_RULES_H
