#include <iostream>
#include <string>
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

//fazer func de copia ou pesquisar no google (?????)

vector<vector<string>> Tree::generateBoards(vector<string> board, char player) 
{
    int i,j, player_pos;
    vector<vector<int>> possible_mov;
    vector<vector<string>> possibleBoards;
    // passa a posicao (de 0 a 8 no tapatan) do jogador analisado e, no move.cpp ve os movimentos possiveis a partir daquela posicao
    // move.cpp devolve uma lista de duplas (i,j) de cada posicao atual e aqui na generate a gente verifica quais movimentos sao possiveis e adiciona no vetor a ser devolvido
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {   
            if(board.at(i).at(j) == player)
            {
                player_pos = 3*i+j;
                possible_mov = tapatanMoves(player_pos);
                for(vector<vector<int>>::iterator it = possible_mov.begin(); it != possible_mov.end(); it++)
                {
                    if(board[it->at(0)][it->at(1)] == '0')
                    {
                        //gambiarra fodida pois n sei cpp quem quiser melhorar pode dale
                        std::vector<string> b = board;
                        b[it->at(0)][it->at(1)] = player;
                        b[i][j] = '0';
                        possibleBoards.push_back(b);
                    }

                }
            }
        }
    }
    return possibleBoards;
}

void Tree::generateChildren(Node* startingNode, char player)
{
    vector<vector<string>> possibleBoards;
    Node* newChild;
    vector<string> b;
    
    possibleBoards = generateBoards(startingNode->board, player); 
    
    for (vector<vector<string>>::iterator it = possibleBoards.begin(); it != possibleBoards.end(); it++)
    {
        newChild = new Node(*it);
        startingNode->addChildren(newChild);
    }
}

/*int main()
{
    vector<string> start = {"102", "002", "211"};

    Tree* testree = new Tree(start);
    
    testree->generateChildren(testree->root, '1');

    cout << testree->root << endl;
    
    for(vector<Node>::iterator chld = testree->root->children.begin(); chld != testree->root->children.end(); chld++)
    {
        for(vector<string>::iterator brd = chld->board.begin(); brd != chld->board.end(); brd++)
            cout << *brd << endl;
        cout << endl;
    } 
    
    return 0;
}*/
