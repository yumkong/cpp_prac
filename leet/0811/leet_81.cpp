// search a targe value from a sorted array after rotation, if found return index, otherwise return -1
// NOTE: there may be duplicated elems in the array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0 || (len == 1 && nums[0] != target)) return -1;
        int left = 0, right = len - 1, mid = len / 2;
        while(left < right)
        {
            // here not return mid directly: maybe mid is not the first elem that = target
            if(target == nums[mid]) right = mid; // return mid;
            else if(target > nums[mid])
            {
               // note here  <= instead of '<' in case that mid == right 
                if(nums[mid] < nums[right])
                {
                    if(target <= nums[right]) left = mid + 1;
                    else right = mid - 1;
                }
                else if(nums[mid] > nums[right]) left = mid + 1;
                else --right; // to remove duplicates
            }
            else
            {
                if(nums[mid] < nums[right]) right = mid - 1;
                else if(nums[mid] > nums[right]) 
                {
                    if(target >= nums[left]) right = mid - 1;
                    else left = mid + 1;
                }
                else --right; // to remove duplicates
            }
            mid = (left + right) / 2;
            //cout << "mid = " << mid << endl;
        }
//        cout << "left = " << left << ", right = " << right << endl;
        // at this time left = right = mid
        return (left >= len || nums[left] != target) ? false : true;
    }
};

int main()
{
    vector<int> input({2,3, 4,5,6,7,8,8,8,8,8,8,10, 11,0,1,2});
    Solution solu;
    cout << solu.search(input, 2) << endl;
    return 0;
}
