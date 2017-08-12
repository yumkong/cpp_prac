// minimum size subarray sum:
// given an array of n pos ints and a pos int s, find the minimum length of a contiguous subarray
// of which the sum >= s. If no such subarray, return 0
// mine: deque + backtracking ==> fail
// other: use 2 pointers, one for the start and another for the end of the current subarray
//        make optimal moves so as to keep the sum greater than s as well as maintain the lowest size possible
// time O(n), space O(1)
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int res = ~(1 << 31); // max_int
        int left = 0, sum = 0;
        for(int i = 0; i < len; ++i)
        {
            sum += nums[i];
            while(sum >= s)
            {
                res = min(res, i - left + 1); // 
                sum -= nums[left++]; // moving left forward to see if this still meet requirment
            }
        }
        return (res != ~(1<<31)) ? res : 0;
    }
};

int main()
{
    Solution solu;
    vector<int> input({2,3,1,2,4,3});
    // show the minimum length
    cout << solu.minSubArrayLen(7, input) << endl;
    return 0;
}
