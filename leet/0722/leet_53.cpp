// find the contiguous subarray within an array which has the largest sum
// the vector contains at least one number
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int maxsofar = nums[0], maxcur = nums[0];
        for(int i = 1; i < len; ++i)
        {
            maxcur = max(maxcur + nums[i], nums[i]);
            maxsofar = max(maxsofar, maxcur);
        }
        return maxsofar;
    }
};

int main()
{
    int a[] = {-2, -1}; //{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.maxSubArray(arr) << endl; // 6
    return 0;
}
