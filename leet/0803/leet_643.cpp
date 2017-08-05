// given an array consisting of n integers, find the contiguous subarray of length k that has the
// max average value
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        if(len < k) return 0;
        int sum = 0;
        for(int i = 0; i < k; ++i) sum += nums[i];
        int maxsum = sum;
        for(int i = k; i < len; ++i) 
        {
            sum += nums[i] - nums[i-k];
            if(sum > maxsum) maxsum = sum;
        }
        return (double)maxsum / k;
    }
};

int main()
{
    vector<int> arr({1,12, -5, -6, 50, 3});
    Solution solu;
    cout << solu.findMaxAverage(arr, 4) << endl;
    return 0;
}
