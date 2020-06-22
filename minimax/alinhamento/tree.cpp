#include <iostream>
#include <vector>
#include "tree.hpp"
#include "tabuleiro.hpp"
#include "move.hpp"
#include "node.hpp"
#include "decision.hpp"

using namespace std;

//Metodo construtor da arvore
Tree::Tree(Tabuleiro startingBoard)
{
    Node* rootNode = new Node(startingBoard);
    this->setRoot(rootNode);
}
//Metodo setter da arvore
void Tree::setRoot(Node* root)
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

vector<Tabuleiro> Tree::generateBoards(Tabuleiro board, char player, bool jump)
{
    int i,j, player_pos;
    vector<vector<int>> possible_mov;//matriz com as possiveis posicoes geradas a partir do tabuleiro passado como parametro

    vector<vector<int>> aux_vet;

    vector<Tabuleiro> possibleBoards;//vetor com os possiveis tabuleiros gerados a partir da posicao atual

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board.posicoes[i][j] == player)//verifica se a posicao do tabuleiro esta sendo ocupada pelo jogador
            {
                player_pos = 3*i+j;//realiza uma aritmetica para determinar a posicao do jogador no tabuleiro


                // TODO: SWITCH DE ACORDO COM O JOGO USANDO CÓDIGOS PRé DEFINIDOS
                possible_mov = tapatanMoves(player_pos);
                if(jump) {
                  aux_vet = tapatanJumpMoves(player_pos, board);
                  possible_mov.insert(possible_mov.end(), aux_vet.begin(), aux_vet.end());
                }

                for(vector<vector<int>>::iterator it = possible_mov.begin(); it != possible_mov.end(); it++)//varre todas as posicoes do tabuleiro
                {
                    if(board.posicoes[it->at(0)][it->at(1)] == '0')//verifica se a posicao do tabuleiro esta vazia para poder realizar a possivel movimentacao
                    {
                        //gambiarra fodida pois n sei cpp quem quiser melhorar pode dale
                        Tabuleiro newBoard = board;
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