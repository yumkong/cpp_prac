// given int n, how many structurally unique BST that can store values 1,2,..., n
// ME: this seems like a dp problem
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(n == 2) return 2;
        vector<int> dp(n+1, 0);
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for(int i = 3; i <= n; ++i)
        {
            int sum = 0;
            for(int j = 0; j < i / 2; ++j)
            {
                // 1 node is act as root
                sum += 2 * dp[j] * dp[i-j-1];
            }
            if(i % 2 == 1) sum += dp[i/2] * dp[i/2];
            dp[i] = sum;
        }
        return dp[n];
    }
};

int main()
{
    Solution solu;
    cout << solu.numTrees(3) << endl;
    return 0;
}
