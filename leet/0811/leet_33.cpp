// search a targe value from a sorted array after rotation, if found return index, otherwise return -1
// ASSUME: no duplicate exists in the array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0 || (len == 1 && nums[0] != target)) return -1;
        int left = 0, right = len - 1, mid = len / 2;
        while(left < right)
        {
            if(target == nums[mid]) return mid;
            else if(target > nums[mid])
            {
               // note here  <= instead of '<' in case that mid == right 
                if(nums[mid] <= nums[right])
                {
                    if(target <= nums[right]) left = mid + 1;
                    else right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(nums[mid] <= nums[right]) right = mid - 1;
                else
                {
                    if(target >= nums[left]) right = mid - 1;
                    else left = mid + 1;
                }
            }
            mid = (left + right) / 2;
            //cout << "mid = " << mid << endl;
        }
//        cout << "left = " << left << ", right = " << right << endl;
        // at this time left = right = mid
        return (left >= len || nums[left] != target) ? (-1) : left;
    }
};

int main()
{
    vector<int> input({3,1}); //4,5,6,7,8,9,10, 11,0,1,2});
    Solution solu;
    cout << solu.search(input, 0) << endl;
    return 0;
}
