// given a non-empty **positive** int array, find if the array can be paritioned into two subset s.t. the sum of
// elements in both subsets is equal
// NOTE: each of the elemnt <= 100, array size <= 200
// basic understanding, need read later
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size(), sum = 0;
        for(int i = 0; i < len; ++i) sum += nums[i];
        if(sum % 2 == 1) return false;
        sum /= 2;// half sum
        //meaning: up till len, is there a combination of elems that can be sum ?
        vector<vector<bool> > dp(len+1, vector<bool>(sum + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= len; ++i) dp[i][0] = true;
        for(int k = 1; k <= sum; ++k) dp[0][k] = false;
        for(int i = 1; i <= len; ++i)
        {
            for(int k = 1; k <= sum; ++k)
            {
                dp[i][k] = dp[i-1][k];
                // when i-th elem is no larger than sum 
                // for the first time, dp[i][k] == true only when nums[i-1] == k
                if(k >= nums[i-1]) dp[i][k] = (dp[i][k] || dp[i-1][k - nums[i-1]]);
            }
        }
        return dp[len][sum];
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,2,3,5});
    cout << solu.canPartition(input) << endl;
    return 0;
}
