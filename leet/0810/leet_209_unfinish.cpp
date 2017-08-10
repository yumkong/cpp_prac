// given an array of n pos ints and a pos int s, find the minimum length of a contiguous subarray
// of which the sum >= s. If no such subarray, return 0
// mine: deque + backtracking
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int subsum = 0;
        int res = ~(1 << 31);
        deque<int> dq;
        helper(nums, dq, subsum, s, res, 0);
        return res;
    }
    void helper(vector<int>& nums, deque<int> &dq, int subsum, int s, int &res, int start)
    {
        cout << "subsum = " << subsum << endl;
        if(subsum >= s)
        {
            if(dq.size() < res) res = dq.size();
        }
        if(start >= nums.size()) return;
        for(int i = start; i < nums.size(); ++i)
        {
            // use dq to guarantee consecutivity of subarray
           // cout << "pushing back: " << nums[i] << endl;
            dq.push_back(nums[i]);
            subsum += nums[i];
            helper(nums, dq, subsum, s, res, i + 1);
            subsum -= dq.front();
           // cout << "poping front: " << dq.front() << endl; 
            dq.pop_front(); // pop out dq[0]
        }
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
