// return the index of any peak element (with values greater than its neighbors) in an array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        // the topic already assume that num[i] != num[i+1]
        if(len <= 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[len - 1] > nums[len - 2])  return len - 1;
        for(int i = 1; i < len - 1; ++i)
        {
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
        }
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,2,3,1});
    cout << solu.findPeakElement(input) << endl;
    return 0;
}
