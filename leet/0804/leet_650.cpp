// given two options copy all and paste and a initial character 'A' on the notepad
// find the minimum number of steps to get n 'A'
// Note: n is in the range [1, 1000]
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, 0); // dp[i]: to get i 'A' what is the min-step needed?
        // dp[0] = 0, dp[1] = 0 (we already have an 'A')
        for(int i = 2; i <= n; ++i)
        {
            // init dp[i] as i
            dp[i] = i; // dp[2] = 2, dp[3] = 3
            for(int j = i/2; j > 1; --j)
            {
                if(i % j == 0) // find the first factor, then break
                {
                    dp[i] = dp[j] + (i / j);
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution solu;
    cout << solu.minSteps(10) << endl;
    return 0;
}
