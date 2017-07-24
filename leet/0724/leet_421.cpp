// given a non-empty array of non-negative ints, find the maximum result of XOR of any two pairs in array in **O(n)** time
#include <iostream>
#include <vector>
#include <unordered_set> // c++11
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return 0;
        if(len == 2) return nums[0] ^ nums[1];
        int max = 0, mask = 0;
        unordered_set<int> uset;
        for(int i = 30; i >= 0; --i)
        {
            // the bits considered so far
            mask |= (1 << i);
            uset.clear();
            // store prefix of all number with [i-1, ..., 0] bits discarded
            for(int n: nums) // c++11
            {
                uset.insert(mask & n);
            }
            // find out if there are two prefices with different i-th bit
            int candidate = max | (1 << i);
            for(int prefix : uset)
            {
                if(uset.find(prefix ^ candidate) != uset.end())
                {
                    // keep the max xor difference between any two pairs from highest significant bit
                    // to i-th bit
                    max = candidate;
                    break;
                }
            }
        }        
        return max;
    }
};

int main()
{
    int a[] = {3, 10, 5, 25, 2, 8};
    vector<int> arr(a, a+ sizeof(a)/sizeof(a[0]));
    Solution solu;
    cout << solu.findMaximumXOR(arr) << endl;
    return 0;
}
