// given a list of non-negative int list, for each integer, choose either '+' or '-' as its new symbol
// find out how many ways to assign symbols to make sum of ints equal to S
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        if(len <= 0) return 0;
        return helper(nums, S, 0, 0);
    }
    int helper(vector<int>& nums, int dest, int sum, int start)
    {
        if(start >= nums.size())
        {
            if(sum == dest) return 1;
            else return 0;
        }
        return helper(nums, dest, sum + nums[start], start + 1) + helper(nums, dest, sum - nums[start], start + 1);
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,1,1,1,1});
    cout << solu.findTargetSumWays(input, 3) << endl;
    return 0;
}
// a better solution
/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum < S || (sum+S) % 2 == 1) return 0;
        int target = (sum + S) / 2;
        vector<int> ways(target+1, 0);
        ways[0] = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                ways[j] += ways[j-nums[i]];
            }
        }
        return ways[target];
    }
};
*/
