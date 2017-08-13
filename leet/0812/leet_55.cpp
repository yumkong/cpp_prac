// given an array of non-negative integers, and init position at 0
// each element in the array represents the maximum jump length at that position
// determine if it is possible to rearch the last index
// eg1: [2,3,1,1,4] =>  true
// eg2: [3,2,1,0,4] => false
// use an important observation:
// if the end can be reached by a good idx in the middle, if some other points can reach the end,
// these point must can reach the good idx 
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int last = len - 1;
        for(int i = len - 1; i >= 0; --i)
        {
            if(i + nums[i] >= last) last = i;
        }
        return last == 0;
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
