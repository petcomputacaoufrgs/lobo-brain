#include "tabuleiro.hpp"
#include "vertex.hpp"

using namespace std;

/**************************************************
*	Estrutura tabuleiro:                          *
* 		-Armazena um vetor de vetor de char       *
* 		que representa as posicoes do tabuleiro   *
*                                                 *
* 		- Uso:                                    *
*			- Tabuleiro exemplo (<vetor>);        *
*                                                 *
***************************************************/



// 0            3
// |  >  2  <   |
// 1 ---------- 4

// Construtor
Tabuleiro::Tabuleiro(Vertex *firstPos, int size)
{
	this->firstPos = firstPos;
	this->size = size;
}

// Construtor
Tabuleiro::Tabuleiro()
{

}

// Funcao de busca para a lista de adjacencia
Vertex* Tabuleiro::search(int pos) {

	Vertex* aux = this->firstPos;

	while(this->firstPos != NULL) {
		if(aux->pos == pos)
			return aux;
		else
			aux = aux->next;
	}
	return NULL;
}


// Gera um novo tabuleiro completamente vazio, apenas com a estrutura do Pong Hsu K'i
Tabuleiro pongHauKiBoard(){

	Vertex* pos0 = new Vertex(0, '0');
	Vertex* pos1 = new Vertex(1, '0');
	Vertex* pos2 = new Vertex(2, '0');
	Vertex* pos3 = new Vertex(3, '0');
	Vertex* pos4 = new Vertex(4, '0');

	Tabuleiro board (pos0, 5);

	pos0->addNeighbour(pos1);
	pos0->addNeighbour(pos2);
	pos0->addVertex(pos1);
	pos1->addNeighbour(pos0);
	pos1->addNeighbour(pos2);
	pos1->addNeighbour(pos4);
	pos1->addVertex(pos2);
	pos2->addNeighbour(pos0);
	pos2->addNeighbour(pos1);
	pos2->addNeighbour(pos3);
	pos2->addNeighbour(pos4);
	pos2->addVertex(pos3);
	pos3->addNeighbour(pos2);
	pos3->addNeighbour(pos4);
	pos3->addVertex(pos4);
	pos4->addNeighbour(pos1);
	pos4->addNeighbour(pos2);
	pos4->addNeighbour(pos3);

	return board;

}


// Recebe um tabuleiro ~vazio~ e seta as posições iniciais do jogo
void Tabuleiro::pongHauKiInitialPositions() {

	Vertex* aux = this->firstPos;

	for(int i = 0; i < 5; i++) {

		switch (i)
		{
		case 0:
				aux->player = '1';
				aux = aux->next;
			break;

		case 1:
				aux->player = '2';
				aux = aux->next;
			break;

		case 2:
				aux->player = '0';
				aux = aux->next;
			break;

		case 3:
				aux->player = '2';
				aux = aux->next;
			break;

		case 4:
				aux->player = '1';
				aux = aux->next;
			break;

		default:
			break;
		}

	}

}

void Tabuleiro::print() {

	if(this != NULL && this->firstPos != NULL) {

		Vertex* aux = this->firstPos;

		for(int i = 0; i < this->size; i++) {

			cout << "\n\tTAB --> " << aux->pos << ": '" << aux->player << "' ";
			aux = aux->next;

		}

	}
	return;
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
*                                                                                        *
*				- Observaçoes:                                                                   *
*           - Podemos mais alem buscar novas otimizacoes para funcoes deste tipo         *
******************************************************************************************/
void Tabuleiro::setCurrentBoard(char player, char enemy, int from, int to, vector<int> playerPos, vector<int> enemyPos){

  // TODO: vai ter que ter um switch nesta caceta
  Vertex* aux = this->firstPos;// inicializa um auxiliar como o
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

  aux = this->search(from);

  aux->player = '0';

  aux = this->search(to);

  aux->player = player;

  return;
}


bool Tabuleiro::operator == (const Tabuleiro & board) {

	Vertex* aux_this = this->firstPos;
	Vertex* aux_board = board.firstPos;

	// ^ = xor
	if(aux_this == NULL ^ aux_board == NULL)
			return false;

	while(aux_this != NULL && aux_board != NULL){

		if(aux_this->player != aux_board->player)
				return false;

		aux_this = aux_this->next;
		aux_board = aux_board->next;
	}

	return true;

}
