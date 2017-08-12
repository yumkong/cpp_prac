// find minimum in rotated sorted array II (related to 153)
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
            //cout << "mid = " << mid << ", left = " << left << endl;
            if(nums[mid] > nums[right]) left = mid + 1;
            else if(nums[mid] < nums[right]) right = mid;
            else --right;
            mid = (left + right) / 2;
        }
        return nums[left];
    }
};

int main()
{ 
    Solution solu;
    vector<int> input({3,4,5,6,7,1,2,3});
    cout << solu.findMin(input) << endl;
    return 0;
}
