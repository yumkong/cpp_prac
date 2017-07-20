// given a sequence of n ints: a1, a2, ... an, find whether or not having 132 pattern:
// i < j < k and  ai < ak < aj
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return false;
        if(len == 3) return (nums[0] < nums[2]) && (nums[2] < nums[1]);
        // s1 for storing ai (min), s2 for storing aj (max)
        stack<int> s1, s2;
        s1.push(nums[0]);
        for(int i = 0; i < len; ++i)
        {
            if(!s1.empty() && s1.top() > nums[i])

        }
    }
};
