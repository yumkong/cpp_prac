// find number of reverse pairs:
// given an array nums, we call (i, j) an important reverse pair if i < j
// and nums[i] > 2 * nums[j], find the number of all such pairs
// solu2: binary indexed tree => pass
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// the following 3 funcs can be used to other bst problem
void update(vector<int>& BIT, int index, int val)
{
    while (index > 0) {
        BIT[index] += val;
        index -= index & (-index);
    }
}

int query(vector<int>& BIT, int index)
{
    int sum = 0;
    while (index < BIT.size()) {
        sum += BIT[index];
        index += index & (-index);
    }
    return sum;
}

class Solution {
public:
    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> nums_copy(nums);
        sort(nums_copy.begin(), nums_copy.end());
        vector<int> BITS(n + 1, 0);
        int count = 0;
        for (int i = 0; i < n; i++) 
        {
	    count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
	    update(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
	}
	return count;
    }
};

int main()
{
    Solution solu;
    vector<int> input({2,4,3,5,1});
    cout << solu.reversePairs(input) << endl;
    return 0;
}
