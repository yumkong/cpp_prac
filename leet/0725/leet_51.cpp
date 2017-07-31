// n queen: placing n queens on an n x n chessboard s.t. no two queens attach each other
// Given an integer n, return all distinct solutions to the n-queens puzzle
// each solution contains a distinct board configuration of the n-queen displacement 'Q'(queen), '.'(empty)
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        if(n <= 0) return res; // empty
        if(n == 1) 
        {
            res.push_back(vector<string>(1,"Q"));
            return res;
        }
        vector<string> nQueens(n, string(n, '.'));
        helper(0, n, res, nQueens);
        return res;
    }
    void helper(int row, int &total, vector<vector<string> > &res, vector<string>& nQueens)
    {
        cout << "row = " << row << endl;
        if(row == total)
        {
            res.push_back(nQueens);
            return;
        }
        for(int col = 0; col != total; ++col)
        {
            if(isValid(nQueens, row, col, total))
            {
                nQueens[row][col] = 'Q';
                helper(row + 1, total, res, nQueens);
                nQueens[row][col] = '.'; // before go to the next for iter, first delete the Queen
            }
        }
    }
    bool isValid(vector<string> &nQueens, int row, int col, int &total)
    {
        cout << "col = " << col << endl;
        // if the column has a queen before
        for(int i = 0; i != row; ++i)
        {
            if(nQueens[i][col] == 'Q') return false;
        }
        // check 45 diagonal NOTE condition must use "&&" to connect instead of ","
        for(int i = row - 1, j = col - 1; i >= 0 && j>= 0; --i, --j)
        {
            if(nQueens[i][j] == 'Q') return false;
        }
        // check 135 diagonal NOTE condition must use "&&" to connect instead of ","
        for(int i = row - 1, j = col + 1; i >= 0 && j < total; --i, ++j)
        {
            if(nQueens[i][j] == 'Q') return false;
        }
        return true;
    }
};

int main()
{
    Solution solu;
    vector<vector<string> > board = solu.solveNQueens(4);
    for(int i = 0; i < board.size(); ++i)
    {
        cout << "### board " << i << " ###" << endl;
        for(int j = 0; j < board[0].size(); ++j) cout << board[i][j] << endl;
        cout << endl;
    }
    return 0;
}
