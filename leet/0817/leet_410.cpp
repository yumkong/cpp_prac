// given an non-negative int array and an integer m, split the array into m non-empty continous subarrays
// make sure to minimize the largest sum among these m subarrays
// 1<= n <= 1000,  1 <= m <= 50
// Solu: the answer is between max value of the input array and sum of these numbers
// => use binary search to narrow down and left and right boundaries an approach the correct answer

#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxnum = 0;
        long arrsum = 0;
      
        for(int i = 0; i < nums.size(); ++i)
        {
            maxnum = max(maxnum, nums[i]);
            arrsum += nums[i];
        }
        // only 1 subarray
        if(m == 1) return (int)arrsum;
        // binary search
        long l = maxnum, r = arrsum;
        while(l <= r)
        {
            long mid = (l + r) / 2;
            // mid (target) is too large => not reach m yet
            if(valid(mid, nums, m)) r = mid - 1;
            else l = mid + 1;
        }
        return (int)l;
    }
    bool valid(long target, vector<int>& nums, int m)
    {
        int count = 1;
        long total = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            total += nums[i];
            if(total > target)
            {
                total = nums[i];
                ++count;
                if(count > m) return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> input({1,2147483647});
    Solution solu;
    cout << solu.splitArray(input, 2) << endl;
    return 0;
}
