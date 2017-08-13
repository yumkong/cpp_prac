// given an array of non-negative integers, and init position at 0
// each element in the array represents the maximum jump length at that position
// assume it can always rearch the last index, get the minimum move steps
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
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return true;
        // dp[idx]: if the idx-th elem can be reached
        //vector<bool> dp(len, false);
        //dp[len - 1] = true;
        // <idx of reachable elements>
        int qidx = len - 1, qsize = 1, cnt = 1;
        while(1)
        {
            cout << "qidx = " << qidx << endl; 
            // search from first to last, if found stop
            for(int i = 0; i < qidx; ++i)
            {
                if(i + nums[i] >= qidx)
                {
                    if(i == 0) return cnt;
                    else
                    {
                        qidx = i; ++cnt; break;
                    }
                }
            }
        }
    }
};

int main()
{
    Solution solu;
    vector<int> in1({10,9,8,7,6,5,4,3,2,1,1,0});
    //vector<int> in2({});
    cout << solu.jump(in1) << endl;
    return 0;
}
