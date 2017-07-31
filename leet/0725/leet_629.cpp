// k inverse pairs array
// given two integers n and k, find how many different arrays consist numbers from 1 to n s.t. there are k inverse paris
// an inverse pair in array a is: (a[i], a[j]) where i<j and a[i] > a[j]
// integer n is in the range [1, 1000] and k in the range [0, 1000]
// *** NOTE: since the answer may be very large, it should be modulo 1000000007
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        int bigprime = 1000000007;
        // maximum number of inverse pair is n*(n-1)/2 for [1,2,...,n]
        if(k > n*(n-1)/2 || k < 0) return 0; // no such array
        if(k == 0 || k == n*(n-1)/2) return 1; // either total reverse or total original
        //if(n == 1) return 0;
        vector<long> dp_sub(k+1, 0);
        // (n + 1) x (k + 1)  matrix
        vector<vector<long> > dp(n+1, dp_sub);
        // border condition: when 2 elements: 1 non-inverse pair and 1 inverse pair
        dp[2][0] = 1; // n == 2, k == 0
        dp[2][1] = 1; // n == 2, k == 1
        for(int i = 3; i <= n; ++i)
        {
            // border condition, for all i>=3 elements, only 1 non-inverse pair
            dp[i][0] = 1;
            // maxinum number of inverse pairs given i elements: (i-1) + (i-2) +... + 1 = i*(i-1)/2
            int cur_max = i*(i-1)/2;
            // stop at min(k, cur_max): no need to do more
            for(int j = 1; j <= min(k, cur_max); ++j)
            {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
                if(j >= i) dp[i][j] -= dp[i-1][j-i];
                // sometimes may be negative so (x + bigprime) % bigprime
                dp[i][j] = (dp[i][j] + bigprime) % bigprime;
            }
        } 
        return (int) dp[n][k];
    }
};

int main()
{
    Solution solu;
    cout << solu.kInversePairs(3, 1) << endl; // should be 2
    return 0;
}
