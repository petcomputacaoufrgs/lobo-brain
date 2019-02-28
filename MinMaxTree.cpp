#include <iostream>
#include <vector>

using namespace std;

class Nodo
{
    public:
        int valor;
        Nodo *pai;
        vector<Nodo> filhos;
        vector<string> tabuleiro;

        Nodo(vector<string> tabuleiro);

        void adicionaFilho(Nodo* novoFilho);

};

Nodo::Nodo(vector<string> tabuleiro)
{
    cout << tabuleiro[2][2] << "criou nodo" << endl;

    int nCol = sizeof(tabuleiro) / sizeof(tabuleiro[0]);

    int nLin = sizeof(tabuleiro[0]) / sizeof(char);

    for (int i=0; i<nCol; i++)
    {
        for (int j=0; j<nLin; j++)
        {
            this->tabuleiro[i][j] = tabuleiro[i][j];
        }
    }

    this->pai = NULL;
}

 void Nodo::adicionaFilho(Nodo* novoFilho)
{
    cout << "adiciona filho" << endl;

    //Nodo novoFilho = Nodo(tabuleiro);
    novoFilho->pai = this;
    this->filhos.push_back(*novoFilho);
}


int main()
{
    vector<string> teste00 = {"001", "100", "101"};
    vector<string> teste01 = {"000", "110", "100"};

    cout << teste00[1][1];

    Nodo* nodoTeste = new Nodo(teste00);
    Nodo* nodoFilhoT = new Nodo(teste01);

    nodoTeste->adicionaFilho(nodoFilhoT);

    cout << "sou lindo" << endl;

    return 0;
}

