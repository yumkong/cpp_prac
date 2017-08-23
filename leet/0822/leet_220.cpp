// Category: BST
// given an int array, find out whether there are two indices i and j: 
// i != j
// abs(nums[i] - nums[j]) <= t
// abs(i - j) <= k
#include <vector>
#include <iostream>
#include <cmath>
#include <climits> // INT_MIN
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k <= 0 || t < 0) return false;
        map<long, long> mp;
        int len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            long remappedNum = (long)nums[i] - INT_MIN;
            long bucket = remappedNum / ((long)t + 1);
            // all elements that satisfies: abs(nums[i] - nums[j]) <= t, are in [bucket], [bucket-1] or [bucket+1]
            if( mp.count(bucket) > 0
               || (mp.count(bucket - 1) > 0 && remappedNum - mp[bucket - 1] <= t)
               || (mp.count(bucket + 1) > 0 && mp[bucket + 1] - remappedNum <= t) )
            {return true; }
            // here is an assumption that the k elements are distinct
            // if not, will not come here (return true in the above step)
            if(mp.size() >= k)
            {
                long lastBucket = ((long)nums[i - k] - INT_MIN) / ((long)t + 1);
                mp.erase(lastBucket);
            }
            mp[bucket] = remappedNum;
        }
        return false;
    }
};

int main()
{
	vector<int> input({4,2});
	Solution solu;
	cout << solu.containsNearbyAlmostDuplicate(input, 2, 1) << endl;
	//cout << solu.containsNearbyAlmostDuplicate(input, 2, 10) << endl;
	return 0;
}
