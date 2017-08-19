// given a **circle** of non-negative ints representing the amount of money in each house, where the last house is the neighbor if the first house
// determine the maxinum amount of money can be robbed, when non two adjacent houses can be broken into
// NOTE: this is complex and not correct= > not use it!!!
// Solu: inspired by discussion: Since you cannot rob both the first and last house, just create two separate vectors, one excluding the first house, and another excluding the last house. The best solution generated from these two vectors using the original House Robber DP algorithm is the optimal one.
#include <iostream>
#include <vector>
#include <utility> // pair
#include <algorithm> // find
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len <= 0) return 0;
        if(len == 1) return nums[0];
        // pair<up till now the maximum money, inds that composes the maximum money>
        return max(rob(nums, 0, len - 2), rob(nums, 1, len - 1)); 
    }
    int rob(vector<int>& nums, int low, int high)
    {
        int preRob = 0, preNotRob = 0, robval = 0, notRobval = 0;
        for(int i = low; i <= high; ++i)
        {
            robval = preNotRob + nums[i];
            notRobval = max(preRob, preNotRob);
            preNotRob = notRobval;
            preRob = robval;
        }
        return max(robval, notRobval);
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,1,1,2}); // 14
    cout << solu.rob(input) << endl;
    return 0;
}
