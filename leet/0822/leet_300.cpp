// given an unsorted int array, find the length of longest increasing subsequence
// NOTE: should at least run O(n ^ 2), O(nlogn) is better
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // method: dp ==> two loops is common in dp
        // on the premise that the longest increasing subsequence possible upto the i-th index 
        // in a given array is independent of the elements coming later on in the array.
        int len = nums.size();
        if(len <= 0) return 0;
        vector<int> dp(len, 0);
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i < len; ++i)
        {
            int maxval = 0;
            for(int j = 0; j < i; ++j)
            {
                if(nums[i] > nums[j])
                {
                    maxval = max(maxval, dp[j]);
                }
            }
            dp[i] = maxval + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({10, 9, 2, 5, 3, 7, 101, 18});
    cout << solu.lengthOfLIS(input) << endl;
    return 0;
}
