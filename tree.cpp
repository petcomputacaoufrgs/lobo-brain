#include <iostream>
#include <vector>

using namespace std;

class Node
{
    public:
        int value;
        Node *parent;
        vector<Node> children;
        vector<string> board;

        Node(vector<string> board);

        void addSon(Node* newSon);

};

Node::Node(vector<string> board)
{
    cout << board[2][2] << "criou Node" << endl;

    int nCol = sizeof(board) / sizeof(board[0]);

    int nLin = sizeof(board[0]) / sizeof(char);

    for (int i=0; i<nCol; i++)
    {
        for (int j=0; j<nLin; j++)
        {
            this->board[i][j] = board[i][j];
        }
    }

    this->parent = NULL;
}

 void Node::addSon(Node* newSon)
{
    cout << "adiciona filho" << endl;

    //Node newSon = Node(board);
    newSon->parent = this;
    this->children.push_back(*newSon);
}


int main()
{
    vector<string> test00 = {"001", "100", "101"};
    vector<string> test01 = {"000", "110", "100"};

    cout << test00[1][1];

    Node* NodeTest = new Node(test00);
    Node* NodeSonT = new Node(test01);

    NodeTest->addSon(NodeSonT);

    cout << "sou lindo" << endl;

    return 0;
}

