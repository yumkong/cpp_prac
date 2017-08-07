//givne an array of n+1 ints where each int is between 1 and n. Assume there is only 1 duplicate num, find it
// not modify the array (read only)
// must use constant O(1) space
// runtime < O(n^2)
// NOTE: there is only one duplicate number in the array, but it could be repeated more than once
// in other words, some other num may be missing
// inspired by @echoxiaolee 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return 1;
        int slow = nums[0];
        //IMPORTANT!!! here must make fast and slow different!!!
        int fast = nums[nums[0]];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
           // cout << "fast = " << fast << ", slow = " << slow << endl;
        }
        fast = 0;
        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};

int main()
{
    vector<int> arr({1,2,3,4,5,6,7,8,9,8});
    Solution solu;
    cout << solu.findDuplicate(arr) << endl;
    return 0;
}
