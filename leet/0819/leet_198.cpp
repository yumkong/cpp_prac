// given a list of non-negative ints representing the amount of money in each house, determine the maxinum amount of money can be robbed, when non two adjacent houses can be broken into
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        vector<int> dp(len + 1, 0);
        dp[1] = nums[0];
        for(int i = 2; i <= len; ++i)
        { // up till i, what the maximum money can we get
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        } 
        return dp[len];
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,3,5,7,9});
    cout << solu.rob(input) << endl;
    return 0;
}
