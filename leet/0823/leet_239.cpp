// sliding window maximum
// given an array, and a sliding window of size k which move from the very left to the very right
// return the max val of each position
// NOTE: k is always valid, can you solve it in linear time?
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res;
        if(len <= 0 || k <= 0) return res;
        res.assign(len - k + 1, 0);
        int idx = 0;
        //0823: save the max val's index of a window
        deque<int> dq;
        for(int i = 0; i < len; ++i)
        {
            // remove numbers out of range k
            while(!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            // remove smaller numbers in k range as they are useless
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            // q contain idx, res contain content
            dq.push_back(i);
			// return values from k to len
            if(i >= k - 1) res[idx++] = nums[dq.front()];
        }
        return res;
    }
};

int main()
{
    Solution solu;
    vector<int> input({1, 3, -1, -3, 5, 3, 6, 7});
    vector<int> res = solu.maxSlidingWindow(input, 3);
    for(auto &i: res) cout << i << " ";
    cout << endl;
    return 0;
}
