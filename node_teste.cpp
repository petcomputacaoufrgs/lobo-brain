#include <iostream>
#include "node.hpp"
#include "tabuleiro.hpp"

using namespace std;

int main()
{
    Tabuleiro t1 ({ {'1','0','2'},
                    {'2','1','1'},
                    {'2','0','0'}   });
                    
	Tabuleiro t2 ({ {'1','0','2'},
                    {'2','1','0'},
                    {'2','0','1'}   });


    Node* NodeTest = new Node(t1);
    Node* NodeSonT = new Node(t2);

    NodeTest->addChildren(NodeSonT);

    return 0;
}