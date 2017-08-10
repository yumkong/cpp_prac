// given an non-empty int array, find the 3rd maximum number, if not exist, return the maximum
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int len = nums.size();
        int min_int = (1 << 31);
        
        if(len == 1) return nums[0];
        if(len == 2) return max(nums[0], nums[1]);
        int max1 = min_int, max2 = min_int, max3 = min_int;
        int distinct_cnt = 0;// how many distict numbers totally assigned in for loop?
        int min_cnt = 0; // how many min_int appears?
        for(int i = 0; i < len; ++i)
        {
            if(nums[i] > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
                ++distinct_cnt;
            }
            else if(nums[i] < max1 && nums[i] > max2)
            {
                max3 = max2;
                max2 = nums[i];
                ++distinct_cnt;
            }
            else if(nums[i] < max2 && nums[i] > max3)
            {
                max3 = nums[i];
                ++distinct_cnt;
            }
            else if(nums[i] == min_int)
            {
                min_cnt = 1; // if min_int appears in array, cnt once
            }
        }
        return (distinct_cnt + min_cnt >= 3)? max3: max1;
    }
};

int main()
{
	int a[] = {1,2,2,3};
	vector<int> arr(a, a + sizeof(a) /sizeof(a[0]));
	Solution solu;
	cout << solu.thirdMax(arr) << endl;
	return 0;
}