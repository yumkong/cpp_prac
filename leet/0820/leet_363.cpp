// given an non-empty 2D matrix and an int K, find the max sum of a rectangle in the matrix s.t. its sum is <= k
//NOTE: the rectangle inside the matrix must have an area > 0
// what if the number of rows is much larger than the number of columns ? 
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        if(row <= 0) return 0;
        int col = matrix[0].size();
        if(col <= 0) return 0;
        //cout << "row = " << row << ", col = " << col << endl;
        // integeral matrix
        vector<vector<int> > dp(row + 1, vector<int>(col + 1, 0));
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {   // integeral matrix
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + matrix[i][j];
            }
        }
        int res = (1 << 31); // init as min_int
        for(int i = 1; i <= row; ++i)
        {
            for(int j = 1; j <= col; ++j)
            {   // integeral matrix
                //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
                for(int m = i; m <= row; ++m)
                {
                    for(int l = j; l <= col; ++l)
                    {
                        int area = dp[m][l] + dp[i-1][j-1] - dp[i-1][l] - dp[m][j-1];
                        if(area <= k) res = max(res, area);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<vector<int> > matrix({ {2, 2, -1} });
    cout << solu.maxSumSubmatrix(matrix, 3) << endl;
    return 0;
}
