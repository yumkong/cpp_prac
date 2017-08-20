// given an int matrix, find the length of the longest increasing path
// can move to four directions: left, right, up and down
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    vector<pair<int, int> > direct;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row <= 0) return 0;
        int col = matrix[0].size();
        if(col <= 0) return 0;
        // initialize direct
        direct.push_back({-1, 0}); // up
        direct.push_back({1, 0}); //down
        direct.push_back({0, -1}); // left
        direct.push_back({0, 1}); // right
        // store the number of increasing path of each position
        vector<vector<int> > dp(row, vector<int>(col, -1));
        int res = 0;
        for(int r = 0; r < row; ++r)
        {
            for(int c = 0; c < col; ++c) 
            {
                int tmp = helper(dp, matrix, r, c);
                //cout << "r = " << r << ", c = " << c << ": " << tmp << endl;
                res = max(res, tmp);
            }
        }
        return res+1;
    }
    int helper(vector<vector<int> > &dp, vector<vector<int> > &matrix, int r, int c)
    {   
        // check border case
        int row = matrix.size(), col = matrix[0].size();
        // if already computed
        if(dp[r][c] >= 0) return dp[r][c];
        int res = 0;
        for(int i = 0; i < 4; ++i)
        {
            int newr = r + direct[i].first, newc = c + direct[i].second;
            if(check(newr, newc, row, col) && matrix[newr][newc] < matrix[r][c])
                res = max(res, 1 + helper(dp, matrix, newr, newc));
        }
        dp[r][c] = res;
        return res;
    }
    bool check(int r, int c, int row, int col)
    {
        if(r < 0 || c < 0 || r >= row || c >= col) return false;
        else return true;
    }
};

int main()
{
    Solution solu;
    vector<vector<int> > input({vector<int>({9,9,4}), // {3,4,5}),
                                vector<int>({6,6,8}), // {3,2,6}),
                                vector<int>({2,1,1})}); // {2,2,1})}); 
    cout << solu.longestIncreasingPath(input) << endl;
    return 0;
}
