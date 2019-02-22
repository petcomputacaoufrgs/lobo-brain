#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Nodo
{
    public:
        int valor;
        Nodo *pai;
        list<Nodo> filhos;
        string* tabuleiro;

        Nodo(string* tabuleiro);
        
        void adicionaFilho(string* tabuleiro);

    private:
        list<Nodo>::iterator it;
};

Nodo::Nodo(string* tabuleiro)
{
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

 void Nodo::adicionaFilho(string* tabuleiro)
{   
    it++;
    Nodo novoFilho = Nodo(tabuleiro);
    novoFilho.pai = this;
    this->filhos.insert(it, novoFilho);
}


int main()
{   
    Nodo nodoTeste = new Nodo({{'0', '0', '1'}, {'1', '0', '0'}, {'1', '0', '1'}});
    Nodo nodoFilhoT = new Nodo({{'0', '0', '1'}, {'1', '0', '0'}, {'0', '0', '0'}});

    nodoTeste.adicionaFilho(nodoFilhoT);

    cout << "sou lindo" << endl;

    return 0;
}

