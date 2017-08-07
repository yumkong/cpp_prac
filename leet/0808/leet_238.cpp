// given an arry of n integers (n > 1), return an array of same lenght s.t. its i-th pos equal to the product of 
// all elems of nums except nums[i]
// solve it without division and in O(1) => can it be done with O(1) space ? 
// e.g. [1,2,3,4] => [24,12,8,6]
// idea: forward and backward accumulate product
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        for(int i = 1; i < len; ++i)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for(int i = len - 1; i >= 0; --i)
        {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};

int main()
{
    vector<int> arr({1,2,3,4});
    Solution solu;
    vector<int> res = solu.productExceptSelf(arr);
    for(auto &i: res) cout << i << " ";
    cout << endl;
    return 0;
}
