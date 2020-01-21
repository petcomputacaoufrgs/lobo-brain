#include <stdio.h>
#include <vector>
#include <string>
#include "tabuleiro.hpp"
#include "evaluations.hpp"

using namespace std;

// Main reservada à testes da função VDE, comentar se não for o caso
int main()
{

    // Tabuleiros para testes da função VDE
    Tabuleiro t1 = pongHauKiBoard();
    t1.pongHauKiInitialPositions();

	   Tabuleiro t2 = pongHauKiBoard();
     t2.pongHauKiInitialPositions();
     t2.firstPos->player = '0';
     t2.firstPos->next->player = '1';
     t2.firstPos->next->next->player = '1';
     t2.firstPos->next->next->next->player = '2';
     t2.firstPos->next->next->next->next->player = '2';
  //
  //   Tabuleiro t3 ({ {'2','1','2'},
  //                   {'2','1','2'},
  //                   {'1','2','1'}   });
  //
  //   // Tabuleiro inicial, base de comparacao para empate
  //   Tabuleiro tini ({   {'2', '1', '2'},
  //                       {'0', '0', '0'},
  //                       {'1', '2', '1'}     });

    // Armazena o numero de vezes que o tabuleiro esteve na posicao inicial
	int nIni = 1;


    //mudar para cout
    printf("--->\t%d\n", pongHauKiEvaluation(t1, '1', '2', &nIni));
    printf("--->\t%d\n", pongHauKiEvaluation(t1, '2', '1', &nIni));

    printf("--->\t%d\n", pongHauKiEvaluation(t2, '1', '2', &nIni));
    printf("--->\t%d\n", pongHauKiEvaluation(t2, '2', '1', &nIni));


    return 0;
}
