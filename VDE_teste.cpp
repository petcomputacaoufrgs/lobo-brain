#include <stdio.h>
#include <vector>
#include <string>
#include "tabuleiro.hpp"
#include "VDE.hpp"

using namespace std;

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


    //mudar para cout
    printf("--->\t%d\n", funcaoVDE(t1, tini, '1', '2', &nIni));
    printf("--->\t%d\n", funcaoVDE(t1, tini, '2', '1', &nIni));
	printf("--->\t%d\n", funcaoVDE(t2, tini, '1', '2', &nIni));
    printf("--->\t%d\n", funcaoVDE(t2, tini, '2', '1', &nIni));
    printf("--->\t%d\n", funcaoVDE(t3, tini, '2', '1', &nIni));

    return 0;
}