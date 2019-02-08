#include <iostream>
#include <list>

using namespace std;

class Nodo
{
    public:
        Nodo();
        int valor;
        Nodo* pai;
        list<Nodo> filhos;
        string* tabuleiro;
        void adicionaFilho();

    private:
        list<Nodo>::iterator it;
};

Nodo::Nodo(string* tabuleiro, Nodo* pai)
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

    this->pai = pai;
}
    
Nodo::adicionaFilho(string tabuleiro[3][3])
{
    it = this->filhos.begin();
    it++;
    Nodo novoFilho = Nodo(tabuleiro, this);
    this->filhos.insert(it, novoFilho);
}


int main()
{
    cout << "sou lindo" << endl;

    return 0;
}

