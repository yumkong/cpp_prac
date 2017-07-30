// find the contiguous subarray within an array which has the largest sum
// the vector contains at least one number
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        // here cannot use dp[0] = 0 as the border: what if nums are all negative?
        int maxsofar = nums[0];
        dp[0] = nums[0]; //int maxcur = nums[0];
        for(int i = 1; i < len; ++i)
        {
            //maxcur = max(maxcur + nums[i], nums[i]);
            // record which is bigger: the consecutive sum one or the singleton one? 
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            //maxsofar = max(maxsofar, maxcur);
            // dp is a irregular recursion: like here use the max to change the elems of dp array
            maxsofar = max(maxsofar, dp[i]);
        }
        return maxsofar;
    }
};

int main()
{
    int a[] = {-2, -1}; //{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.maxSubArray(arr) << endl; // 6
    return 0;
}
