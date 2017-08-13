// given an array of non-negative integers, and init position at 0
// each element in the array represents the maximum jump length at that position
// assume it can always rearch the last index, get the minimum move steps
// eg1: [2,3,1,1,4] =>  true
// eg2: [3,2,1,0,4] => false
// 
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), step = 0, start = 0, end = 0;
        while (end < n - 1) 
        {
            step++; 
	    int maxend = end + 1;
	    for (int i = start; i <= end; i++) 
            {
                if(i + nums[i] >= n - 1) return step;
	        maxend = max(maxend, i + nums[i]);
	    }
            start = end + 1;
            end = maxend;
        }
	return step;
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
