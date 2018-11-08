#define <iostream>
using namespace std;

int funcaoVDE(int tab[3][3], char jogador)
{
  //testa vitoria
  if (tab[0][0] == jogador)
  {
    if (tab[0][1] == jogador && tab[0][2] == jogador || tab[1][0] == jogador && tab[2][0] == jogador || tab [1][1] == jogador && tab [2][2] == jogador)
    {
      return 1;
    }
  }
  else if (tab[0][2] == jogador)
  {
    if (tab[1][1] == jogador && tab[2][0] == jogador || tab[1][2] == jogador && tab[2][2] == jogador)
    {
      return 1;
    }
  }
  else if (tab[1][1] == jogador && tab[1][2] == jogador || tab[1][0] == jogador && tab[1][2])
  {
    return 1;
  }
  else if (tab[2][0] == jogador && tab[2][1] == jogador && tab[2][2] == jogador)
  {
    return 1;
  }

  //testa derrota


  }


int main()
{



  return 0;
}
