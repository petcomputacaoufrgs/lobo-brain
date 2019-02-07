#include <iostream>
#include <list>

class Nodo
{
    public:
        int valor;
        Nodo* pai;
        std::list<Nodo> filhos;
        char tabuleiro[3][3];


    void Nodo(char tabuleiro[3][3], Nodo pai)
    {
        this->tabuleiro = tabuleiro;
        this->pai = pai;
    }

    void adicionaFilho(char tabuleiro[3][3])
    {
        Nodo novoFilho = Nodo(tabuleiro, this);
        this->filhos.insert(novoFilho);
    }

};
    

int main()
{
    std::cout << "sou lindo" << std::endl;

    return 0;
}

