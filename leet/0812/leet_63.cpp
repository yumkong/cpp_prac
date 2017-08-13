// unique paths II : follow up of leet_62: unique paths with obstacles
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m <= 0) return 0;
        int n = obstacleGrid[0].size();
        if(n <= 0) return 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int i = 0;
        while(i < m && obstacleGrid[i][0] == 0) {dp[i][0] = 1; ++i; }
        i = 0;
        while(i < n && obstacleGrid[0][i] == 0) {dp[0][i] = 1; ++i; }
        for(int r = 1; r < m; ++r)
        {
            for(int c = 1; c < n; ++c) 
            {
                if(obstacleGrid[r][c] == 0) dp[r][c] = dp[r-1][c] + dp[r][c-1];
                else dp[r][c] = 0;
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution solu;
    vector<vector<int> > matrix({vector<int>({0,0,0}),
                                 vector<int>({0,1,0}),
                                 vector<int>({0,0,0})
                                });
    cout << solu.uniquePathsWithObstacles(matrix) << endl;
    return 0;
}
