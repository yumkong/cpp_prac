// non-decreasing array
// given an array with n ints, check it it could become non-decreasing by modifying at most 1 element
// n is [1, 10000]
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return true;
        int cnt = 0;   //the number of changes
        for(int i = 1; i < nums.size() && cnt<=1 ; i++)
        {
            if(nums[i-1] > nums[i])
            {
                cnt++;
                //modify nums[i-1] of a priority
                if(i - 2 < 0 || nums[i-2] <= nums[i]) nums[i-1] = nums[i];
                else nums[i] = nums[i-1]; //have to modify nums[i]
            }
        }
        return cnt <= 1;
    }
};

int main()
{
    Solution solu;
    vector<int> input({2,3,3,2,4});
    cout << solu.checkPossibility(input) << endl;
    return 0;
}
