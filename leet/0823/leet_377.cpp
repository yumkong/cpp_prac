// given an int array with all positive nums and no ***duplicates**, find the number of possible combinations that add
// up to a positive integer target
// me: use dp[target+1]: how many way to get a sum of target
// me2: backtracking => Time Limit Exceeded
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();
        if(len <= 0 || target <= 0) return 0;
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        return helper(nums, dp, target);
    }
    int helper(vector<int>& nums, vector<int>& dp, int target)
    {
        //if(sum > target) return;
        if(dp[target] != -1) { return dp[target]; }
        int res = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
			// 0825: if nums[i] > target: does not come here, res will keep 0
            if(nums[i] <= target) res += helper(nums, dp, target - nums[i]);
        }
        dp[target] = res;
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,2,3});
    cout << solu.combinationSum4(input, 32) << endl; // 7
    return 0;
}

// alternative: bottom-up dp
/*
public int combinationSum4(int[] nums, int target) {
    int[] comb = new int[target + 1];
    comb[0] = 1;
    for (int i = 1; i < comb.length; i++) {
        for (int j = 0; j < nums.length; j++) {
			// otherwise it keeps 0
            if (i - nums[j] >= 0) {
                comb[i] += comb[i - nums[j]];
            }
        }
    }
    return comb[target];
}
*/

