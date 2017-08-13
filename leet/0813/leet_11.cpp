// container with most water
// given n non-negative ints a_1, a_2, ..., a_n, where each represents a point at (i, a_i)
// n vertical lines are drawn s.t. the two end points of line i is (i,a_i) and (i, 0)
// find two lines which together with x-axis forms a container s.t. it contains most water
// NOTE n >= i
//solu: 2-pointers: intuition: if we move the pointer at the longer line inwards, there won't be any
// increase in the area, but move the short lines inwards could possibly enlarge the area
// time O(n) and space O(1)
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int res = 0, left = 0, right = len - 1;
        while(left < right)
        {
            res = max(res, min(height[left], height[right]) * (right - left));
            if(height[left] > height[right]) --right;
            else ++left;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> height({4,2,3,4,7,3,2,5}); // 4 x 4 = 16
    cout << solu.maxArea(height) << endl;
    return 0;
}
