// maximal square
// given a 2D binary matrix filled with 0 and 1, find the largest square containing only 1's and return its area
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // method: using dp
        int row = matrix.size();
        if(row <= 0) return 0;
        int col = matrix[0].size();
        if(col <= 0) return 0;
        int maxedge = 0;
        vector<vector<int> > dp(row + 1, vector<int>(col + 1, 0));
        for(int i = 1; i <= row; ++i)
        {
            for(int j = 1; j <= col; ++j)
            {
                if(matrix[i-1][j-1] == '1')
                {
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                    maxedge = max(maxedge, dp[i][j]);
                }
            }
        }
        return maxedge * maxedge;
    }
};

int main()
{
    Solution solu;
    vector<vector<char> > matrix({ {'1','0','1','0','0'}, {'1','0','1','1','1'}, {'1','1','1','1','1'}, 
                                   {'1','0','0','1','0'} });
    cout << solu.maximalSquare(matrix) << endl;
    return 0;
}
