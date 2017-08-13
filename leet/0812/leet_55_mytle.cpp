// given an array of non-negative integers, and init position at 0
// each element in the array represents the maximum jump length at that position
// determine if it is possible to rearch the last index
// eg1: [2,3,1,1,4] =>  true
// eg2: [3,2,1,0,4] => false
// TLE!!!
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return true;
        // dp[idx]: if the idx-th elem can be reached
        vector<bool> dp(len, false);
        dp[len - 1] = true;
        // <idx of reachable elements>
        deque<int> qidx;
        qidx.push_back(len - 1);
        int qsize = 1;
        while(1)
        {
            for(int i = 0; i < qsize; ++i)
            {
                int idx = qidx.front(); qidx.pop_front();
                for(int i = 0; i < idx; ++i)
                {
                    if(i + nums[i] >= idx && !dp[i])
                    {
                        dp[i] = true;
                        qidx.push_back(i);
                    }
                }
            }
            // update queue's size
            qsize = qidx.size();
            // if found idx = 0, return true
            if(qsize > 0)
            {
                //deque<int>::iterator it = find(qidx.begin(), qidx.end(), 0);
                if(find(qidx.begin(), qidx.end(), 0) != qidx.end()) return true;
            }
            else break;
        }
        return false;
    }
};

int main()
{
    Solution solu;
    vector<int> in1({2,3,1,1,4});
    vector<int> in2({3,2,1,0,4});
    cout << solu.canJump(in1) << endl;
    cout << solu.canJump(in2) << endl;
    return 0;
}
