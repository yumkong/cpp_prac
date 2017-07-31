#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int max_int = ~(1 << 31);
        int min_int = (1 << 31);
        int len = nums.size();
        if(len == 1) return 0;
        if(len == 2) return (nums[0] > nums[1]) ? 2 : 0;
        int left_sorted_cnt = 0, right_sorted_cnt = 0;
        //int i = 0, j = len - 1 ;
        for(int i = 0; i < len - 1; ++i)
        {
            if(nums[i] <= nums[i+1]) 
            {
                ++left_sorted_cnt;
            }
            else break;
        }
        if(left_sorted_cnt == len - 1) return 0;
        for(int i = len - 1; i >= 1; --i)
        {
            if(nums[i] >= nums[i-1]) 
            {
                ++right_sorted_cnt;
            }
            else break;
        }
        // get min and max in the unsorted region
        int min_loc = max_int, max_loc = min_int;
        for(int i = left_sorted_cnt; i < len - right_sorted_cnt; ++i)
        {
            if(min_loc > nums[i]) min_loc = nums[i];
            if(max_loc < nums[i]) max_loc = nums[i];
        }
        // initial unsorted length
        int unsort_len = len - left_sorted_cnt - right_sorted_cnt;
        for(int i = left_sorted_cnt - 1; i >= 0; --i)
        {
            if(nums[i] > min_loc) ++unsort_len;
            else break;
        }
        for(int i = len - right_sorted_cnt; i < len; ++i)
        {
            if(nums[i] < max_loc) ++unsort_len;
            else break;
        }
        return unsort_len;
    }
};

int main()
{
    int a[] = {2, 6, 9, 15};
    vector<int> arr(a, a + sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.findUnsortedSubarray(arr) << endl;
    return 0;
}
