#include <iostream>
#include "node.hpp"
#include "tabuleiro.hpp"

using namespace std;

// As funcoes referentes a classe 'Node' estao funcionando
// Os nodos estao sendo inseridos corretamente referentes a um determinado pai

int main()
{
    Tabuleiro t1 ({ {'1','0','2'},
                    {'2','1','1'},
                    {'2','0','0'}   });

	Tabuleiro t2 ({ {'1','0','2'},
                    {'2','1','0'},
                    {'2','0','1'}   });

    Tabuleiro t3 ({ {'0','1','2'},
                    {'0','1','2'},
                    {'2','1','0'}   });


    Node* NodeTest = new Node(t1);
    Node* NodeSonT = new Node(t2);
    Node* NodeSonT2 = new Node(t3);

    NodeTest->addChildren(NodeSonT);
    NodeTest->addChildren(NodeSonT2);

    // Varre todos os filhos da raiz ('Node')
    for(vector<Node*>::iterator it = NodeTest->children.begin(); it != NodeTest->children.end(); it++){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++)
                cout << it->board.posicoes[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
