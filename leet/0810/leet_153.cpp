// find minimum in rotated sorted array
// assume no duplicated elements
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        if(len == 2) return min(nums[0], nums[1]);
        int left = 0, right = len - 1, mid = len / 2;
        while(left < right)
        {
            cout << "mid = " << mid << ", left = " << left << endl;
            /*
            if(nums[mid] > nums[left])
            {
                if(nums[mid] > nums[right]) left = mid + 1;
                else right = mid;
            }
            else right = mid;*/
            if(nums[mid] >= nums[left] && nums[mid] >= nums[right]) left = mid + 1;
            else right = mid;
            mid = (left + right) / 2;
        }
        return nums[left];
    }
};

int main()
{ 
    Solution solu;
    vector<int> input({3,4,5,6,7,1,2});
    cout << solu.findMin(input) << endl;
    return 0;
}
