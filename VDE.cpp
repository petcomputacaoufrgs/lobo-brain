#include <stdio.h>
#include <vector>
#include <string> 

/* Retorna 0 se o estado nao eh terminal
 *         1 se empate
 *		   2 se vitoria 
 *        -1 se derrota
 */


//typedef struct tabuleiroInicial
//{
//    char posicaoInicial[3][3];
//    int  nVezesInicial; 
//} tabuleiroInicial;            ANTIGA

//a funcao VDE tbm serve como teste para se o estado eh terminal (!= 0)
//mudando tipo do tabuleiro por compatibilidade com o resto 


//int funcaoVDE(char tab[3][3], char jogador, char oponente, tabuleiroInicial *t) ANTIGA
int funcaoVDE(std::vector<std::string> tab, std::vector<std::string> tab_ini, char jogador, char oponente, int *repeticoes_inicial)
{   //VITORIA --> 2 EMPATE --> 1 DERROTA --> -1 NDA --> 0
    int cont = 0;

    //testa empateo
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            //printf("%c %c", tab[i][j], tab_ini[i][j]);
            if(tab[i][j] == tab_ini[i][j])
            {
                //printf("kk\n");
                cont++;
            }
        }
    }

// o hummes é corno

    if (cont == 9)
    {
        (*repeticoes_inicial)++;
        if (*repeticoes_inicial == 3)
            return 1;
    }


    //testa vitoria
    if (tab[0][0] == jogador)
    {
      if (tab[0][1] == jogador && tab[0][2] == jogador || tab[1][0] == jogador && tab[2][0] == jogador || tab[1][1] == jogador && tab [2][2] == jogador)
        {
            return 2;
        }
    }
    else if (tab[0][2] == jogador)
    {
        if (tab[1][1] == jogador && tab[2][0] == jogador || tab[1][2] == jogador && tab[2][2] == jogador)
        {
            return 2;
        }
    }
    else if (tab[1][1] == jogador && tab[1][2] == jogador || tab[1][0] == jogador && tab[1][2] == jogador)
    {
        return 2;
    }
    else if (tab[2][0] == jogador && tab[2][1] == jogador && tab[2][2] == jogador)
    {
        return 2;
    }
	
	//testa derrota
	if (tab[0][0] == oponente)
    {
      if (tab[0][1] == oponente && tab[0][2] == oponente || tab[1][0] == oponente && tab[2][0] == oponente || tab[1][1] == oponente && tab [2][2] == oponente)
        {
            return -1;
        }
    }
    else if (tab[0][2] == oponente)
    {
        if (tab[1][1] == oponente && tab[2][0] == oponente || tab[1][2] == oponente && tab[2][2] == oponente)
        {
            return -1;
        }
    }
    else if (tab[1][1] == oponente && tab[1][2] == oponente || tab[1][0] == oponente && tab[1][2] == oponente)
    {
        return -1;
    }
    else if (tab[2][0] == oponente && tab[2][1] == oponente && tab[2][2] == oponente)
    {
        return -1;
    }

    return 0;
}


/*int main()
{
//   char t1[3][3] = {{'1','0','0'},{'0','1','0'},{'0','0','1'}};
//	char t2[3][3] = {{'0','0','2'},{'0','0','2'},{'0','0','2'}};
//	char t3[3][3] = {'0','1','0','0','0','1','0','0','1'};
	std::string s00("100"), s01("010"), s02("001"),
	            s10("010"), s11("001"), s12("001"); 
	
	std::vector<std::string> v0;
	std::vector<std::string> v1;
	
	v0.push_back(s00); v0.push_back(s01); v0.push_back(s02);
	v1.push_back(s10); v1.push_back(s11); v1.push_back(s12);
	
	int nIni = 1;

    printf("--->%d\n", funcaoVDE(v0, v1, '1', '2', &nIni));
    printf("--->%d\n", funcaoVDE(v0, v1, '2', '1', &nIni));
	printf("--->%d\n", funcaoVDE(v1, v1, '1', '2', &nIni));
    printf("--->%d\n", funcaoVDE(v1, v1, '1', '2', &nIni));

    return 0;
}*/
