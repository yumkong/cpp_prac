//given a m x n grid and the start coordinate (i, j) of the ball, can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). But at most move N times. 
//Find out the number of paths to move the ball out of grid boundary. 
// the answer may be large, return it after mod 10^9 + 7
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        //if((i < 0 || i >= m) && (j < 0 || j >= n)) return 1;
        //if(N <= 0) return 0;
        bprime = 1000000007;
        vector<int> tmp1(N + 1, -1); // why N + 1? => need to compute [i][j][N]: max(i) == m-1, max(j) == n-1, and N
        vector<vector<int> > tmp2(n, tmp1);
        // here dp's functionality is to avoid duplicate computation
        vector<vector<vector<int> > > dp(m, tmp2);
        return helper(m, n, N, i, j, dp);
    }
    int helper(int m, int n, int N, int i, int j, vector<vector<vector<int> > > &dp)
    {
        if(i < 0 || i == m || j < 0 || j == n) return 1;
        if(N <= 0) return 0; // not boarder and no step left to move
        if(dp[i][j][N] >= 0) return dp[i][j][N];
        dp[i][j][N] = ((helper(m, n, N - 1, i - 1, j, dp) + helper(m, n, N - 1, i + 1, j, dp)) % bprime + (helper(m, n, N - 1, i, j - 1, dp) + helper(m, n, N - 1, i, j + 1, dp)) % bprime) % bprime;
        return dp[i][j][N];
    }
private:
    int bprime;
};

int main()
{
    Solution solu;
    cout << solu.findPaths(1, 3, 3, 0, 1) << endl;
    return 0;
}
