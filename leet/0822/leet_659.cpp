// category: heap
// given an int array in ascending order (may have duplicates), split them into several subseqences, 
// where each subsequence consist of at least 3 consecutive ints, return whehter can make such a split
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> freq, appendfreq;
        int len = nums.size();
        for(int i = 0; i < len; ++i) ++freq[nums[i]];
        for(int i = 0; i < len; ++i)
        {
            // the number has been used
            if(freq[nums[i]] == 0) continue;
            // the number follow after a sequence
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
