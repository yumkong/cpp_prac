// search for a range: given an int array sorted in ascending order. find the starting and ending
// position of a targe value
// NOTE: run time must be O(log n). If the target is not found, return [-1, -1]
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res({-1, -1});
        int len = nums.size();
        if(len <= 0 || (len == 1 && target != nums[0])) return res;
        if(len == 1 && target == nums[0]) {res[0] = 0; res[1] = 0; return res; }
        // use recursion
        helper(nums, 0, len - 1, target, res);
        return res;
    }
    void helper(vector<int>& nums, int left, int right, int target, vector<int>& res)
    {
        if(left > right) return; // no answer
        if(left == right) 
        {
            if(nums[left] == target) 
            {
                if(res[0] >= 0) res[0] = min(left, res[0]);
                else res[0] = left;
                res[1] = max(left, res[1]);
            }
        }
        int mid = (left + right) / 2;
        //cout << "mid = " << mid << endl;
        if(left < right)
        {
            if(nums[mid] < target) helper(nums, mid + 1, right, target, res);
            else if(nums[mid] > target) helper(nums, left, mid - 1, target, res);
            else // nums[mid] == target
            {
                if(mid > left && nums[mid - 1] == target) helper(nums, left, mid, target, res);
                else
                { 
                    if(res[0] < 0) res[0] = mid;
                    else res[0] = min(res[0], mid);
                }
                if(mid + 1 < right && nums[mid + 1] == target) helper(nums, mid + 1, right, target, res);
                else res[1] = (nums[mid + 1] == target) ? (mid + 1) : mid;
            }
        }
    }
};

int main()
{
    //vector<int> input({5, 7, 7, 8, 8, 10});
    //vector<int> input({1,4});
    vector<int> input({1,2,3,3,3,3,4,5,9});
    Solution solu;
    vector<int> res = solu.searchRange(input, 3);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;
    return 0;
}
