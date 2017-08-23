// category: heap
// given an int array in ascending order (may have duplicates), split them into several subseqences, 
// where each subsequence consist of at least 3 consecutive ints, return whether we can make such a split
// 0822: need to read more !!!
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> freq, appendfreq;
        int len = nums.size();
        // count the number of each elements
        for(int i = 0; i < len; ++i) ++freq[nums[i]];
        for(int i = 0; i < len; ++i)
        {
            // the number has been used (by previous sequence)
            if(freq[nums[i]] == 0) continue;
            // the number follow after a sequence
            // NOTE: map.count(elem) && mp[elem] ... is a standard c++ usage of map
            else if(appendfreq.count(nums[i]) > 0 && appendfreq[nums[i]] > 0)
            {
                --appendfreq[nums[i]];
                ++appendfreq[nums[i] + 1];
            } // the number launch a new sequence
            else if(freq.count(nums[i] + 1) > 0 && freq[nums[i] + 1] > 0 
                  && freq.count(nums[i] + 2) > 0 && freq[nums[i] + 2] > 0)
            {
                --freq[nums[i] + 1];
                --freq[nums[i] + 2];
                ++appendfreq[nums[i] + 3];
            } 
            else return false;
            // the current number has been used, so freq minus 1
            --freq[nums[i]];
        }
        return true;
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,2,3,4,4,5});
    cout << solu.isPossible(input) << endl;
    return 0;
}
