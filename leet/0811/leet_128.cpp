// given an unsorted int array, find the length of the longest consecutive elements subsequence
// e.g. [100, 4, 200, 1, 3, 2] => 4: (aka. [1,2,3,4])
// NOTE: should run in O(n)
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        map<int, int> mp; // <val, how many consecutive now around this val>
        for(int i = 0; i < nums.size(); ++i)
        {
            int cur = nums[i];
            // first meet this elem
            if(mp.count(cur) == 0)
            {
                int left = (mp.count(cur - 1) > 0) ? mp[cur - 1] : 0;
                int right = (mp.count(cur + 1) > 0) ? mp[cur + 1] : 0;
           
                mp[cur] = left + right + 1;
                res = max(res, mp[cur]);
                // propagate the updated consecutive length to two borders
                mp[cur - left] = mp[cur];
                mp[cur + right] = mp[cur];
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({100,4,200,1,3,2});
    cout << solu.longestConsecutive(input) << endl;
    return 0;
}

