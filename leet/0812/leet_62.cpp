// a robot is located at top-left corner of a m x n grid, it can only move down or right at any point,
// how many unique paths that it can take to reach the bottom-right corner?
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0) return 0;
        if(m == 1 || n == 1) return 1;
        vector<vector<int> > dp(m, vector<int>(n, 1));
        for(int r = 1; r < m; ++r)
        {
            for(int c = 1; c < n; ++c) dp[r][c] = dp[r-1][c] + dp[r][c-1];
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution solu;
    cout << solu.uniquePaths(3,3) << endl;
    return 0;
}
