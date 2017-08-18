// given an non-negative int array and an integer m, split the array into m non-empty continous subarrays
// make sure to minimize the largest sum among these m subarrays
// 1<= n <= 1000,  1 <= m <= 50
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        if(len == 1) return nums[0];
        // change nums to an integer array
        vector<int> dp(len + 1, 0);
        for(int i = 0; i < len; ++i) dp[i+1] = dp[i] + nums[i];
        int avg = 0, maxsum = (1 << 31); // init as int_min
        if(m == 1) return dp[len];
        else avg = dp[len] / m;
        int preidx = 0, cnt = 0;
        for(int i = 1; i <= len; ++i)
        {
            if(dp[i] - dp[preidx] >= avg)
            {
                ++cnt;
                if(abs(dp[i] - dp[preidx] - avg) >= abs(dp[i - 1] - dp[preidx] - avg)) 
                {maxsum = max(maxsum, dp[i - 1] - dp[preidx]); preidx = i - 1; }
                else 
                {maxsum = max(maxsum, dp[i] - dp[preidx]); preidx = i; }
            }
        }
        cout << "cnt = " << cnt << ", preidx = " << preidx <<endl;
        if(cnt < m) maxsum = max(maxsum, dp[len] - dp[preidx]);
        return maxsum;
    }
};

int main()
{
    vector<int> input({1,2147483647});
    Solution solu;
    cout << solu.splitArray(input, 2) << endl;
    return 0;
}
