// given a sorted array containing only ints where every element appears twice except for one element which appears
// once, find this single element appearinng once
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        int left = 0, right = len - 1, mid, halflen;
        while(left < right)
        {
            mid = (left + right) / 2;
            halflen = (right - left) / 2;
            // processing differs when half len is even or odd
            if(halflen % 2 == 1)
            {
                if(nums[mid] == nums[mid-1]) left = mid + 1;
                else right = mid - 1;
            }
            else
            {
                if(nums[mid] == nums[mid + 1]) left = mid + 2;
                else right = mid;
            }
        }
        return nums[left];
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,1,2,3,3,4,4,8,8});
    cout << solu.singleNonDuplicate(input) << endl;
    return 0;
}
