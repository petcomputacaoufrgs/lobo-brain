#include <iostream>
#include <vector>
#include "minimaxTree.hpp"
#include "board.hpp"
#include "move.hpp"
#include "minimaxNode.hpp"
#include "decision.hpp"

using namespace std;


minimaxTree::minimaxTree(Board startingBoard)
{
    Node* rootNode = new Node(startingBoard);
    this->setRoot(rootNode);
}


void minimaxTree::setRoot(Node* root)
{
    this->root = root;
}

/*****************************************************************************************
*   generateBoards:                                                                      *
*       - Especificacao:                                                                 *
*           - Gera os possiveis tabuleiros (jogadas) a partir de um tabuleiro            *
*           atual dado,*ou seja, gera as possiveis jogadas que a maquina                 *
*           pode fazer a partir de um estado de jogo                                     *
*                                                                                        *
*       - Entardas:                                                                      *
*           - Recebe como entrada um tabuleiro (estado atual do jogo) e o jogador atual  *
*       - Saida:                                                                         *
*           - Retorna um ponteiro para a raiz de um                                      *
*           conjunto de possiveis tabuleiros gerados                                     *
*                                                                                        *
*       - Dados importantes:                                                             *
*           - passa a posicao (de 0 a 8 no tapatan) do jogador analisado e,              *
*           no move.cpp ve os movimentos possiveis a partir daquela posicao              *
*           - move.cpp devolve uma lista de duplas (i,j) de cada posicao atual           *
*           e aqui na generate a gente verifica quais movimentos sao possiveis           *
*           e adiciona no vetor a ser devolvido                                          *
******************************************************************************************/

vector<Board> minimaxTree::produceNextLayerBoards(Board originalBoard, Player player, bool jump)
{
    vector<vector<int>> possibleMov;//matriz com as possiveis posicoes geradas a partir do tabuleiro passado como parametro

    vector<vector<int>> auxVector;

    vector<Board> possibleBoards;//vetor com os possiveis tabuleiros gerados a partir da posicao atual

    /*
     *
     *
     * Here we will iterate over all the board positions
     * searching for the Player pieces
     *
     *
     */

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(originalBoard.playersPositions[i][j] == player)//verifica se a posicao do tabuleiro esta sendo ocupada pelo jogador
            {
                playerPos = 3*i+j;//realiza uma aritmetica para determinar a posicao do jogador no tabuleiro


                // TODO: SWITCH DE ACORDO COM O JOGO USANDO CÓDIGOS PRé DEFINIDOS
                possibleMov = tapatanMoves(playerPos);

                if(jump) {
                  auxVector = tapatanJumpMoves(playerPos, originalBoard);
                  possibleMov.insert(possibleMov.end(), auxVector.begin(), auxVector.end());
                }

                for(vector<vector<int>>::iterator it = possibleMov.begin(); it != possibleMov.end(); it++)//varre todas as posicoes do tabuleiro
                {
                    if(originalBoard.playersPositions[it->at(0)][it->at(1)] == '0')//verifica se a posicao do tabuleiro esta vazia para poder realizar a possivel movimentacao
                    {
                        //
                        Board newBoard = originalBoard;
                        newBoard.posicoes[it->at(0)][it->at(1)] = player;//gera um possivel tabuleiro com a possivel movimentacao a partir da posicao atual do jogo
                        newBoard.posicoes[i][j] = '0';//quer dizer que o jogador se movimentou, ou seja, tem que zerar a posicao anterior dele

                        possibleBoards.push_back(newBoard);
                    }

                }
            }
        }
    }

    return possibleBoards;
}





/*****************************************************************************************
*   generateChildren:                                                                    *
*       - Especificacao: a partir de um estado atual de jogo e um jogador,               *
*       gera todos os possiveis tabuleiros a partir dop estado dado.                     *
*                                                                                        *
*       - Entrada: recebe como parametro o estado atual do jogo(nodo que contem o board) *
*       e o jogador o qual se deve gerar as possiveis jogadas                            *
*                                                                                        *
*       - Observacao:                                                                    *
*           - Os nodos filhos sao alocados dinamicamente na memoria, por isso é void     *
******************************************************************************************/
void Tree::generateChildren(Node* current_state, char player, bool jump)
{
    vector<Tabuleiro> possibleBoards;
    Node* newChild;
    Tabuleiro board;

    //Gera os possiveis tabuleiros a partir da posicao corrente (jogadas do player)
    possibleBoards = this->generateBoards(current_state->board, player, jump);

    //Adiciona os filhos (Node que contem board) no respectivo Node pai
    for (vector<Tabuleiro>::iterator it = possibleBoards.begin(); it != possibleBoards.end(); it++)
    {
        newChild = new Node(*it);
        current_state->addChildren(newChild);
    }
}

void Tree::free() {
    this->root->free();
}