// figure out if someone has won tic-tac-toe
#include <iostream>
using namespace std;

enum Check{ ROW, COLUMN, DIAGONAL, REDIAGONAL };// 0 1 2 3

int CheckRowColumn(int board[], int n, Check check)
{
    int type = 0;
    for(int i = 0; i < n; ++i)
    {
        bool found = true;
        for(int j = 0; j < n; ++j)
        {
            int k = 0;
            if(check == ROW)
            {
                // k = 0,1,2
                k = i * n + j;//get linear_idx of [i,j]
            }
            else
            { 
                // k = 0, 3, 9
                k = i + j * n;
            }
            if(j == 0)
            {
                type = board[k]; //if in first column, assign it to type (aka, user's type: 0, 1 or 2)
            }
            else if(board[k] != type)// for 2nd and 3rd column, compare it to type
            {
                found = false;
                break;
            }
        }
        if(found) return type;
    } 
    return 0;
}

int CheckDiagonal(int board[], int n, Check check)
{
    int type = 0;
    bool found = true;
    //
    for(int i = 0; i < n; ++i)
    {
        int k = 0;
        if(check == DIAGONAL)
        {
            k = i + i * n; //diagnal: (0,0) -> (1,1) -> (2,2)
        }
        else
        {
            k = i + (n - 1 - i) * n; //off-diagonal: (0, 2) -> (1, 1) -> (2, 0)
        }
        if(i == 0)
        {
            type = board[k];
        }
        else if(board[k] != type)
        {
            found = false;
            break;
        }
    }
    if(found) return type;
    return 0;
} 

int hasWon(int board[], int n)
{
    int type = 0;
    type = CheckRowColumn(board, n, ROW);
    if(type != 0) return type;
    type = CheckRowColumn(board, n, COLUMN);
    if(type != 0) return type;
    type = CheckDiagonal(board, n, DIAGONAL);
    if(type != 0) return type;
    type = CheckDiagonal(board, n, REDIAGONAL);
    if(type != 0) return type;
    return 0;
}

int main()
{
    int n = 3; // 3 x 3 board
    int board[] = {
        2, 2, 1, 
        2, 1, 1,
        1, 2, 0
    };
    // there are 3 types: 0-blank, 1,2 are users
    int type = hasWon(board, n);
    if(type != 0)
    {
        cout << type << " won!" << endl;
    }
    else
    {
        cout << "nobody won!" << endl;
    }
    return 0;
}
