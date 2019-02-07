#include <stdio.h>

typedef struct tabuleiroInicial
{
    char posicaoInicial[3][3];
    int nVezesInicial;
} tabuleiroInicial;

int funcaoVDE(char tab[3][3], char jogador, tabuleiroInicial *t)
{
    int cont = 0;

    //testa empate
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%c %c", tab[i][j], t->posicaoInicial[i][j]);
            if(tab[i][j] == t->posicaoInicial[i][j])
            {
                printf("kk\n");
                cont++;
            }
        }
    }

    if (cont == 9)
    {
        t->nVezesInicial++;
        if (t->nVezesInicial == 3)
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

    return 0;
}


int main()
{
    char tabuleiroTeste[3][3] = {{'0','0','0'},{'0','0','1'},{'0','0','1'}};
    tabuleiroInicial tabini = {{'0','1','0','0','0','1','0','0','1'}, 2};

    if(funcaoVDE(tabuleiroTeste, '1', &tabini) == 0)
    {
        printf("iupi");
    }

    return 0;
}
