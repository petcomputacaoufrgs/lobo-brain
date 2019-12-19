using namespace std;


// aparentemente as funcoes relacionadas a move.cpp estao funcionando corretamente
int main()
{
    int player_pos = 0;
    int player_pos = 4;

    vector<vector<int>> possible_mov = tapatanMoves(player_pos);

   // deve-se varrer todo possible_mov, mas como nao sei cpp nao sei fazer isso :D
    for (int i = 0; i < possible_mov.size(); i++)
    {
        for (int j = 0; j < possible_mov[i].size(); j++)
        {
            cout << possible_mov[i][j];
        }
        cout << endl;
    }
    return 0;
} 