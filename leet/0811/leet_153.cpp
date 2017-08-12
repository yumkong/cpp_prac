// find the contiguous subarray (contains at least 1 number) which has the largest product
// me: "constiguous" subarray should use two pointers
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0], imax = nums[0], imin = nums[0];
        for(int i = 1; i < len; ++i)
        {
            // when getting a negative, swap min and max
            if(nums[i] < 0) {int tmp = imax; imax = imin; imin = tmp; };
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);
            res = max(res, imax);
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({2,3,-2,4});
    cout << solu.maxProduct(input) << endl;
    return 0;
}
