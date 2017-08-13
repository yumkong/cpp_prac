// minimum path sum
// given an m x n grid filled with non-negative numbers, find a path from top-left to bottom-right 
// which minimizes the sum of all numbers along its path
// NOTE: can only move either down or right at any point in time
// me: this is a simple dp problem
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int row = grid.size();
        if(row <= 0) return 0;
        int col = grid[0].size();
        if(col <= 0) return 0;
        vector<vector<int> > dp(row + 1, vector<int>(col + 1, 0));
        // init left edge
        for(int i = 1; i <= row; ++i) dp[i][1] = dp[i - 1][1] + grid[i - 1][0];
        // init top edge
        for(int i = 1; i <= col; ++i) dp[1][i] = dp[1][i - 1] + grid[0][i - 1];
        for(int r = 2; r <= row; ++r)
        {
            for(int c = 2; c <= col; ++c)
            {
                // min of left and top
                dp[r][c] = min(dp[r-1][c], dp[r][c - 1]) + grid[r - 1][c - 1];
            }
        }
        return dp[row][col];
    }
};

int main()
{
    vector<vector<int> > grid({vector<int>({1,3,5,7}),
                                 vector<int>({10,2,8,20}),
                                 vector<int>({23,4,2,50})
                                });
    Solution solu;
    cout << solu.minPathSum(grid) << endl;
    return 0;
}
