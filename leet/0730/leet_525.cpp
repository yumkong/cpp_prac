// find maximum length of a contiguous subarray with equal number of 0 and 1 in a binary array
// the length of binary array not exceed 50,000
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return 0;
        int cnt0 = 0, cnt1 = 0;
        map<int, pair<int, int> > mp;
        // naturally when no element, the diff is 0
        mp[0] = {0, 0};
        for(int i = 0; i < len; ++i)
        {
            if(nums[i] == 0) ++cnt0;
            else ++cnt1;
            int diff10 = cnt1 - cnt0;
            if(mp.count(diff10) > 0) mp[diff10].second = i+1;
            else mp[diff10] = {i+1, i+1};
        }
        int res = (1<<31);
        for(auto &i : mp)
        {
            if(res < i.second.second - i.second.first) 
               res = i.second.second - i.second.first;
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({0,1});
    cout << solu.findMaxLength(input) << endl;
    return 0;
}
