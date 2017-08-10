// given an int array nums and an int k, find out whether there are two distinct indices i and j s.t.
// nums[i] == nums[j], and |i - j| <= k
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, vector<int> > mp; // <same val, <different indices> >
        for(int i = 0; i < len; ++i)
        {
            mp[nums[i]].push_back(i);
            int tmplen = mp[nums[i]].size();
            if(tmplen > 1 && mp[nums[i]][tmplen - 1] - mp[nums[i]][tmplen - 2] <= k) return true; 
        }
        return false;
    }
};

int main()
{
    Solution solu;
    vector<int> input({1,2,3,4,5,6,7,8,6,9}); // k = 3
    cout << solu.containsNearbyDuplicate(input, 2) << endl;
    return 0;
}
