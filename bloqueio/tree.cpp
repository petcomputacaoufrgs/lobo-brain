#include <iostream>
#include <vector>
#include "tree.hpp"
#include "move.hpp"
#include "node.hpp"
#include "decision.hpp"
#include "vertex.hpp"
#include "tabuleiro.hpp"

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
*   setCurrentBoard:                                                                      *
*       - Especificacao:                                                                 *
*           - Gera um novo grafo - que sera o novo tabuleiro gerado - a partir de um     *
*           estado de jogo atual. Isso depende do jogo que esta sendo rodado, logo,      *
*           antes de gerar o o tabuleiro corrente, eh necessario verificar qual é o jogo *
*           adotado no momento da chamada da funcao.                                     *
*                                                                                        *
*       - Entardas:                                                                      *
*           - Recebe como entrada um tabuleiro (estado atual do jogo), o jogador atual   *
*           o jogador adversario, a posicao que o jogador está e para onde ele vai se    *
*           movimentar, um vetor que contém todas as possicoes atuais do jogador e um    *
*           vetor que contém todas as posicoes atuais do adversario                      *
*       - Saida:                                                                         *
*           - Retorna um tabuleiro, ou seja um ponteiro para a posicao 0 da lista de     *
*           adjacencia do grafo                                                          *
*                                                                                        *                                        *
******************************************************************************************/
Tabuleiro setCurrentBoard(char player, char enemy, int from, int to, vector<int> playerPos, vector<int> enemyPos){

  // TODO: vai ter que ter um switch nesta caceta
  Tabuleiro currentBoard = pongHauKiBoard();//inicializa um novo tabuleiro
  Vertex* aux = currentBoard.firstPos;// inicializa um auxiliar como o
  // ponteiro para a primeira posicao do tabuleiro passado como parametro

  // percorre toda a lista de adjacencia
  while(aux != NULL){
    // percorre toda a lista das posicoes atuais do jogador, 
    // juntamente com as posicoes atuais do adversario
    for(int i = 0; i < playerPos.size(); i++) {
      if(aux->pos == playerPos[i]) {// verifica se a posicao esta sendo ocupada pelo jogador
        aux->player = player;
      }
      else if(aux->pos == enemyPos[i]) {// verifica se a posicao esta sendo ocupada pelo adversario
        aux->player = enemy;
      }

    }
    aux = aux->next;
  }

  aux = search(currentBoard, from);

  aux->player = '0';

  aux = search(currentBoard, to);

  aux->player = player;

  return currentBoard;

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


// EM CONSTRUCAO         AAAAAA
vector<Tabuleiro> Tree::generateBoards(Tabuleiro board, char player, char enemy)
{
    vector<int> possible_mov;//matriz com as possiveis posicoes geradas a partir do tabuleiro passado como parametro
    vector<Tabuleiro> possibleBoards;//vetor com os possiveis tabuleiros gerados a partir da posicao atual
    vector<int> player_pos;
    vector<int> enemy_pos;


    // varre o grafo em busca dos player pra adicionar as posicao deles no vector
    Vertex* pos_aux = board.firstPos;
    while(pos_aux != NULL){// varre toda a lista de adjacencia
      if(pos_aux->player == player){// verifica se a posicao esta sendo ocupada pelo jogador
        player_pos.push_back(pos_aux->pos);
      }else if(pos_aux->player == enemy){// verifica se a posicao esta sendo ocupada pelo adversario
        enemy_pos.push_back(pos_aux->pos);
      }

    }

    // varre todo grafo de nuebo pra gerar os tab novo
    Vertex* pos_aux = board.firstPos;
    while(pos_aux != NULL) {// varre toda lista de adjacencia

      if(pos_aux->player == player) {// verifica se a posicao esta sendo ocupada pelo jogador

        possible_mov = searchFreeNeighbours(pos_aux);// verifica as possiveis movimentacoes do jogador

        for(vector<int>::iterator it = possible_mov.begin(); it != possible_mov.end(); it++) {// varre a lista com as posicoes das possiveis jogadas

          Tabuleiro newBoard = setCurrentBoard(player, enemy, pos_aux->pos, *it, player_pos, enemy_pos); // gera um novo tabuleiro a partir da nova movimentacao
          possibleBoards.push_back(newBoard); // adiciona o novo tabuleiro na arvore

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
void Tree::generateChildren(Node* current_state, char player)
{
    vector<Tabuleiro> possibleBoards;
    Node* newChild;
    Tabuleiro board;

    //Gera os possiveis tabuleiros a partir da posicao corrente (jogadas do player)
    possibleBoards = this->generateBoards(current_state->board, player);

    //Adiciona os filhos (Node que contthisem board) no respectivo Node pai
    for (vector<Tabuleiro>::iterator it = possibleBoards.begin(); it != possibleBoards.end(); it++)
    {
        newChild = new Node(*it);
        current_state->addChildren(newChild);
    }
}
