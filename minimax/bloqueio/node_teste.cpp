#include <iostream>
#include <iterator>
#include "node.hpp"
#include "tabuleiro.hpp"

using namespace std;

// Certo

int main()
{
    Tabuleiro t1 = pongHauKiBoard();

	  Tabuleiro t2 = pongHauKiBoard();
    t2.pongHauKiInitialPositions();

    Tabuleiro t3 = pongHauKiBoard();


    Node* NodeTest = new Node(t1);
    Node* NodeSonT = new Node(t2);
    Node* NodeSonT2 = new Node(t3);

    NodeTest->addChildren(NodeSonT);
    NodeTest->addChildren(NodeSonT2);

    // Varre todos os filhos da raiz ('Node')
    for(vector<Node*>::iterator it = NodeTest->children.begin(); it != NodeTest->children.end(); it++){
        (*it)->board.print();
    }

    return 0;
}
