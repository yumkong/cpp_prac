// given an array containing n distinct numbers from 0,1,2,..., n, find the one that is missing from it
// NOTE: should run in O(n), try best to use only O(1) space
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        for(int i = 0; i < len; ++i)
        {
            res = res ^ i ^ nums[i];
        }
        // not forget the last index [len]
        return res ^ len;
    }
};

int main()
{
    Solution solu;
    vector<int> arr({0,1,3});
    cout << solu.missingNumber(arr) << endl;
    return 0;
}
