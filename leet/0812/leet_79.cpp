// given a 2D board and a word, find if the word exists in the grid
// Note the word can be constructed from letters of sequentially adjcent cell, where "adjcent"
// cells are those horizontally or vertically neighoring
// the same letter cannot be used more than once => need a visited indicator
#include <string>
#include <vector>
#include <iostream>
#include <utility> // pair
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        // {delta_row, delta_col}
        direct.push_back({0, -1}); // left
        direct.push_back({0, 1}); // right
        direct.push_back({-1, 0}); // up
        direct.push_back({1, 0}); // down
        // using backtracking
        int row = board.size();
        if(row <= 0) return false;
        int col = board[0].size();
        if(col <= 0) return false;
        int wordlen = word.size();
        if(wordlen == 0) return false;
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c)
            {
                if(board[r][c] == word[0])
                {
                    if(helper(board, direct, r, c, word, 0, visited)) return true;
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<char> >& board, vector<pair<int, int> > direct, int r, int c, string word, int start, vector<vector<bool> >& visited)
    {
        // terminate condition
        if(start >= word.size()) return true;
        // when crossing board, return false
        int row = board.size(), col = board[0].size();
        if(r < 0 || r >= row || c < 0 || c >= col) return false;
        // current char not match or has already been visited
        if(board[r][c] != word[start] || visited[r][c]) return false;
        else visited[r][c] = true;
        // main body
        for(int i = 0; i < direct.size(); ++i)
        {
            if(helper(board, direct, r + direct[i].first, c + direct[i].second, word, start + 1, visited)) 
            { return true; }
        }
        // at the end, recover visited
        visited[r][c] = false;
        return false;
    }
private:
    vector<pair<int, int> > direct;
};

int main()
{
    Solution solu;
    vector<vector<char> > input({vector<char>({'A','B','C','E'}),
                                 vector<char>({'S','F','C','S'}),
                                 vector<char>({'A','D','E','E'})
                                });
    cout << solu.exist(input, "ABCCED") << endl;
    cout << solu.exist(input, "SEE") << endl;
    cout << solu.exist(input, "ABCB") << endl;
    return 0;
}
