#include <iostream>
#include "tree.hpp"
#include "move.cpp"

using namespace std;

Tree::Tree(vector<string> startingBoard)
{
    Node* rootNode = new Node(startingBoard);
    this->setRoot(rootNode);
}

void Tree::setRoot(Node* root)
{
    this->root = root;
}

//fazer func de copia ou pesquisar no google

vector<vector<string>>* Tree::generateBoards(String board[3], char player)
{
    int i,j;
    std::vector<vector<int>> possible_mov;
    vector<vector<string>> possibleBoards;
    // passa a posicao (de 0 a 8 no tapatan) do jogador analisado e, no move.cpp ve os movimentos possiveis a partir daquela posicao
    // move.cpp devolve uma lista de duplas (i,j) de cada posicao atual e aqui na generate a gente verifica quais movimentos sao possiveis e adiciona no vetor a ser devolvido

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j] == player)
            {
                player_pos = 3*i+j;
                possible_mov = tapatanMoves(player_pos);
                for(vector<int>::iterator it = possible_mov.begin(); it != possible_mov.end(); it++)
                {
                    if(board[it[0]][it[1]] == '0')
                    {
                        //gambiarra fodida pois n sei cpp quem quiser melhorar pode dale
                        std::vector<string> b = board;
                        b[it[0]][it[1]] = player;
                        b[i][j] = '0';
                        possibleBoards.push_back(b);
                    }

                }
            }
        }
    }
    return possibleBoards;
}

void Tree::generateChildren(Node* node, char player)
{
    vector<vector<string>> possibleBoards;
    cd DopossibleBoards = generateBoards(node.board, player);

    /*for (vector<string>::iterator it = possibleBoards.begin(); it != possibleBoards.end(); it++)
    {
        Node* newChildren = new Node(it);
        self.addChildren(newChildren);
    }*/
}

int main()
{
    vector<string> start = {"102", "012", "201"};

    Tree* testree = new Tree(start);

    cout << testree->root << endl;

    return 0;
}
