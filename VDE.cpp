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




/* Retorna 0 se o estado nao eh terminal
 *		   100 se vitoria 
 *         -100 se derrota
 *         -1 se empate
 *         OLD: incrementa a var "empate" se empate

    os valores escolhidos para vitoria e derrota
    devem ser alterados se a altura da arvore
    for muito grande


 */


//typedef struct tabuleiroInicial
//{
//    char posicaoInicial[3][3];
//    int  nVezesInicial; 
//} tabuleiroInicial;            ANTIGA

//a funcao VDE tbm serve como teste para se o estado eh terminal (!= 0)
//mudando tipo do tabuleiro por compatibilidade com o resto 


//int funcaoVDE(char tab[3][3], char jogador, char oponente, tabuleiroInicial *t) ANTIGA
int funcaoVDE(Tabuleiro tab, Tabuleiro tab_ini, char jogador, char oponente, int *repeticoes_inicial)
{   //VITORIA --> 2 EMPATE --> 1 DERROTA --> -1 NDA --> 0
    int cont = 0;

    //testa empateo
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
      if (tab.posicoes[0][1] == jogador && tab.posicoes[0][2] == jogador || tab.posicoes[1][0] == jogador && tab.posicoes[2][0] == jogador || tab.posicoes[1][1] == jogador && tab.posicoes[2][2] == jogador)
        {
            return 100;
        }
    }
    else if (tab.posicoes[0][2] == jogador)
    {
        if (tab.posicoes[1][1] == jogador && tab.posicoes[2][0] == jogador || tab.posicoes[1][2] == jogador && tab.posicoes[2][2] == jogador)
        {
            return 100;
        }
    }
    else if (tab.posicoes[1][1] == jogador && tab.posicoes[1][2] == jogador || tab.posicoes[1][0] == jogador && tab.posicoes[1][2] == jogador)
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
      if (tab.posicoes[0][1] == oponente && tab.posicoes[0][2] == oponente || tab.posicoes[1][0] == oponente && tab.posicoes[2][0] == oponente || tab.posicoes[1][1] == oponente && tab.posicoes[2][2] == oponente)
        {
            return -100;
        }
    }
    else if (tab.posicoes[0][2] == oponente)
    {
        if (tab.posicoes[1][1] == oponente && tab.posicoes[2][0] == oponente || tab.posicoes[1][2] == oponente && tab.posicoes[2][2] == oponente)
        {
            return -100;
        }
    }
    else if (tab.posicoes[1][1] == oponente && tab.posicoes[1][2] == oponente || tab.posicoes[1][0] == oponente && tab.posicoes[1][2] == oponente)
    {
        return -100;
    }
    else if (tab.posicoes[2][0] == oponente && tab.posicoes[2][1] == oponente && tab.posicoes[2][2] == oponente)
    {
        return -100;
    }

    return 0;
}


int main()
{
    Tabuleiro t1 ({ {'1','0','2'},
                    {'2','1','0'},
                    {'2','0','1'}   });
	Tabuleiro t2 ({ {'0','0','2'},
                    {'0','0','2'},
                    {'0','0','2'}   });

    Tabuleiro t3 ({ {'2','1','2'},
                    {'2','1','2'},
                    {'1','2','1'}   });

    Tabuleiro tini ({   {'2', '1', '2'},
                        {'0', '0', '0'},
                        {'1', '2', '1'}     });

	int nIni = 1;

    printf("--->\t%d\n", funcaoVDE(t1, tini, '1', '2', &nIni));
    printf("--->\t%d\n", funcaoVDE(t1, tini, '2', '1', &nIni));
	printf("--->\t%d\n", funcaoVDE(t2, tini, '1', '2', &nIni));
    printf("--->\t%d\n", funcaoVDE(t2, tini, '2', '1', &nIni));
    printf("--->\t%d\n", funcaoVDE(t3, tini, '2', '1', &nIni));

    return 0;
}
