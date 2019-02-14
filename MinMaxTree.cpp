#include <iostream>
#include <list>

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
        void setPai(Nodo *pai)
        {
            this->pai = pai;
        }

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
    it = this->filhos.begin();
    it++;
    Nodo *novoFilho = new Nodo(tabuleiro);
    novoFilho.setPai(pai);
    this->filhos.insert(it, novoFilho);
}


int main()
{
    cout << "sou lindo" << endl;

    return 0;
}

