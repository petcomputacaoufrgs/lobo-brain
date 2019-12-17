#include <stdio.h>
#include <vector>
#include <string>
#include "tabuleiro.hpp"




/*


ESTA MERDA FUNCIONA

SE FOR ALTERAR FAZ ALGUM BACKUP

CORNO


*/



// OLD MAS SALVO PQ VAI Q NEH
// variavel global para contar
//  quantas vezes chegou a posicao inicial
// int empate = 0;



/***********************************************************************************************
*   funcaoVDE:                                                                                 *
*       - Especificacao:                                                                       *
*           - Verifica se a partir de um determinado tabuleiro passado como entrada,           *
*           houve vitoria, derrota ou empate (VDE) do jogador atual, ou seja, retorna o        *
*           valor heuristico do nodo                                                           *
*       -Entrada:                                                                              *
*           - Recebe como parametro o tabuleiro inicial (da forma que o jogo comecou),         *
*           o tabuleiro atual (como esta o jogo no momento que a funcao eh chamada),           *
*           o jogador atual e o oponente e o numero de repeticoes do tabuleiro inicial         *
*           (para checar possibilidade de empate)                                              *
*       - Saida:                                                                               *
*           - Retorna a pontuacao que o jogador recebe ao empatar, ganhar ou perder com        *
*           o tabuleiro passado                                                                *
*                                                                                              *
*       - Dados importantes:                                                                   *
*           - Retorna:                                                                         *
*               - 0 se o estado nao eh terminal                                                *
*		        - 100 se vitoria                                                               *
*              - -100 se derrota                                                               *
*              - -1 se empate                                                                  *
*                                                                                              *
*                                                                                              *
*       - Observacoes:                                                                         *
*           - Os valores escolhidos para vitoria e derrota                                     *
*           devem ser alterados se a altura da arvore                                          *
*           for muito grande, ou seja, ha um feature na implementacao que                      *
*           gera pesos para a pontuacao de acordo com a altura da arvore. Dessa forma,         *
*           quanto maior a altura da arvore, quer dizer que mais jogadas sao necessarias       *
*           para chegar em um determinado nodo, logo deve ocorrer uma diminuicao dessa         *
*           da pontuacao desse ramo.                                                           *
*                                                                                              *
*      - Mudancas importantes:                                                                 *
*           - Incrementava a variavel 'empate' caso ocorresse empate                           * 
************************************************************************************************/

int funcaoVDE(Tabuleiro tab, Tabuleiro tab_ini, char jogador, char oponente, int *repeticoes_inicial)
{
    int cont = 0;

    //testa empate
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {

            if(tab.posicoes[i][j] == tab_ini.posicoes[i][j])
            {
                cont++;
            }
        }
    }

// o hummes é corno

    // Tabuleiro igual ao do comeco -> empate
    if (cont == 9)
    {
        (*repeticoes_inicial)++;
        if (*repeticoes_inicial == 3) {
            return -1;
        }
    }


    //testa vitoria
    if (tab.posicoes[0][0] == jogador)
    {
      if (tab.posicoes[0][1] == jogador && tab.posicoes[0][2] == jogador ||
            tab.posicoes[1][0] == jogador && tab.posicoes[2][0] == jogador ||
            tab.posicoes[1][1] == jogador && tab.posicoes[2][2] == jogador)
        {
            return 100;
        }
    }
    else if (tab.posicoes[0][2] == jogador)
    {
        if (tab.posicoes[1][1] == jogador && tab.posicoes[2][0] == jogador ||
            tab.posicoes[1][2] == jogador && tab.posicoes[2][2] == jogador)
        {
            return 100;
        }
    }
    else if (tab.posicoes[1][1] == jogador && tab.posicoes[1][2] == jogador ||
            tab.posicoes[1][0] == jogador && tab.posicoes[1][2] == jogador)
    {
        return 100;
    }
    else if (tab.posicoes[2][0] == jogador && tab.posicoes[2][1] == jogador && tab.posicoes[2][2] == jogador)
    {
        return 100;
    }
	
	//testa derrota
	if (tab.posicoes[0][0] == oponente)
    {
      if (tab.posicoes[0][1] == oponente && tab.posicoes[0][2] == oponente ||
            tab.posicoes[1][0] == oponente && tab.posicoes[2][0] == oponente ||
            tab.posicoes[1][1] == oponente && tab.posicoes[2][2] == oponente)
        {
            return -100;
        }
    }
    else if (tab.posicoes[0][2] == oponente)
    {
        if (tab.posicoes[1][1] == oponente && tab.posicoes[2][0] == oponente ||
            tab.posicoes[1][2] == oponente && tab.posicoes[2][2] == oponente)
        {
            return -100;
        }
    }
    else if (tab.posicoes[1][1] == oponente && tab.posicoes[1][2] == oponente ||
                tab.posicoes[1][0] == oponente && tab.posicoes[1][2] == oponente)
    {
        return -100;
    }
    else if (tab.posicoes[2][0] == oponente && tab.posicoes[2][1] == oponente && tab.posicoes[2][2] == oponente)
    {
        return -100;
    }

    return 0;
}



// Main reservada à testes da função VDE, comentar se não for o caso
int main()
{

    // Tabuleiros para testes da função VDE
    Tabuleiro t1 ({ {'1','0','2'},
                    {'2','1','0'},
                    {'2','0','1'}   });
                    
	Tabuleiro t2 ({ {'0','0','2'},
                    {'0','0','2'},
                    {'0','0','2'}   });

    Tabuleiro t3 ({ {'2','1','2'},
                    {'2','1','2'},
                    {'1','2','1'}   });

    // Tabuleiro inicial, base de comparacao para empate
    Tabuleiro tini ({   {'2', '1', '2'},
                        {'0', '0', '0'},
                        {'1', '2', '1'}     });

    // Armazena o numero de vezes que o tabuleiro esteve na posicao inicial
	int nIni = 1;

    printf("--->\t%d\n", funcaoVDE(t1, tini, '1', '2', &nIni));
    printf("--->\t%d\n", funcaoVDE(t1, tini, '2', '1', &nIni));
	printf("--->\t%d\n", funcaoVDE(t2, tini, '1', '2', &nIni));
    printf("--->\t%d\n", funcaoVDE(t2, tini, '2', '1', &nIni));
    printf("--->\t%d\n", funcaoVDE(t3, tini, '2', '1', &nIni));

    return 0;
}
