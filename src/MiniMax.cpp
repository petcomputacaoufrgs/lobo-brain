#include "MiniMax.hpp"

using namespace std;

MiniMax::MiniMax(Board startingBoard)
{
    // Dynamic alloc for tree
    this->Tree = new MiniMaxTree(startingBoard);
}

MiniMax::MiniMax(Board startingBoard, int maxDepth)
{
    // Dynamic alloc for tree
    this->Tree = new MiniMaxTree(startingBoard);

    this.maxDepth = maxDepth;
}



int MiniMax::execute(MiniMaxNode currentNode, Player minPlayer, Player maxPlayer, int currentDepth)
{

    if(currentDepth >= this.maxDepth) {

        /*
         * This is the last layer, the Node here will have
         * a
         */

        currentNode.value += currentDepth;
        return currentNode.value;
    }

    // Valoração do tabuleiro atual
    int score = tapatanEvaluation(current_state->board, game->root->board, '1', '2', rep);


    /* CASOS TERMINAIS */


    // Ganhou
    if(score == 100) {
        current_state->value = score - depth;
        return current_state->value;
    }

    // Perdeu
    if(score == -100) {
        current_state->value = score + depth;
        return current_state->value;
    }

    // Nem quem ganhar vai perder e nem quem perder vai ganhar
    if(empate(*rep)) {
        current_state->value = 0;
        return current_state->value;
    }
    // Atingiu a profundidade máxima



    /* CASOS NÃO TERMINAIS */


    if(isMax) {


        /* MAXIMIZING */


        int best = alpha;

        // Gera as opossiveis jogadas a partir do estado atual do jogo
        game->generateChildren(current_state, '1', jump);

        // Varre todos os filhos (tabuleiros) gerados
        for(int i = 0; i < current_state->children.size(); i++){

            int possible_choice = minimax(game, current_state->children[i], jump,
                                          alpha, beta, rep, !isMax, depth + 1, max_depth);

            // Encontra o melhor valor heuristico ate o estado atual do jogo
            best = max(best, possible_choice);
            alpha = max(alpha, best);

            // Alpha-Beta prunning
            if(alpha >= beta)
                return best;	// Beta cut-off
        }	//Fim das recursoes

        // Retorna o valor heuristico da melhor jogada
        return best;

    }else{


        /* MINIMIZING */


        int best = beta;

        // Popula toda a arvore de possibilidades
        game->generateChildren(current_state, '2', jump);

        // Varre filhos do nodo atual, na procura da batida perfeita
        for(int i = 0; i < current_state->children.size(); i++){

            // Recursao, comecando pela esquerda dps filhos e incrementando profundidade
            int possible_choice = minimax(game, current_state->children[i], jump,
                                          alpha, beta, rep, !isMax, depth + 1, max_depth);

            // Verifica se o resultado da recursao foi melhor do que aquele que se tem
            best = min(best, possible_choice);
            beta = min(beta, best);

            // Alpha-Beta prunning
            if(alpha >= beta)
                return best;	// Alpha cut-off
        } // Fim das recursoes

        // Retorna o valor heuristico da melhor jogada
        return best;
    }
}


Board MiniMax::playAs(Player player)
{
    // Variables to keep track
    // of the best possible choice
    int bestChoiceScore;
    MiniMaxNode* bestChoiceNode;

    MiniMaxNode* root = new MiniMaxNode(this.currentSetup);

    // Gera as possiveis jogadas a partir do estado atual do jogo
    this->tree->generateChildren(root, player.symbol);

    // Varre todas as possiveis jogadas selecionando a melhor delas
    for(int i=0; i<current_state->children.size(); i++){

        // Encontra a melhor jogada atraves do retorno do valor heuristico
        currentChoice = minimax(game, current_state->children[i], jump,
                                alpha, beta, rep, false, 1, max_depth);

        // Verifica se é a melhor jogada a ser realizada
        if (currentChoice > alpha){
            alpha = currentChoice;
            bestChoice = current_state->children[i];
            bestChoice->value = alpha;
        }

    }

    // retornar a jogada escolhida
    return bestChoice;
}